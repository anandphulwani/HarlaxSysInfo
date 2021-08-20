;--------------------------------------------------------------------------------------------------------------------------------------
[measureLoadServersPingDetails]
Measure=Plugin
Plugin=RunCommand
Parameter=#ROOTCONFIGPATH#/PythonEXEs/multipleServerPingChecker.exe -i "../ServersToPing.ini" -p #ROOTCONFIGPATH#/PingFiles/CheckServerConnectivity/ -l
State=Hide
OutputType=UTF8
FinishAction=[!SetVariable "initServersPingDetails" "[measureLoadServersPingDetails]"][!EnableMeasure "measureUpdateLoadServersPingDetails"][!UpdateMeasure "measureUpdateLoadServersPingDetails"]
UpdateDivider=-1
DynamicVariables=1

[measureUpdateLoadServersPingDetails]
Measure=String
String=#initServersPingDetails#
RegExpSubstitute=1
Substitute="(?s)(.*)\|\|\|\|\|(.*)":"\2","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","\\2":""
OnUpdateAction=[!SetVariable "loadServersPingDetails" "[measureUpdateLoadServersPingDetails]"]
UpdateDivider=-1
DynamicVariables=1
Disabled=1
;--------------------------------------------------------------------------------------------------------------------------------------

[measureServerPingDetailsData]
Measure=Plugin
Plugin=RunCommand
Parameter=#ROOTCONFIGPATH#/PythonEXEs/multipleServerPingChecker.exe -i "../ServersToPing.ini" -c #internetConnCheckInterval# -p #ROOTCONFIGPATH#/PingFiles/CheckServerConnectivity/ -n #isInternetConnected# -s #loadServersPingDetails#
State=Hide
OutputType=UTF8
FinishAction=[!SetVariable "initServersPingDetails" "[measureServerPingDetailsData]"][!UpdateMeasure "measureUpdateLoadServersPingDetails"][!UpdateMeasure "measureServerPingDetailsDataSub1"]
UpdateDivider=-1
DynamicVariables=1

[measureServerPingDetailsDataSub1]
Measure=String
String=[measureServerPingDetailsData]
RegExpSubstitute=1
Substitute="(?s)(.*)\|\|\|\|\|(.*)":"\1","([[:blank:]][[:blank:]]+)":" ","\\1":""
OnUpdateAction=[!SetVariable "serverPingDetailsData" "[measureServerPingDetailsDataSub1]"][!UpdateMeasure "measureServer1"][!UpdateMeasure "measureServer2"][!UpdateMeasure "measureServer3"][!UpdateMeasure "measureServer4"][!UpdateMeasure "measureServer5"][!UpdateMeasure "measureServer6"][!UpdateMeasure "measureServer7"][!UpdateMeasure "measureServer8"]
UpdateDivider=-1
DynamicVariables=1

[measureSetServerStatusToNull]
Measure=String
String=
OnUpdateAction=[!SetVariable "serverPingDetailsData" "01.PfSense:-2[\13][\10]02.TataSkyRouter:-2[\13][\10]03.AirtelRouter:-2[\13][\10]04.BSNLRouter:-2[\13][\10]05.WifiOld:-2[\13][\10]06.WifiNew:-2[\13][\10]07.CiscoWifiDDWRT:-2[\13][\10]08.Flourish:-2[\13][\10]"][!UpdateMeasure "measureServer1"][!UpdateMeasure "measureServer2"][!UpdateMeasure "measureServer3"][!UpdateMeasure "measureServer4"][!UpdateMeasure "measureServer5"][!UpdateMeasure "measureServer6"][!UpdateMeasure "measureServer7"][!UpdateMeasure "measureServer8"]
UpdateDivider=-1
DynamicVariables=1

[measureServer1]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*01.PfSense:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","-2":"","1":"Online","2":"Online(Lag)","3":"Offline","4":"No Internet"
OnUpdateAction=[!UpdateMeasure "measureServer1UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer1UpdateIcon]
Measure=String
String=[measureServer1]
IfMatch=^Online\(Lag\)$
IfMatchAction=[!SetOption meterServer1Image ImageName Warning.png][!UpdateMeter meterServer1Image]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer1Image ImageName Online.png][!UpdateMeter meterServer1Image]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer1Image ImageName Offline.png][!UpdateMeter meterServer1Image]
IfMatch4=^No Internet$|^$
IfMatchAction4=[!SetOption meterServer1Image ImageName ""][!UpdateMeter meterServer1Image]
UpdateDivider=-1
DynamicVariables=1

[measureServer2]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*02.TataSkyRouter:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","-2":"","1":"Online","2":"Online(Lag)","3":"Offline","4":"No Internet"
OnUpdateAction=[!UpdateMeasure "measureServer2UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer2UpdateIcon]
Measure=String
String=[measureServer2]
IfMatch=^Online\(Lag\)$
IfMatchAction=[!SetOption meterServer2Image ImageName Warning.png][!UpdateMeter meterServer2Image]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer2Image ImageName Online.png][!UpdateMeter meterServer2Image]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer2Image ImageName Offline.png][!UpdateMeter meterServer2Image]
IfMatch4=^No Internet$|^$
IfMatchAction4=[!SetOption meterServer2Image ImageName ""][!UpdateMeter meterServer2Image]
UpdateDivider=-1
DynamicVariables=1

[measureServer3]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*03.AirtelRouter:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","-2":"","1":"Online","2":"Online(Lag)","3":"Offline","4":"No Internet"
OnUpdateAction=[!UpdateMeasure "measureServer3UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer3UpdateIcon]
Measure=String
String=[measureServer3]
IfMatch=^Online\(Lag\)$
IfMatchAction=[!SetOption meterServer3Image ImageName Warning.png][!UpdateMeter meterServer3Image]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer3Image ImageName Online.png][!UpdateMeter meterServer3Image]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer3Image ImageName Offline.png][!UpdateMeter meterServer3Image]
IfMatch4=^No Internet$|^$
IfMatchAction4=[!SetOption meterServer3Image ImageName ""][!UpdateMeter meterServer3Image]
UpdateDivider=-1
DynamicVariables=1

[measureServer4]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*04.BSNLRouter:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","-2":"","1":"Online","2":"Online(Lag)","3":"Offline","4":"No Internet"
OnUpdateAction=[!UpdateMeasure "measureServer4UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer4UpdateIcon]
Measure=String
String=[measureServer4]
IfMatch=^Online\(Lag\)$
IfMatchAction=[!SetOption meterServer4Image ImageName Warning.png][!UpdateMeter meterServer4Image]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer4Image ImageName Online.png][!UpdateMeter meterServer4Image]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer4Image ImageName Offline.png][!UpdateMeter meterServer4Image]
IfMatch4=^No Internet$|^$
IfMatchAction4=[!SetOption meterServer4Image ImageName ""][!UpdateMeter meterServer4Image]
UpdateDivider=-1
DynamicVariables=1

[measureServer5]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*05.WifiOld:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","-2":"","1":"Online","2":"Online(Lag)","3":"Offline","4":"No Internet"
OnUpdateAction=[!UpdateMeasure "measureServer5UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer5UpdateIcon]
Measure=String
String=[measureServer5]
IfMatch=^Online\(Lag\)$
IfMatchAction=[!SetOption meterServer5Image ImageName Warning.png][!UpdateMeter meterServer5Image]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer5Image ImageName Online.png][!UpdateMeter meterServer5Image]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer5Image ImageName Offline.png][!UpdateMeter meterServer5Image]
IfMatch4=^No Internet$|^$
IfMatchAction4=[!SetOption meterServer5Image ImageName ""][!UpdateMeter meterServer5Image]
UpdateDivider=-1
DynamicVariables=1

[measureServer6]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*06.WifiNew:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","-2":"","1":"Online","2":"Online(Lag)","3":"Offline","4":"No Internet"
OnUpdateAction=[!UpdateMeasure "measureServer6UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer6UpdateIcon]
Measure=String
String=[measureServer6]
IfMatch=^Online\(Lag\)$
IfMatchAction=[!SetOption meterServer6Image ImageName Warning.png][!UpdateMeter meterServer6Image]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer6Image ImageName Online.png][!UpdateMeter meterServer6Image]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer6Image ImageName Offline.png][!UpdateMeter meterServer6Image]
IfMatch4=^No Internet$|^$
IfMatchAction4=[!SetOption meterServer6Image ImageName ""][!UpdateMeter meterServer6Image]
UpdateDivider=-1
DynamicVariables=1

[measureServer7]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*07.CiscoWifiDDWRT:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","-2":"","1":"Online","2":"Online(Lag)","3":"Offline","4":"No Internet"
OnUpdateAction=[!UpdateMeasure "measureServer7UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer7UpdateIcon]
Measure=String
String=[measureServer7]
IfMatch=^Online\(Lag\)$
IfMatchAction=[!SetOption meterServer7Image ImageName Warning.png][!UpdateMeter meterServer7Image]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer7Image ImageName Online.png][!UpdateMeter meterServer7Image]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer7Image ImageName Offline.png][!UpdateMeter meterServer7Image]
IfMatch4=^No Internet$|^$
IfMatchAction4=[!SetOption meterServer7Image ImageName ""][!UpdateMeter meterServer7Image]
UpdateDivider=-1
DynamicVariables=1

[measureServer8]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*08.Flourish:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","-2":"","1":"Online","2":"Online(Lag)","3":"Offline","4":"No Internet"
OnUpdateAction=[!UpdateMeasure "measureServer8UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer8UpdateIcon]
Measure=String
String=[measureServer8]
IfMatch=^Online\(Lag\)$
IfMatchAction=[!SetOption meterServer8Image ImageName Warning.png][!UpdateMeter meterServer8Image][!Redraw]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer8Image ImageName Online.png][!UpdateMeter meterServer8Image][!Redraw]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer8Image ImageName Offline.png][!UpdateMeter meterServer8Image][!Redraw]
IfMatch4=^No Internet$|^$
IfMatchAction4=[!SetOption meterServer8Image ImageName ""][!UpdateMeter meterServer8Image][!Redraw]
UpdateDivider=-1
DynamicVariables=1