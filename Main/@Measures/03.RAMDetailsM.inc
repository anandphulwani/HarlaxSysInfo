[measureRAMManufacturer]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic memorychip get manufacturer
State=Hide
OutputType=ANSI
RegExpSubstitute=1
Substitute="No Instance\(s\) Available\.":"","^Manufacturer.*\n":"","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1

[measureRAMType]
Measure=Plugin
Plugin=RunCommand
Program=PowerShell.exe
Parameter=-NoProfile -ExecutionPolicy Bypass -File "getMemory.ps1"
State=Hide
OutputType=UTF8
RegExpSubstitute=1
Substitute="The argument.*":"","Size: 0 bytes(?s).*?=======================":"","Size: .*":"","Memory form factor: .*":"","Memory type: .*\((.*)\)":"\1","Type detail: .*":"","Speed: .*":"","=======================":"","(#CRLF#)+":"#CRLF#","^(\s+)":"","(\s+)$":"","":"[\9]"
; Substitute="(#CRLF#+)":"",",":"[\13][\10]","^(\s+)":"","(\s+)$":"","":"[\9]"        "^(.*)(\r?\n\1)+$":"\1"
UpdateDivider=-1
DynamicVariables=1

[measureRAMDeviceLocators]



Measure=Plugin
Plugin=RunCommand
Parameter=wmic memorychip get devicelocator
State=Hide
OutputType=ANSI
RegExpSubstitute=1
Substitute="No Instance\(s\) Available\.":"","^DeviceLocator.*\n":"","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1

[measureRAMCapacities]
Measure=Plugin
Plugin=RunCommand
Program="powershell.exe"
Parameter="-inputformat none -NoProfile -NonInteractive -command "GWmi CIM_PhysicalMemory | % {\"\" + ($_.capacity / 1GB) + \" GB\"}"
Parameter=PowerShell -NoProfile -ExecutionPolicy Bypass -NonInteractive -Command "GWmi CIM_PhysicalMemory | % {\"\" + ($_.capacity / 1GB) + \" GB\"}"
State=Hide
OutputType=ANSI
RegExpSubstitute=1
Substitute="No Instance\(s\) Available\.":"","^Capacity.*\n":"","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1
DynamicVariables=1

[measureRAMPartNumbers]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic memorychip get partnumber
State=Hide
OutputType=ANSI
RegExpSubstitute=1
Substitute="No Instance\(s\) Available\.":"","^PartNumber.*\n":"","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1

[measureRAMSpeeds]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic memorychip get speed
State=Hide
OutputType=ANSI
RegExpSubstitute=1
Substitute="No Instance\(s\) Available\.":"","^Speed.*\n":"","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","(.+)":"\1 MHz","":"[\9]"
UpdateDivider=-1