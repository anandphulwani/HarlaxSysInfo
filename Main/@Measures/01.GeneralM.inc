[measurePCName]
Measure=Plugin
Plugin=SysInfo
SysInfoType=COMPUTER_NAME
RegExpSubstitute=1
Substitute="(#CRLF#+)":"#CRLF#","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","":"[\9]"
UpdateDivider=-1

[measureUserName]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_NAME
RegExpSubstitute=1
Substitute="(#CRLF#+)":"#CRLF#","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","":"[\9]"
UpdateDivider=-1

[measureUserLogonTime]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_LOGONTIME
UpdateDivider=-1

[measureUserLogonTimeString]
Measure=Time
TimeStamp=[measureUserLogonTime]
Format=%a, %d-%b-%y %H:%M
RegExpSubstitute=1
Substitute="(#CRLF#+)":"#CRLF#","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","":"[\9]"
DynamicVariables=1
UpdateDivider=-1
Group=Account

[measureUptime]
Measure=Uptime
Format="%4!i! days, %3!02i!:%2!02i!:%1!02i!"
RegExpSubstitute=1
Substitute="0 days, ":"","(#CRLF#+)":"#CRLF#","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" ","":"[\9]"

[measureProductName]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=SOFTWARE\Microsoft\Windows NT\CurrentVersion
RegValue=ProductName
RegExpSubstitute=1
Substitute="(#CRLF#+)":"#CRLF#","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" "
UpdateDivider=-1

[measureOSBits]
Measure=Plugin
Plugin=SysInfo
SysInfoType=OS_BITS
RegExpSubstitute=1
Substitute="(#CRLF#+)":"#CRLF#","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" "
UpdateDivider=-1

[measureCSDVersion]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=SOFTWARE\Microsoft\Windows NT\CurrentVersion
RegValue=CSDVersion
RegExpSubstitute=1
Substitute="(#CRLF#+)":"#CRLF#","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" "
UpdateDivider=-1

[measureCurrentBuild]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=SOFTWARE\Microsoft\Windows NT\CurrentVersion
RegValue=CurrentBuild
RegExpSubstitute=1
Substitute="(#CRLF#+)":"#CRLF#","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" "
UpdateDivider=-1

[measureUBR]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=SOFTWARE\Microsoft\Windows NT\CurrentVersion
RegValue=UBR
RegExpSubstitute=1
Substitute="(#CRLF#+)":"#CRLF#","^(\s+)":"","(\s+)$":"","([[:blank:]][[:blank:]]+)":" "
UpdateDivider=-1