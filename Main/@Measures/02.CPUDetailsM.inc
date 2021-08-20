[measureCPUName]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=HARDWARE\DESCRIPTION\System\CentralProcessor\0
RegValue=ProcessorNameString
UpdateDivider=12000
RegExpSubstitute=1
Substitute="CPU":"","\(TM\)|\(tm\)|\(Tm\)":"","Processor":"","(\w{1,4}[\s\S]Core[s]?)":"","(Intel Core|Intel\(R\) Core)":"Intel(R) Core","@":"","AMD Ryzen ":"AMD Ryzen R","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1

[measureSocketDesignation]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic cpu get SocketDesignation
OutputType=ANSI
RegExpSubstitute=1
Substitute="SocketDesignation.*#CRLF#":"","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","(.+)":"(\1)","":"[\9]"
UpdateDivider=-1

[CPUPhyC]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic CPU Get NumberOfCores
State=Hide
OutputType=ANSI
RegExpSubstitute=1
Substitute="NumberOfCores":"","(#CRLF#+)":"","^(\s+)":"","(\s+)$":""
UpdateDivider=-1

[CPUVirC]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic CPU Get NumberOfLogicalProcessors
State=Hide
OutputType=ANSI
RegExpSubstitute=1
Substitute="NumberOfLogicalProcessors":"","(#CRLF#+)":"","^(\s+)":"","(\s+)$":""
UpdateDivider=-1
