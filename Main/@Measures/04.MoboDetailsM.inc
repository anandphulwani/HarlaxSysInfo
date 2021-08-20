[measureMotherboardname]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic baseboard get product
OutputType=ANSI
RegExpSubstitute=1
Substitute="Product.*#CRLF#":"","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1


[measureGPUName]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic path win32_VideoController get name
OutputType=ANSI
RegExpSubstitute=1
Substitute="Name.*#CRLF#":"","Radeon":"AMD Radeon","NVIDIA GeForce":"NVIDIA GeForce","Radmin.*":"","(#CRLF#+)":"","^(\s+)":"","(\s+)$":"","":"[\9]"
UpdateDivider=-1


