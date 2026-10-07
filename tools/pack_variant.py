#!/usr/bin/env python3
"""Build a fixed-size variant_data block from one JSON manifest."""

from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path
from typing import Any


DEFAULT_SLOT_SIZE = 64
DEFAULT_REGION_SIZE = 4096


def parse_integer(value: Any, field_name: str) -> int:
    if isinstance(value, int):
        return value
    if isinstance(value, str):
        try:
            return int(value, 0)
        except ValueError as error:
            raise ValueError(f"{field_name} must be an integer or 0x-prefixed integer") from error
    raise ValueError(f"{field_name} must be an integer or 0x-prefixed integer")


def encode_item(item: dict[str, Any]) -> bytes:
    encoding = item.get("encoding")
    value = item.get("value")

    if not isinstance(value, str):
        raise ValueError(f"item {item.get('name', '<unnamed>')} value must be a string")
    if encoding == "ascii":
        try:
            return value.encode("ascii")
        except UnicodeEncodeError as error:
            raise ValueError(f"item {item.get('name', '<unnamed>')} is not ASCII") from error
    if encoding == "utf8":
        return value.encode("utf-8")
    if encoding == "hex":
        try:
            return bytes.fromhex(value)
        except ValueError as error:
            raise ValueError(f"item {item.get('name', '<unnamed>')} has invalid hex data") from error
    raise ValueError(f"item {item.get('name', '<unnamed>')} encoding must be ascii, utf8, or hex")


def build_variant_block(manifest: dict[str, Any]) -> bytes:
    slot_size = parse_integer(manifest.get("slot_size", DEFAULT_SLOT_SIZE), "slot_size")
    region_size = parse_integer(manifest.get("region_size", DEFAULT_REGION_SIZE), "region_size")
    items = manifest.get("items")

    if slot_size <= 1:
        raise ValueError("slot_size must be greater than 1")
    if region_size <= 0 or region_size % slot_size != 0:
        raise ValueError("region_size must be a positive multiple of slot_size")
    if not isinstance(items, list):
        raise ValueError("items must be an array")

    slot_count = region_size // slot_size
    used_slots: set[int] = set()
    block = bytearray(region_size)

    for item in items:
        if not isinstance(item, dict):
            raise ValueError("every item must be an object")
        name = item.get("name")
        if not isinstance(name, str) or not name:
            raise ValueError("every item must have a non-empty name")

        slot = parse_integer(item.get("slot"), f"item {name} slot")
        if slot < 0 or slot >= slot_count:
            raise ValueError(f"item {name} slot {slot} is outside 0..{slot_count - 1}")
        if slot in used_slots:
            raise ValueError(f"slot {slot} is assigned more than once")

        payload = encode_item(item)
        if len(payload) > slot_size - 1:
            raise ValueError(
                f"item {name} contains {len(payload)} bytes; slot payload limit is {slot_size - 1}"
            )

        offset = slot * slot_size
        block[offset] = len(payload)
        block[offset + 1 : offset + 1 + len(payload)] = payload
        used_slots.add(slot)

    return bytes(block)


def load_manifest(path: Path) -> dict[str, Any]:
    try:
        manifest = json.loads(path.read_text(encoding="utf-8"))
    except json.JSONDecodeError as error:
        raise ValueError(f"invalid JSON: {error}") from error
    if not isinstance(manifest, dict):
        raise ValueError("manifest root must be an object")
    if not isinstance(manifest.get("variant"), str) or not manifest["variant"]:
        raise ValueError("variant must be a non-empty string")
    return manifest


def write_file(path: Path, content: bytes) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(content)


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Build a 4 KiB variant_data block and optionally merge it into a base binary."
    )
    parser.add_argument("manifest", type=Path, help="one-variant JSON manifest")
    parser.add_argument("--variant-bin", type=Path, required=True, help="output variant_data binary")
    parser.add_argument("--base-bin", type=Path, help="base binary to merge into")
    parser.add_argument("--merged-bin", type=Path, help="merged binary output")
    parser.add_argument(
        "--variant-offset",
        help="variant_data byte offset in base binary; overrides merge_offset in the manifest",
    )
    args = parser.parse_args()

    if (args.base_bin is None) != (args.merged_bin is None):
        parser.error("--base-bin and --merged-bin must be used together")

    try:
        manifest = load_manifest(args.manifest)
        block = build_variant_block(manifest)
        write_file(args.variant_bin, block)

        if args.base_bin is not None:
            offset_value = args.variant_offset if args.variant_offset is not None else manifest.get("merge_offset")
            if offset_value is None:
                raise ValueError("merge_offset is required in the manifest or as --variant-offset")
            offset = parse_integer(offset_value, "merge_offset")
            if offset < 0:
                raise ValueError("merge_offset must not be negative")

            base = bytearray(args.base_bin.read_bytes())
            end = offset + len(block)
            if end > len(base):
                raise ValueError(
                    f"variant_data range 0x{offset:X}..0x{end - 1:X} exceeds base binary size 0x{len(base):X}"
                )
            base[offset:end] = block
            write_file(args.merged_bin, bytes(base))
    except (OSError, ValueError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1

    print(f"built {manifest['variant']}: {args.variant_bin} ({len(block)} bytes)")
    if args.merged_bin is not None:
        print(f"merged: {args.merged_bin}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
