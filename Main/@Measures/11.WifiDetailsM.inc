[measureWIFISSID]
Measure=Plugin
Plugin=Plugins\WiFiStatus
WiFiInfoType=SSID
WiFiIntfID=0
RegExpSubstitute=1
Substitute="^(0|-1)$":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","(#CRLF#+)":"#CRLF#","":"N/A"
UpdateDivider=30

[measureWIFIQuality]
Measure=Plugin
Plugin=Plugins\WiFiStatus
WiFiInfoType=Quality
WiFiIntfID=0
RegExpSubstitute=1
Substitute="^(0|-1)$":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","(#CRLF#+)":"#CRLF#","":"N/A"
UpdateDivider=30

[measureWIFIEncryption]
Measure=Plugin
Plugin=Plugins\WiFiStatus
WiFiInfoType=Encryption
WiFiIntfID=0
RegExpSubstitute=1
Substitute="^(0|-1)$":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","(#CRLF#+)":"#CRLF#","":"N/A"
UpdateDivider=30

[measureWIFIAuth]
Measure=Plugin
Plugin=Plugins\WiFiStatus
WiFiInfoType=AUTH
WiFiIntfID=0
RegExpSubstitute=1
Substitute="^(0|-1)$":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","(#CRLF#+)":"#CRLF#","":"N/A"
UpdateDivider=30

[measureWIFIPhy]
Measure=Plugin
Plugin=Plugins\WiFiStatus
WiFiInfoType=PHY
WiFiIntfID=0
RegExpSubstitute=1
Substitute="^(0|-1)$":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","(#CRLF#+)":"#CRLF#","":"N/A"
UpdateDivider=30

[measureWIFINetworksCalculator]
Measure=Plugin
Plugin=Plugins\WiFiStatus
WiFiInfoType=LIST
WiFiIntfID=0
WiFiListStyle=3
RegExpSubstitute=1
Substitute="^(0|-1)$":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","(#CRLF#+)":"#CRLF#","(.+)":"� \1","":"N/A"
UpdateDivider=30
DynamicVariables=1

[measureWIFINetworks]
Measure=String
String=[measureWIFINetworksCalculator]
IfMatch=^N\/A$
IfMatchAction=[!SetOption meterWIFINetworksValue X 4R][!SetOption meterWIFINetworksValue Y 0r][!SetOption meterWIFINetworksValue W 166][!UpdateMeter meterWIFINetworksValue][!Redraw]
IfNotMatchAction=[!SetOption meterWIFINetworksValue X ((#widthtoggle#+247)+28)][!SetOption meterWIFINetworksValue Y 0R][!SetOption meterWIFINetworksValue W 186][!UpdateMeter meterWIFINetworksValue][!Redraw]
UpdateDivider=30
DynamicVariables=1