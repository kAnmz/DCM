# Variant data packaging

`pack_variant.py` converts one JSON manifest into the fixed 4 KiB
`.variant_data` block. It can also overwrite that block in a base binary.

## Manifest

Each manifest represents exactly one variant. Each item owns one 64-byte slot:

- byte `0`: payload length;
- bytes `1..63`: payload;
- omitted slots remain zero-filled.

`slot` is the only placement setting. Adding, removing, or moving a data item
requires changing only the JSON manifest; the script has no field-to-slot map.

Use `ascii`, `utf8`, or `hex` as the item encoding. A payload is limited to 63
bytes. Use separate slots for longer data, with the consumer code defining how
they are joined.

`merge_offset` is the byte offset of `.variant_data` relative to the beginning
of the base `.bin`, not a CPU address. Confirm it from the binary export step
before using it. The example value is intentionally a placeholder.

## Commands

Generate only the 4 KiB data block:

```powershell
python tools/pack_variant.py tools/variant_manifest.example.json --variant-bin out/variant_dcu_fl.bin
```

Generate the block and merge it into a base binary:

```powershell
python tools/pack_variant.py tools/variant_manifest.example.json --variant-bin out/variant_dcu_fl.bin --base-bin out/base.bin --merged-bin out/blf_dcu_fl.bin
```

Use `--variant-offset 0x...` to override `merge_offset` from the manifest.
