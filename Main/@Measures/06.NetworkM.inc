[measureFetchIPDetailsData]
Measure=Plugin
Plugin=RunCommand
Parameter=#ROOTCONFIGPATH#/PythonEXEs/getIPDetailsData.exe
State=Hide
OutputType=UTF8
FinishAction=[!SetVariable "IPDetailsData" "[measureFetchIPDetailsData]"][!UpdateMeasure "measureIPValues"][!UpdateMeasure "measureSubnetMaskValues"][!UpdateMeasure "measureDefaultGatewayValues"][!UpdateMeasure "measureDNSServerValues"][!UpdateMeasure "measureMACAddressValues"][!UpdateMeasure "measureNetworkCardNameValues"][!UpdateMeasure "measureNetworkCardTypeValues"][!UpdateMeasure "measureNetworkCardSpeedValues"]
UpdateDivider=-1
DynamicVariables=1

[measureIPValues]
Measure=String
String=#IPDetailsData#
RegExpSubstitute=1
Substitute="(?s).*IP Addresses:(.*?\n).*":"\1","(#CRLF#+)":"",",":"[\13][\10]","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1
DynamicVariables=1

[measureSubnetMaskValues]
Measure=String
String=#IPDetailsData#
RegExpSubstitute=1
Substitute="(?s).*Subnet Masks:(.*?\n).*":"\1","(#CRLF#+)":"",",":"[\13][\10]","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1
DynamicVariables=1

[measureDefaultGatewayValues]
Measure=String
String=#IPDetailsData#
RegExpSubstitute=1
Substitute="(?s).*Default Gateways:(.*?\n).*":"\1","(#CRLF#+)":"",",":"[\13][\10]","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1
DynamicVariables=1

[measureDNSServerValues]
Measure=String
String=#IPDetailsData#
RegExpSubstitute=1
Substitute="(?s).*DNS Servers:(.*?\n).*":"\1","(#CRLF#+)":"",",":"[\13][\10]","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1
DynamicVariables=1

[measureMACAddressValues]
Measure=String
String=#IPDetailsData#
RegExpSubstitute=1
Substitute="(?s).*MAC Addresses:(.*?\n).*":"\1","(#CRLF#+)":"",",":"[\13][\10]","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1
DynamicVariables=1

[measureNetworkCardNameValues]
Measure=String
String=#IPDetailsData#
RegExpSubstitute=1
Substitute="(?s).*NIC Names:(.*?\n).*":"\1","(#CRLF#+)":"","^(.+)$":"• \1",",":"[\13][\10]• ","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1
DynamicVariables=1

[measureNetworkCardTypeValues]
Measure=String
String=#IPDetailsData#
RegExpSubstitute=1
Substitute="(?s).*NIC Types:(.*?\n).*":"\1","(#CRLF#+)":"",",":"[\13][\10]","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1
DynamicVariables=1

[measureNetworkCardSpeedValues]
Measure=String
String=#IPDetailsData#
RegExpSubstitute=1
Substitute="(?s).*NIC Speeds:(.*?\n).*":"\1","(#CRLF#+)":"",",":"[\13][\10]","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1
DynamicVariables=1