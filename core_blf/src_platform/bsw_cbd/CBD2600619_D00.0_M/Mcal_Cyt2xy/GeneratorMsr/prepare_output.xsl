<?xml version="1.0" encoding="iso-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:output indent="yes"/>
	<!--
	-->
	<xsl:variable name="PluginName" select="'TS_T00D0M0I0R0'"/>
	<!--
	-->
	<!-- ##### Template to remove all MICROSAR components for Tresos Generation ##### -->
	<xsl:template match="*[(local-name()='MODULE-CONFIGURATION' or local-name()='ECUC-MODULE-CONFIGURATION-VALUES') and 
							./*[local-name()='DEFINITION-REF' and contains(text(),'/MICROSAR/')] and 
							./*[local-name()='DEFINITION-REF' and not (contains(text(),'/EcuM'))] and 
							./*[local-name()='DEFINITION-REF' and not (contains(text(),'/Dem')) and not (contains(text(),'/Os'))]]"/>
	<xsl:template match="*[(local-name()='MODULE-CONFIGURATION' or local-name()='ECUC-MODULE-CONFIGURATION-VALUES') and 
							./*[local-name()='DEFINITION-REF' and contains(text(),'/AUTOSAR/')] and 
							./*[local-name()='DEFINITION-REF' and not (contains(text(),'/EcuM'))] and 
							./*[local-name()='DEFINITION-REF' and not (contains(text(),'/Dem')) and not (contains(text(),'/Os'))]]"/>
	<!-- ##### Template to remove all MODULE-CONFIGURATIONs except the Mcal relevant ##### -->
	<xsl:template match="*[(local-name()='MODULE-CONFIGURATION' or local-name()='ECUC-MODULE-CONFIGURATION-VALUES') and 
							./*[local-name()='DEFINITION-REF' and 
								not(contains(text(),'/TS_T40D13M1I0R0/Adc')) and 
								not(substring-after(text(), substring-before(text(), '/Dem'))='/Dem') and
								not(contains(text(),'/TS_T40D13M1I0R0/Dio')) and 
								not(substring-after(text(), substring-before(text(), '/EcuM'))='/EcuM') and
								not(substring-after(text(), substring-before(text(), '/Os'))='/Os') and
								not(contains(text(),'/TS_T40D13M1I0R0/Fls')) and 
								not(contains(text(),'/TS_T40D13M1I0R0/Gpt')) and 
								not(contains(text(),'/TS_T40D13M1I0R0/Icu')) and 
								not(contains(text(),'/TS_T40D13M1I0R0/Mcu')) and 
								not(contains(text(),'/TS_T40D13M1I0R0/Ocu')) and 
								not(contains(text(),'/TS_T40D13M1I0R0/Port')) and 
								not(contains(text(),'/TS_T40D13M1I0R0/Pwm')) and 
								not(contains(text(),'/TS_T40D13M1I0R0/Spi')) and 
								not(contains(text(),'/TS_T40D13M1I0R0/Wdg')) and 
								not(contains(text(),'/TS_T40D13M1I0R0/Resource'))]]"/>
	<!-- ##### MODULE-REFS will not be removed but are ignored by Tresos ##### -->
	<!--<xsl:template match="*[local-name()='MODULE-REFS' and *[local-name()='MODULE-REF' and contains(text(),'/MICROSAR/')]]"/>-->
	<!--
	-->
	<!-- ##### Template to copy all other nodes (with attributes) ##### -->
	<xsl:template match="*" priority="0" name="copy_cat">
		<xsl:copy>
			<xsl:for-each select="@*">
				<xsl:attribute name="{local-name(.)}"><xsl:value-of select="."/></xsl:attribute>
			</xsl:for-each>
			<xsl:apply-templates/>
		</xsl:copy>
	</xsl:template>
	<!--
	-->
	<!--Delete MATCHING-CRITERION-REF (PostBuild-Feature not supported by Tresos) if it exists -->
	<xsl:template match="//*[local-name() = 'MATCHING-CRITERION-REF']" priority="1">
	</xsl:template>
	<xsl:template match="@* | node()">
		<xsl:copy>
			<xsl:apply-templates select="@* | node()"/>
		</xsl:copy>
	</xsl:template>
	<!--
	-->
	<!--Delete VARIATION-POINT (PostBuild-Feature not supported by Tresos) if it exists -->
	<xsl:template match="//*[local-name() = 'VARIATION-POINT']" priority="1">
	</xsl:template>
	<xsl:template match="@* | node()">
		<xsl:copy>
			<xsl:apply-templates select="@* | node()"/>
		</xsl:copy>
	</xsl:template>
	<!--
	-->
	<!-- ##### Template to modify IMPLEMENTATION-CONFIG-CLASS (Tresos only knows VARIANT-POST-BUILD)  ##### -->
	<xsl:template match="*[local-name()='IMPLEMENTATION-CONFIG-VARIANT' and .='VARIANT-POST-BUILD-LOADABLE']" priority="1">
		<xsl:copy>
			<xsl:for-each select="@*">
				<xsl:attribute name="{local-name(.)}"><xsl:value-of select="."/></xsl:attribute>
			</xsl:for-each>
			<xsl:text>VARIANT-POST-BUILD</xsl:text>
		</xsl:copy>
	</xsl:template>
	<!--
	-->
	<!-- ########## The few following lines are necessary to adapt the MICROSAR Dem to vendor's Dem-Stub ########## -->
	<!-- ##### 'Rename MICROSAR-Dem to /$PluginName$/Dem ##### -->
	<xsl:template match="*[local-name()='DEFINITION-REF' and contains(., '/Dem')]" priority="1">
		<xsl:copy>
			<xsl:for-each select="@*">
				<xsl:attribute name="{local-name(.)}"><xsl:value-of select="."/></xsl:attribute>
			</xsl:for-each>
			<xsl:text>/</xsl:text>
			<xsl:value-of select="$PluginName"/>
			<xsl:text>/Dem</xsl:text>
			<xsl:value-of select="substring-after(., '/Dem')"/>
		</xsl:copy>
	</xsl:template>
	<!--
	-->
	<!-- ########## The few following lines are necessary to adapt the MICROSAR EcuM to vendor's EcuM-Stub ########## -->
	<!-- ##### 'Rename MICROSAR-EcuM to /$PluginName$/EcuM ##### -->
	<xsl:template match="*[local-name()='DEFINITION-REF' and contains(., '/EcuM')]" priority="1">
		<xsl:copy>
			<xsl:for-each select="@*">
				<xsl:attribute name="{local-name(.)}"><xsl:value-of select="."/></xsl:attribute>
			</xsl:for-each>
			<xsl:text>/</xsl:text>
			<xsl:value-of select="$PluginName"/>
			<xsl:text>/EcuM</xsl:text>
			<xsl:value-of select="substring-after(., '/EcuM')"/>
		</xsl:copy>
	</xsl:template>
	<!-- ########## The few following lines are necessary to adapt the MICROSAR Os to vendor's Os-Stub ########## -->
	<!-- ##### 'Rename MICROSAR-Os to /$PluginName$/Os ##### -->
	<xsl:template match="*[local-name()='DEFINITION-REF' and contains(., '/Os')]" priority="1">
		<xsl:copy>
			<xsl:for-each select="@*">
				<xsl:attribute name="{local-name(.)}"><xsl:value-of select="."/></xsl:attribute>
			</xsl:for-each>
			<xsl:text>/</xsl:text>
			<xsl:value-of select="$PluginName"/>
			<xsl:text>/Os</xsl:text>
			<xsl:value-of select="substring-after(., '/Os')"/>
		</xsl:copy>
	</xsl:template>
	<!--
	-->
</xsl:stylesheet>
