[measureLANConnected]
Measure=Plugin
Plugin=SysInfo
SysInfoType=LAN_CONNECTIVITY
IfCondition=measureLANConnected = 1
IfTrueAction=[!SetOption MeterLANConnectedImage ImageName Online.png][!UpdateMeter MeterLANConnectedImage][!Redraw]
IfCondition2=measureLANConnected = -1
IfTrueAction2=[!SetOption MeterLANConnectedImage ImageName Offline.png][!UpdateMeter MeterLANConnectedImage][!Redraw]
IfCondition3=(measureLANConnected <> 1) && (measureLANConnected <> -1)
IfTrueAction3=[!SetOption MeterLANConnectedImage ImageName ][!UpdateMeter MeterLANConnectedImage][!Redraw]
UpdateDivider=30

;--------------------------------------------------------------------------------------------------------------------------------------
[measureLoadServersPingAndPublicIP]
Measure=Plugin
Plugin=RunCommand
Parameter=#ROOTCONFIGPATH#/PythonEXEs/pingAndPublicIPDetails.exe -l -p #ROOTCONFIGPATH#/PingFiles/CheckInternetConnectivity/
State=Hide
OutputType=UTF8
FinishAction=[!SetVariable "loadServersPingAndPublicIP" "[measureLoadServersPingAndPublicIP]"][!Delay 2000][!EnableMeasure "measurePingAndPublicIPDetailsDataFetcher"][!UpdateMeasure "measurePingAndPublicIPDetailsDataFetcher"]
UpdateDivider=-1
DynamicVariables=1

[measureUpdateLoadServersPingAndPublicIP]
Measure=String
String=#pingAndPublicIPDetailsData#
RegExpSubstitute=1
Substitute="(.*)\|\|\|\|\|(.*){:-:}(.*){:-:}(.*)":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","\\1":"","":"[\9]"
OnUpdateAction=[!SetVariable "loadServersPingAndPublicIP" "[measureUpdateLoadServersPingAndPublicIP]"]
UpdateDivider=-1
DynamicVariables=1
Disabled=1
;--------------------------------------------------------------------------------------------------------------------------------------
[measurePingAndPublicIPDetailsDataFetcher]
Measure=Calc
Formula=1
OnUpdateAction=[!UpdateMeasure "measurePingAndPublicIPDetailsData"][!CommandMeasure "measurePingAndPublicIPDetailsData" "Run"][!CommandMeasure measureFetchIPDetailsData "Run"]
UpdateDivider=#internetConnCheckInterval#
Disabled=1

[measurePingAndPublicIPDetailsData]
Measure=Plugin
Plugin=RunCommand
Parameter=#ROOTCONFIGPATH#/PythonEXEs/pingAndPublicIPDetails.exe -c #internetConnCheckInterval# -p #ROOTCONFIGPATH#/PingFiles/CheckInternetConnectivity/ -s #loadServersPingAndPublicIP#
State=Hide
OutputType=UTF8
FinishAction=[!SetVariable "pingAndPublicIPDetailsData" "[measurePingAndPublicIPDetailsData]"][!EnableMeasure "measureUpdateLoadServersPingAndPublicIP"][!UpdateMeasure "measureUpdateLoadServersPingAndPublicIP"][!EnableMeasure "measureInternetConnected"][!UpdateMeasure "measureInternetConnected"][!UpdateMeasure "measureIP"][!UpdateMeasure "measureISP"]
UpdateDivider=-1
DynamicVariables=1

[measureInternetConnected]
Measure=String
String=#pingAndPublicIPDetailsData#
RegExpSubstitute=1
Substitute="(.*)\|\|\|\|\|(.*){:-:}(.*){:-:}(.*)":"\2","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","\\2":"","":"[\9]"
OnUpdateAction=[!UpdateMeasure "measureSetServerStatusToNull"][!Delay 1][!UpdateMeasure "measureInternetUpdateIcon"][!SetVariable "isInternetConnected" "[measureInternetConnected]"][!UpdateMeasure "measureServerPingDetailsData"][!Delay 1][!CommandMeasure "measureServerPingDetailsData" "Run"]
UpdateDivider=-1
DynamicVariables=1
Disabled=1

[measureInternetUpdateIcon]
Measure=String
String=[measureInternetConnected]
IfCondition=(measureInternetUpdateIcon = 0)
IfTrueAction=[!SetOption MeterInternetConnectedImage ImageName ""][!UpdateMeter MeterInternetConnectedImage][!Redraw]
IfCondition2=(measureInternetUpdateIcon = 1)
IfTrueAction2=[!SetOption MeterInternetConnectedImage ImageName Online.png][!UpdateMeter MeterInternetConnectedImage][!Redraw]
IfCondition3=(measureInternetUpdateIcon = 2)
IfTrueAction3=[!SetOption MeterInternetConnectedImage ImageName Warning.png][!UpdateMeter MeterInternetConnectedImage][!Redraw]
IfCondition4=(measureInternetUpdateIcon = 3)
IfTrueAction4=[!SetOption MeterInternetConnectedImage ImageName Offline.png][!UpdateMeter MeterInternetConnectedImage][!Redraw]
; FinishAction=[!SetVariable "isInternetConnected" "[measureInternetConnected]"]
UpdateDivider=-1
DynamicVariables=1

[measureDomainName]
Measure=Plugin
Plugin=SysInfo
SysInfoType=DOMAIN_NAME
RegExpSubstitute=1
Substitute="(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","":"[\9]"
UpdateDivider=-1

[measureDomainWorkgroup]
Measure=Plugin
Plugin=SysInfo
SysInfoType=DOMAINWORKGROUP
RegExpSubstitute=1
Substitute="(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","":"[\9]"
UpdateDivider=-1
