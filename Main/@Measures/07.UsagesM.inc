[measureCPU]
Measure=CPU
Processor=0

[measurePhysMemTotal]
Measure=PhysicalMemory
Total=1
UpdateDivider=-1

[measurePhysMemUsed]
Measure=PhysicalMemory
UpdateDivider=5

[measurePhysMemTotalReadable]
Measure=Calc
Formula=Round((measurePhysMemTotal / 1024 / 1024 / 1024), 2)
UpdateDivider=-1

[measurePhysMemUsedReadable]
Measure=Calc
Formula=Round((MeasurePhysMemUsed/ 1024 / 1024 / 1024), 2)
UpdateDivider=5

[measureRAMUsage]
Returns the amount of RAM used in bytes.
Measure=PhysicalMemory
UpdateDivider=20
; 1000 milliseconds (Update in the [Rainmeter] section). 1000 x 20 = 20000 ms or 20 seconds.

[measureSWAP]
Measure=SwapMemory
UpdateDivider=20

; This measure returns the total disk space
[measureTotalDisk1]
Measure=FreeDiskSpace
Drive=#disk1#
Total=1
UpdateDivider=120

; Returns inverted value of free disk space (i.e. used disk space)
[measureUsedDisk1]
Measure=FreeDiskSpace
Drive=#disk1#
InvertMeasure=1
UpdateDivider=120

[measureTotalDisk2]
Measure=FreeDiskSpace
Drive=#disk2#
Total=1
UpdateDivider=120

[measureUsedDisk2]
Measure=FreeDiskSpace
Drive=#disk2#
InvertMeasure=1
UpdateDivider=120

[measureIP]
Measure=String
String=#pingAndPublicIPDetailsData#
RegExpSubstitute=1
Substitute="(.*)\|\|\|\|\|(.*){:-:}(.*){:-:}(.*)":"\3","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","\\3":"N/A","":"N/A"
UpdateDivider=-1
DynamicVariables=1

[measureISP]
Measure=String
String=#pingAndPublicIPDetailsData#
RegExpSubstitute=1
Substitute="(.*)\|\|\|\|\|(.*){:-:}(.*){:-:}(.*)":"\4","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","\\4":"N/A","":"N/A"
OnUpdateAction=[!UpdateMeter meterISPValue]
UpdateDivider=-1
DynamicVariables=1

[measureNetIn]
Measure=NetIn
Interface=Best
DynamicVariables=1

[measureNetOut]
Measure=NetOut
Interface=Best
DynamicVariables=1
