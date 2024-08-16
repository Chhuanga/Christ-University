<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" 
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:f1="http://example.com/f1_stats">
  <xsl:output method="html" indent="yes"/>

  <xsl:template match="/">
    <html>
      <head>
        <title>F1 Driver Statistics</title>
        <style>
          table {
            border-collapse: collapse;
            width: 100%;
          }
          th, td {
            border: 1px solid black;
            padding: 8px;
            text-align: left;
          }
          th {
            background-color: #f2f2f2;
          }
        </style>
      </head>
      <body>
        <h1>F1 Driver Statistics</h1>
        <table>
          <tr>
            <th>Name</th>
            <th>Team</th>
            <th>Nationality</th>
            <th>Championships</th>
            <th>Race Wins</th>
            <th>Podiums</th>
            <th>Fastest Laps</th>
            <th>Pole Positions</th>
          </tr>
          <xsl:apply-templates select="f1:f1_stats/f1:driver"/>
        </table>
      </body>
    </html>
  </xsl:template>

  <xsl:template match="f1:driver">
    <tr>
      <td><xsl:value-of select="f1:name"/></td>
      <td><xsl:value-of select="f1:team"/></td>
      <td><xsl:value-of select="f1:nationality"/></td>
      <td><xsl:value-of select="f1:championships"/></td>
      <td><xsl:value-of select="f1:race_wins"/></td>
      <td><xsl:value-of select="f1:podiums"/></td>
      <td><xsl:value-of select="f1:fastest_laps"/></td>
      <td><xsl:value-of select="f1:pole_positions"/></td>
    </tr>
  </xsl:template>
</xsl:stylesheet>