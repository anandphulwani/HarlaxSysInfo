[measureCPUName]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=HARDWARE\DESCRIPTION\System\CentralProcessor\0
RegValue=ProcessorNameString
UpdateDivider=12000
RegExpSubstitute=1
Substitute="CPU":"","\(TM\)|\(tm\)|\(Tm\)":"","Processor":"","(\w{1,4}[\s\S]Core[s]?)":"","(Intel Core|Intel\(R\) Core)":"Intel(R) Core","@":"","AMD Ryzen ":"AMD Ryzen R","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","":"[\9]"
UpdateDivider=-1

[measureSocketDesignation]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic cpu get SocketDesignation
OutputType=ANSI
RegExpSubstitute=1
Substitute="SocketDesignation.*#CRLF#":"","(#CRLF#+)":"","\sCPU\s[0-9]":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","(.+)":"(\1)","":"[\9]"
UpdateDivider=-1

[CPUPhyC]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic CPU Get NumberOfCores
State=Hide
OutputType=ANSI
RegExpSubstitute=1
Substitute="NumberOfCores":"","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" "
UpdateDivider=-1

[CPUVirC]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic CPU Get NumberOfLogicalProcessors
State=Hide
OutputType=ANSI
RegExpSubstitute=1
Substitute="NumberOfLogicalProcessors":"","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" "
UpdateDivider=-1

[measureTemperatureAndFanDataFetcher]
Measure=Calc
Formula=1
OnUpdateAction=[!EnableMeasure "measureTemperatureAndFanDataError101Checker"][!UpdateMeasure "measureTemperatureAndFanDataError101Checker"]
UpdateDivider=#temperatureAndFanCheckInterval#
DynamicVariables=1

[measureTemperatureAndFanDataError101Checker]
Measure=String
String=#isTemperatureAndFanDataError101#
IfMatch=^0$
IfMatchAction=[!SetVariable "isTemperatureAndFanDataError101" 1][!UpdateMeasure "measureTemperatureAndFanData"][!CommandMeasure "measureTemperatureAndFanData" "Run"]
IfMatchMode=1
UpdateDivider=-1
DynamicVariables=1
Disabled=1

[measureTemperatureAndFanData]
Measure=Plugin
Plugin=RunCommand
Parameter=#ROOTCONFIGPATH#/PythonEXEs/getTemperatureAndFan.exe
State=Hide
OutputType=ANSI
; [!Log "Ran measureTemperatureAndFanData"]
FinishAction=[!SetVariable "isTemperatureAndFanDataError101" 0][!SetVariable "temperatureAndFanData" "[measureTemperatureAndFanData]"][!UpdateMeasure "measureCPUTempValue"][!UpdateMeasure "measureCPUFanValue"][!UpdateMeasure "measureMoboTempValue"][!UpdateMeasure "measureOtherFanValue"][!UpdateMeasure "measureGPUTempValue"][!UpdateMeasure "measureHDDModelsAndTempValue"]
UpdateDivider=-1
DynamicVariables=1

[measureCPUTempValue]
Measure=String
String=#temperatureAndFanData#
RegExpSubstitute=1
Substitute="(.*),(.*),(.*),(.*),(.*),(.*)":"\1","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","":"N/A","(.+)":"\1  /"
UpdateDivider=-1
DynamicVariables=1

[measureCPUFanValue]
Measure=String
String=#temperatureAndFanData#
RegExpSubstitute=1
Substitute="(.*),(.*),(.*),(.*),(.*),(.*)":"\5","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","":"N/A"
UpdateDivider=-1
DynamicVariables=1