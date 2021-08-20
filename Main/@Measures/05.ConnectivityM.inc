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

[measurePingAndPublicIPDetailsDataFetcher]
Measure=Calc
Formula=1
OnUpdateAction=[!CommandMeasure "measurePingAndPublicIPDetailsData" "Run"]
UpdateDivider=#internetConnCheckInterval#

[measurePingAndPublicIPDetailsData]
Measure=Plugin
Plugin=RunCommand
Parameter=#ROOTCONFIGPATH#/PythonEXEs/pingAndPublicIPDetails.exe -c #internetConnCheckInterval# -p #ROOTCONFIGPATH#/PingFiles/CheckInternetConnectivity/
State=Hide
OutputType=UTF8
FinishAction=[!SetVariable "pingAndPublicIPDetailsData" "[measurePingAndPublicIPDetailsData]"][!UpdateMeasure "measureInternetConnected"][!UpdateMeasure "measureIP"][!UpdateMeasure "measureISP"]
UpdateDivider=-1
DynamicVariables=1

[measureInternetConnected]
Measure=String
String=#pingAndPublicIPDetailsData#
RegExpSubstitute=1
Substitute="(.*){:-:}(.*){:-:}(.*)":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","\\1":"","":"[\9]"
OnUpdateAction=[!UpdateMeasure "measureInternetUpdateIcon"][!SetVariable "isInternetConnected" "[measureInternetConnected:]"][!Delay 500][!UpdateMeasure "measureServerPingDetailsData"][!Delay 500][!CommandMeasure "measureServerPingDetailsData" "Run"]
UpdateDivider=-1
DynamicVariables=1

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
Substitute="(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1

[measureDomainWorkgroup]
Measure=Plugin
Plugin=SysInfo
SysInfoType=DOMAINWORKGROUP
RegExpSubstitute=1
Substitute="(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1
