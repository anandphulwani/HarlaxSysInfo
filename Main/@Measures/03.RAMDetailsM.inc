[measureRAMManufacturer]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic memorychip get manufacturer
State=Hide
OutputType=ANSI
RegExpSubstitute=1
Substitute="No Instance\(s\) Available\.":"","Manufacturer#CRLF#":"","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","":"[\9]"
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
Substitute="No Instance\(s\) Available\.":"","DeviceLocator#CRLF#":"","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1

[measureRAMCapacities]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic memorychip get capacity
State=Hide
OutputType=ANSI
RegExpSubstitute=1
Substitute="No Instance\(s\) Available\.":"","Capacity#CRLF#":"","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1

[measureRAMPartNumbers]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic memorychip get partnumber
State=Hide
OutputType=ANSI
RegExpSubstitute=1
Substitute="No Instance\(s\) Available\.":"","PartNumber#CRLF#":"","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1

[measureRAMSpeeds]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic memorychip get speed
State=Hide
OutputType=ANSI
RegExpSubstitute=1
Substitute="No Instance\(s\) Available\.":"","Speed#CRLF#":"","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1