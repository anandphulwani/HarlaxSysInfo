;========================================
;Top Part
;========================================

[measureComputerName]
Measure=Plugin
Plugin=SysInfo
SysInfoType=COMPUTER_NAME
UpdateDivider=-1

[measureTime]
Measure=Time
Format=%H%M%S
[measureDate]
Measure=Time
Format=%a, %#b %#d
[measureOSBits]
Measure=Plugin
Plugin=SysInfo
SysInfoType=OS_BITS
UpdateDivider=-1
[measureMonitors]
Measure=Plugin
Plugin=SysInfo
SysInfoType=NUM_MONITORS
UpdateDivider=-1
[measureUsername]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_NAME
UpdateDivider=-1

[measureVersion]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=SOFTWARE\Microsoft\Windows NT\CurrentVersion
RegValue=DisplayVersion
UpdateDivider=-1

;========================================
;CPU
;========================================
; 
; [measureCPU]
; Measure=Plugin
; Plugin=UsageMonitor
; Alias=CPU
; Index=0
; RegExpSubstitute=1
; Substitute="^0$":"0.01"
; 
; [CPUTextActual]
; Measure=Calc
; Formula=MeasureCPU/5
; 
;========================================
;GPU
;========================================

[measureGPU]
Measure=Plugin
Plugin=UsageMonitor
Alias=GPU
Index=0
Blacklist=dwm
DynamicVariables=1
[GPUTextActual]
Measure=Calc
Formula=MeasureGPU/5

;========================================
;Bin
;========================================

[RecycleBinFiles]
Measure=RecycleManager
RecycleType=COUNT
Drives=ALL
UpdateDivider=60
Group=Bin
Substitute=".0":""
[RecycleBinSize]
Measure=RecycleManager
RecycleType=SIZE
Drives=ALL
UpdateDivider=60
Group=Bin

;========================================
;Internet
;========================================

; [InternetType]
; Measure=Plugin
; Plugin=SysInfo
; SysInfoType=ADAPTER_TYPE
; SysInfoData=Best
; UpdateDivider=-1
; IfCondition=InternetType=6
; IfTrueAction=[!SetVariable NetType Ethernet][!UpdateMeasure InternetStatus]
; IfCondition2=InternetType=71
; IfTrueAction2=[!SetVariable NetType Wifi][!UpdateMeasure InternetStatus]

; [InternetName]
; Measure=PLUGIN
; Plugin=WifiStatus
; WiFiInfoType=SSID
; Substitute="-1":""

; [InternetStatus]
; Measure=PLUGIN
; Plugin=SysInfo
; SysInfoType=INTERNET_CONNECTIVITY
; Substitute="-1.0":"Offline","1.0":"Connected"
; DynamicVariables=1
; IfCondition=InternetStatus = -1
; IfTrueAction=[!SetOption Internet Text "%6#CRLF#%1#CRLF#Click here to connect to the internet"][!UpdateMeter Internet][!Redraw]
; IfFalseAction=[!SetOption Internet Text "%6#CRLF#%1 %2-%3 Dl %4b | Ul %5b"][!UpdateMeter Internet][!Redraw]

; [mAUTH]
; Measure=PLUGIN
; Plugin=WifiStatus
; WiFiInfoType=AUTH
; Substitute="-1":""

; [InternetDownloadSpeed]
; Measure=NetIn
; Interface=Best
; MinValue=0
; AverageSize=5

; [InternetUploadSpeed]
; Measure=NetOut
; Interface=Best
; MinValue=0
; AverageSize=5

; ================================================
; Drives
; ================================================

[DriveCTotal]
Measure=FreeDiskSpace
Total=1
Drive=C:
UpdateDivider=120
Substitute=^0$":"0.000001"

[DriveDTotal]
Measure=FreeDiskSpace
Total=1
Drive=D:
UpdateDivider=120
Substitute=^0$":"0.000001"

[DriveCFree]
Measure=FreeDiskSpace
Drive=C:
UpdateDivider=120
Substitute="^0$":"0.000001"

[DriveDFree]
Measure=FreeDiskSpace
Drive=D:
UpdateDivider=120
Substitute=^0$":"0.000001"

[DriveCPercent]
Measure=Calc
Formula=(DriveCTotal-DriveCFree)/DriveCTotal*100
UpdateDivider=120

[DriveCActual]
Measure=Calc
Formula=DriveCPercent/5
UpdateDivider=120

[DriveDPercent]
Measure=Calc
Formula=(DriveDTotal-DriveDFree)/DriveDTotal*100
UpdateDivider=120

[DriveDActual]
Measure=Calc
Formula=DriveDPercent/5
UpdateDivider=120

[measureDriveCRead]
Measure=Plugin
Plugin=Plugins\PerfMon.dll
PerfMonObject=LogicalDisk
PerfMonCounter="Disk Read Bytes/sec"
PerfMonInstance=C:
Group=NonOverview

[measureDriveCWrite]
Measure=Plugin
Plugin=Plugins\PerfMon.dll
PerfMonObject=LogicalDisk
PerfMonCounter="Disk Write Bytes/sec"
PerfMonInstance=C:
Group=NonOverview

[measureDriveDRead]
Measure=Plugin
Plugin=Plugins\PerfMon.dll
PerfMonObject=LogicalDisk
PerfMonCounter="Disk Read Bytes/sec"
PerfMonInstance=D:
Group=NonOverview

[measureDriveDWrite]
Measure=Plugin
Plugin=Plugins\PerfMon.dll
PerfMonObject=LogicalDisk
PerfMonCounter="Disk Write Bytes/sec"
PerfMonInstance=D:
Group=NonOverview


