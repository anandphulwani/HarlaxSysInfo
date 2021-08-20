[measureServerPingDetailsDataFetcher]
Measure=Calc
Formula=1
OnUpdateAction=[!CommandMeasure "measureServerPingDetailsData" "Run"]
UpdateDivider=#serverConnCheckInterval#

[measureServerPingDetailsData]
Measure=Plugin
Plugin=RunCommand
Parameter=#ROOTCONFIGPATH#/PythonEXEs/multipleServerPingChecker.exe -i "../ServersToPing.ini" -c #serverConnCheckInterval# -p #ROOTCONFIGPATH#/PingFiles/CheckServerConnectivity/
State=Hide
OutputType=UTF8
FinishAction=[!SetVariable "serverPingDetailsData" "[measureServerPingDetailsData]"][!UpdateMeasure "measureServer1"][!UpdateMeasure "measureServer2"][!UpdateMeasure "measureServer3"][!UpdateMeasure "measureServer4"][!UpdateMeasure "measureServer5"][!UpdateMeasure "measureServer6"][!UpdateMeasure "measureServer7"][!UpdateMeasure "measureServer8"][!UpdateMeasure "measureServer9"][!UpdateMeasure "measureServer10"][!UpdateMeasure "measureServer11"][!UpdateMeasure "measureServer12"][!UpdateMeasure "measureServer13"][!UpdateMeasure "measureServer14"]
UpdateDivider=-1
DynamicVariables=1

[measureServer1]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*BSNLRouter:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","1":"Online","2":"Online/Lagging","3":"Offline"
OnUpdateAction=[!UpdateMeasure "measureServer1UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer1UpdateIcon]
Measure=String
String=[measureServer1]
IfMatch=^Online\/Lagging$
IfMatchAction=[!SetOption meterServer1Image ImageName Warning.png][!UpdateMeter meterServer1Image][!Redraw]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer1Image ImageName Online.png][!UpdateMeter meterServer1Image][!Redraw]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer1Image ImageName Offline.png][!UpdateMeter meterServer1Image][!Redraw]
UpdateDivider=-1
DynamicVariables=1

[measureServer2]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*TataSkyRouter:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","1":"Online","2":"Online/Lagging","3":"Offline"
OnUpdateAction=[!UpdateMeasure "measureServer2UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer2UpdateIcon]
Measure=String
String=[measureServer2]
IfMatch=^Online\/Lagging$
IfMatchAction=[!SetOption meterServer2Image ImageName Warning.png][!UpdateMeter meterServer2Image][!Redraw]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer2Image ImageName Online.png][!UpdateMeter meterServer2Image][!Redraw]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer2Image ImageName Offline.png][!UpdateMeter meterServer2Image][!Redraw]
UpdateDivider=-1
DynamicVariables=1

[measureServer3]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*AirtelRouter:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","1":"Online","2":"Online/Lagging","3":"Offline"
OnUpdateAction=[!UpdateMeasure "measureServer3UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer3UpdateIcon]
Measure=String
String=[measureServer3]
IfMatch=^Online\/Lagging$
IfMatchAction=[!SetOption meterServer3Image ImageName Warning.png][!UpdateMeter meterServer3Image][!Redraw]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer3Image ImageName Online.png][!UpdateMeter meterServer3Image][!Redraw]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer3Image ImageName Offline.png][!UpdateMeter meterServer3Image][!Redraw]
UpdateDivider=-1
DynamicVariables=1

[measureServer4]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*PfSense:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","1":"Online","2":"Online/Lagging","3":"Offline"
OnUpdateAction=[!UpdateMeasure "measureServer4UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer4UpdateIcon]
Measure=String
String=[measureServer4]
IfMatch=^Online\/Lagging$
IfMatchAction=[!SetOption meterServer4Image ImageName Warning.png][!UpdateMeter meterServer4Image][!Redraw]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer4Image ImageName Online.png][!UpdateMeter meterServer4Image][!Redraw]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer4Image ImageName Offline.png][!UpdateMeter meterServer4Image][!Redraw]
UpdateDivider=-1
DynamicVariables=1

[measureServer5]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*WifiOld:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","1":"Online","2":"Online/Lagging","3":"Offline"
OnUpdateAction=[!UpdateMeasure "measureServer5UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer5UpdateIcon]
Measure=String
String=[measureServer5]
IfMatch=^Online\/Lagging$
IfMatchAction=[!SetOption meterServer5Image ImageName Warning.png][!UpdateMeter meterServer5Image][!Redraw]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer5Image ImageName Online.png][!UpdateMeter meterServer5Image][!Redraw]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer5Image ImageName Offline.png][!UpdateMeter meterServer5Image][!Redraw]
UpdateDivider=-1
DynamicVariables=1

[measureServer6]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*WifiNew:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","1":"Online","2":"Online/Lagging","3":"Offline"
OnUpdateAction=[!UpdateMeasure "measureServer6UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer6UpdateIcon]
Measure=String
String=[measureServer6]
IfMatch=^Online\/Lagging$
IfMatchAction=[!SetOption meterServer6Image ImageName Warning.png][!UpdateMeter meterServer6Image][!Redraw]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer6Image ImageName Online.png][!UpdateMeter meterServer6Image][!Redraw]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer6Image ImageName Offline.png][!UpdateMeter meterServer6Image][!Redraw]
UpdateDivider=-1
DynamicVariables=1

[measureServer7]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*CiscoWifiAPDDWRT:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","1":"Online","2":"Online/Lagging","3":"Offline"
OnUpdateAction=[!UpdateMeasure "measureServer7UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer7UpdateIcon]
Measure=String
String=[measureServer7]
IfMatch=^Online\/Lagging$
IfMatchAction=[!SetOption meterServer7Image ImageName Warning.png][!UpdateMeter meterServer7Image][!Redraw]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer7Image ImageName Online.png][!UpdateMeter meterServer7Image][!Redraw]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer7Image ImageName Offline.png][!UpdateMeter meterServer7Image][!Redraw]
UpdateDivider=-1
DynamicVariables=1

[measureServer8]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*proxmoxA:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","1":"Online","2":"Online/Lagging","3":"Offline"
OnUpdateAction=[!UpdateMeasure "measureServer8UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer8UpdateIcon]
Measure=String
String=[measureServer8]
IfMatch=^Online\/Lagging$
IfMatchAction=[!SetOption meterServer8Image ImageName Warning.png][!UpdateMeter meterServer8Image][!Redraw]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer8Image ImageName Online.png][!UpdateMeter meterServer8Image][!Redraw]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer8Image ImageName Offline.png][!UpdateMeter meterServer8Image][!Redraw]
UpdateDivider=-1
DynamicVariables=1

[measureServer9]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*proxmoxJ:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","1":"Online","2":"Online/Lagging","3":"Offline"
OnUpdateAction=[!UpdateMeasure "measureServer9UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer9UpdateIcon]
Measure=String
String=[measureServer9]
IfMatch=^Online\/Lagging$
IfMatchAction=[!SetOption meterServer9Image ImageName Warning.png][!UpdateMeter meterServer9Image][!Redraw]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer9Image ImageName Online.png][!UpdateMeter meterServer9Image][!Redraw]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer9Image ImageName Offline.png][!UpdateMeter meterServer9Image][!Redraw]
UpdateDivider=-1
DynamicVariables=1

[measureServer10]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*Legend:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","1":"Online","2":"Online/Lagging","3":"Offline"
OnUpdateAction=[!UpdateMeasure "measureServer10UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer10UpdateIcon]
Measure=String
String=[measureServer10]
IfMatch=^Online\/Lagging$
IfMatchAction=[!SetOption meterServer10Image ImageName Warning.png][!UpdateMeter meterServer10Image][!Redraw]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer10Image ImageName Online.png][!UpdateMeter meterServer10Image][!Redraw]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer10Image ImageName Offline.png][!UpdateMeter meterServer10Image][!Redraw]
UpdateDivider=-1
DynamicVariables=1

[measureServer11]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*Tulip:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","1":"Online","2":"Online/Lagging","3":"Offline"
OnUpdateAction=[!UpdateMeasure "measureServer11UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer11UpdateIcon]
Measure=String
String=[measureServer11]
IfMatch=^Online\/Lagging$
IfMatchAction=[!SetOption meterServer11Image ImageName Warning.png][!UpdateMeter meterServer11Image][!Redraw]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer11Image ImageName Online.png][!UpdateMeter meterServer11Image][!Redraw]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer11Image ImageName Offline.png][!UpdateMeter meterServer11Image][!Redraw]
UpdateDivider=-1
DynamicVariables=1

[measureServer12]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*xammpserver:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","1":"Online","2":"Online/Lagging","3":"Offline"
OnUpdateAction=[!UpdateMeasure "measureServer12UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer12UpdateIcon]
Measure=String
String=[measureServer12]
IfMatch=^Online\/Lagging$
IfMatchAction=[!SetOption meterServer12Image ImageName Warning.png][!UpdateMeter meterServer12Image][!Redraw]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer12Image ImageName Online.png][!UpdateMeter meterServer12Image][!Redraw]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer12Image ImageName Offline.png][!UpdateMeter meterServer12Image][!Redraw]
UpdateDivider=-1
DynamicVariables=1

[measureServer13]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*Flourish:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","1":"Online","2":"Online/Lagging","3":"Offline"
OnUpdateAction=[!UpdateMeasure "measureServer13UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer13UpdateIcon]
Measure=String
String=[measureServer13]
IfMatch=^Online\/Lagging$
IfMatchAction=[!SetOption meterServer13Image ImageName Warning.png][!UpdateMeter meterServer13Image][!Redraw]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer13Image ImageName Online.png][!UpdateMeter meterServer13Image][!Redraw]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer13Image ImageName Offline.png][!UpdateMeter meterServer13Image][!Redraw]
UpdateDivider=-1
DynamicVariables=1

[measureServer14]
Measure=String
String=#serverPingDetailsData#
RegExpSubstitute=1
Substitute="(?s).*PowerOutageRouter:(.*?\n).*":"\1","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","1":"Online","2":"Online/Lagging","3":"Offline"
OnUpdateAction=[!UpdateMeasure "measureServer14UpdateIcon"]
UpdateDivider=-1
DynamicVariables=1

[measureServer14UpdateIcon]
Measure=String
String=[measureServer14]
IfMatch=^Online\/Lagging$
IfMatchAction=[!SetOption meterServer14Image ImageName Warning.png][!UpdateMeter meterServer14Image][!Redraw]
IfMatch2=^Online$
IfMatchAction2=[!SetOption meterServer14Image ImageName Online.png][!UpdateMeter meterServer14Image][!Redraw]
IfMatch3=^Offline$
IfMatchAction3=[!SetOption meterServer14Image ImageName Offline.png][!UpdateMeter meterServer14Image][!Redraw]
UpdateDivider=-1
DynamicVariables=1

