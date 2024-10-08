<?xml version="1.0" encoding="UTF-8"?>
<<<<<<< HEAD
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <head>
                <title>F1 Driver Statistics</title>
                <style>
                    table {
                        border-collapse: collapse;
                        width: 100%;
                        max-width: 1000px;
                        margin: 0 auto;
                    }
                    th, td {
                        border: 1px solid #ddd;
                        padding: 8px;
                        text-align: left;
                    }
                    th {
                        background-color: #f2f2f2;
                        font-weight: bold;
                    }
                    tr:nth-child(even) {
                        background-color: #f9f9f9;
                    }
                    h1 {
                        text-align: center;
                    }
                </style>
            </head>
            <body>
                <h1>F1 Driver Statistics</h1>
                <table>
                    <thead>
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
                    </thead>
                    <tbody>
                        <xsl:for-each select="drivers/driver">
                            <tr>
                                <td><xsl:value-of select="name"/></td>
                                <td><xsl:value-of select="team"/></td>
                                <td><xsl:value-of select="nationality"/></td>
                                <td><xsl:value-of select="championships"/></td>
                                <td><xsl:value-of select="race_wins"/></td>
                                <td><xsl:value-of select="podiums"/></td>
                                <td><xsl:value-of select="fastest_laps"/></td>
                                <td><xsl:value-of select="pole_positions"/></td>
                            </tr>
                        </xsl:for-each>
                    </tbody>
                </table>
            </body>
        </html>
    </xsl:template>
=======
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  
  <xsl:template match="/">
    <html>
      <head>
        <title>F1 Driver Stats</title>
        <style>
          table {
            width: 100%;
            border-collapse: collapse;
            margin: 20px 0;
          }
          th, td {
            border: 1px solid #ddd;
            padding: 8px;
            text-align: left;
          }
          th {
            background-color: #4CAF50;
            color: white;
          }
          tr:nth-child(even) {
            background-color: #f2f2f2;
          }
          tr:hover {
            background-color: #ddd;
          }
        </style>
      </head>
      <body>
        <h1>F1 Driver Stats</h1>
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
          <xsl:for-each select="f1_stats/driver">
            <tr>
              <td><xsl:value-of select="name"/></td>
              <td><xsl:value-of select="team"/></td>
              <td><xsl:value-of select="nationality"/></td>
              <td><xsl:value-of select="championships"/></td>
              <td><xsl:value-of select="race_wins"/></td>
              <td><xsl:value-of select="podiums"/></td>
              <td><xsl:value-of select="fastest_laps"/></td>
              <td><xsl:value-of select="pole_positions"/></td>
            </tr>
          </xsl:for-each>
        </table>
      </body>
    </html>
  </xsl:template>

>>>>>>> 338abb4e8923fb5159ee574010f04c5f0993ec8c
</xsl:stylesheet>
