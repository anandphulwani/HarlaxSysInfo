[measureMotherboardname]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic baseboard get product
OutputType=ANSI
RegExpSubstitute=1
Substitute="Product.*#CRLF#":"","(#CRLF#+)":"#CRLF#","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","":"[\9]"
UpdateDivider=-1

[measureMoboTempValue]
Measure=String
String=#temperatureAndFanData#
RegExpSubstitute=1
Substitute="(.*),(.*),(.*),(.*),(.*),(.*)":"\2","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","":"N/A"
UpdateDivider=-1
DynamicVariables=1

[measureOtherFanValue]
Measure=String
String=#temperatureAndFanData#
RegExpSubstitute=1
Substitute="(.*),(.*),(.*),(.*),(.*),(.*)":"\6","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","":"N/A"
UpdateDivider=-1
DynamicVariables=1

[measureGPUName]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic path win32_VideoController get name
OutputType=ANSI
RegExpSubstitute=1
Substitute="Name.*#CRLF#":"","Radeon":"AMD Radeon","NVIDIA GeForce":"NVIDIA GeForce","Radmin.*":"","(#CRLF#+)":"#CRLF#","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","":"[\9]"
UpdateDivider=-1

[measureGPUTempValue]
Measure=String
String=#temperatureAndFanData#
RegExpSubstitute=1
Substitute="(.*),(.*),(.*),(.*),(.*),(.*)":"\3","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","":"N/A"
UpdateDivider=-1
DynamicVariables=1

[measureHDDModelsAndTempValue]
Measure=String
String=#temperatureAndFanData#
RegExpSubstitute=1
Substitute="(.*),(.*),(.*),(.*),(.*),(.*)":"\4"," ; ":"[\13][\10]","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","":"N/A"
IfMatch=^N\/A$
IfMatchAction=[!SetOption meterHDDModelsTemperatureValue X 4R][!SetOption meterHDDModelsTemperatureValue Y 0r][!SetOption meterHDDModelsTemperatureValue W 100][!UpdateMeter meterHDDModelsTemperatureValue][!Redraw]
IfNotMatchAction=[!SetOption meterHDDModelsTemperatureValue X ((#widthtoggle#-8)+22)][!SetOption meterHDDModelsTemperatureValue Y 0R][!SetOption meterHDDModelsTemperatureValue W 180][!UpdateMeter meterHDDModelsTemperatureValue][!Redraw]
UpdateDivider=-1
DynamicVariables=1