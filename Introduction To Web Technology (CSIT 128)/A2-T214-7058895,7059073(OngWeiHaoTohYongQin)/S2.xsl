<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns="http://www.w3.org/1999/xhtml">
	<xsl:output method="xml" indent="yes" encoding="UTF-8"/>
		<xsl:template match="/forecast">
			<html>
				<head>
					<style>
						th{
							background-color:orange;
							width:100px;
						}
					</style>
				</head>
				<body>
					<h1> <xsl:value-of select="@queryLocation"/>  [<xsl:value-of select="@queryTime"/>]</h1>
					<table border = "1"  style="align:center; ">
					<tr>
						<th style="background-color:orange; width:70px"> 
						Date
						</th>
						<th>
						Mon
						</th>
						<th> 
						Tue
						</th >
						<th> 
						Wed
						</th>
						<th> 
						Thur
						</th>
						<th> 
						Fri
						</th>
						<th> 
						Sat
						</th>
						<th> 
						Sun
						</th>		
					</tr>
					<xsl:for-each select="weather">
						<xsl:sort select="date"/>
						<tr style="text-align:center">
						<td style="height:120px; text-align:center; background-color:orange">
							<xsl:value-of select="date"/> 
							<xsl:choose>
								<xsl:when test="month='1'">
									<xsl:text> Jan </xsl:text>
								</xsl:when>
								<xsl:when test="month='2'">
									<xsl:text> Feb </xsl:text>
								</xsl:when>
								<xsl:when test="month='3'">
									<xsl:text> Mar </xsl:text>
								</xsl:when>
								<xsl:when test="month='4'">
									<xsl:text> Apr </xsl:text>
								</xsl:when>
								<xsl:when test="month='5'">
									<xsl:text> May </xsl:text>
								</xsl:when>
								<xsl:when test="month='6'">
									<xsl:text> Jun </xsl:text>
								</xsl:when>
								<xsl:when test="month='7'">
									<xsl:text> Jul </xsl:text>
								</xsl:when>
								<xsl:when test="month='8'">
									<xsl:text> Aug </xsl:text>
								</xsl:when>
								<xsl:when test="month='9'">
									<xsl:text> Sep </xsl:text>
								</xsl:when>
								<xsl:when test="month='10'">
									<xsl:text> Oct </xsl:text>
								</xsl:when>
								<xsl:when test="month='11'">
									<xsl:text> Nob </xsl:text>
								</xsl:when>
								<xsl:when test="month='12'">
									<xsl:text> Dec </xsl:text>
								</xsl:when>
							</xsl:choose>
						</td>
						<td>
							<xsl:choose>
								<xsl:when test="date='12' and dayOfWeek='Mon'">
									<xsl:value-of select="lowest"/>°						
									<xsl:text> - </xsl:text>
									<xsl:value-of select="highest"/>°
										<img>
										<xsl:attribute name="src">
										<xsl:value-of select="overallCode"/>
										<xsl:text>.png</xsl:text>
										</xsl:attribute>
										<xsl:attribute name="width">
										<xsl:text>60px</xsl:text>
										</xsl:attribute>
										</img>
										<p style="font-size:15px; color:blue">
									<xsl:value-of select="overall"/>
									</p>
								</xsl:when>
							</xsl:choose>
						</td>
						<td>
						</td>
						<td>
						</td>
						<td>
							<xsl:choose>
								<xsl:when test="date='08' and dayOfWeek='Thu'">
									<xsl:value-of select="lowest"/>°						
									<xsl:text> - </xsl:text>
									<xsl:value-of select="highest"/>°
										<img>
										<xsl:attribute name="src">
										<xsl:value-of select="overallCode"/>
										<xsl:text>.png</xsl:text>
										</xsl:attribute>
										<xsl:attribute name="width">
										<xsl:text>60px</xsl:text>
										</xsl:attribute>
										</img>
										<p style="font-size:15px; color:red">
									<xsl:value-of select="overall"/>
									</p>
								</xsl:when>
							</xsl:choose>
						</td>
						<td>
							<xsl:choose>
								<xsl:when test="date='09' and dayOfWeek='Fri'">
									<xsl:value-of select="lowest"/>°						
									<xsl:text> - </xsl:text>
									<xsl:value-of select="highest"/>°
										<img>
										<xsl:attribute name="src">
										<xsl:value-of select="overallCode"/>
										<xsl:text>.png</xsl:text>
										</xsl:attribute>
										<xsl:attribute name="width">
										<xsl:text>60px</xsl:text>
										</xsl:attribute>
										</img>
										<p style="font-size:15px; color:blue">
									<xsl:value-of select="overall"/>
									</p>
								</xsl:when>
							</xsl:choose>
						</td>
						<td>
							<xsl:choose>
								<xsl:when test="date='10' and dayOfWeek='Sat'">
									<xsl:value-of select="lowest"/>°						
									<xsl:text> - </xsl:text>
									<xsl:value-of select="highest"/>°
										<img>
										<xsl:attribute name="src">
										<xsl:value-of select="overallCode"/>
										<xsl:text>.png</xsl:text>
										</xsl:attribute>
										<xsl:attribute name="width">
										<xsl:text>60px</xsl:text>
										</xsl:attribute>
										</img>
										
										<p style="font-size:15px; color:red">
									<xsl:value-of select="overall"/>
									</p>
								</xsl:when>
							</xsl:choose>
						</td>
						<td>
							<xsl:choose>
								<xsl:when test="date='11' and dayOfWeek='Sun'">
									<xsl:value-of select="lowest"/>°						
									<xsl:text> - </xsl:text>
									<xsl:value-of select="highest"/>°
										<img style="width:50%">
										<xsl:attribute name="src">
										<xsl:value-of select="overallCode"/>
										<xsl:text>.png</xsl:text>
										</xsl:attribute>
										<xsl:attribute name="width">
										<xsl:text>60px</xsl:text>
										</xsl:attribute>
										</img>
										<p style="font-size:15px; color:green">
									<xsl:value-of select="overall"/>
										</p>
								</xsl:when>
							</xsl:choose>
						</td>
						</tr>
					</xsl:for-each>
				</table>
				</body>
			</html>
		</xsl:template>
</xsl:stylesheet>