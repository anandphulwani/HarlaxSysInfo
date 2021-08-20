[Serial1_1]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=0R
Text="1.1. "
Group=Hidethis

[meterPCNameTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
Text="PC Name: "
Group=Hidethis

[meterPCNameValue]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=170
MeasureName=measurePCName
Text="%1"
Group=Hidethis
ClipString=2

[Serial1_2]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=0R
Text="1.2. "
Group=Hidethis

[meterUserNameTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
Text="Username: "
Group=Hidethis

[meterUserNameValue]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=165
MeasureName=measureUserName
Text="%1"
Group=Hidethis
ClipString=2

[Serial1_3]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=0R
Text="1.3. "
Group=Hidethis

[meterLogonTimeTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
Text="Logon Time: "
Group=Hidethis

[meterLogonTimeValue]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=157
MeasureName=measureUserLogonTimeString
Text="%1"
Group=Hidethis
ClipString=2

[Serial1_4]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=0R
Text="1.4. "
Group=Hidethis

[meterUptimeTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
Text="Up Time: "
Group=Hidethis

[meterUptimeValue]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=172
MeasureName=measureUpTime
Text="%1"
Group=Hidethis
ClipString=2

[Serial1_5]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=0R
Text="1.5. "
Group=Hidethis

[meterOSNameTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
Text="OS: "
Group=Hidethis

[meterOSNameValue]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=199
MeasureName=measureProductName
MeasureName2=measureOSBits
MeasureName3=measureCSDVersion
Text="%1 (%2Bit)[\13][\10]%3"
Group=Hidethis
ClipString=2

[Serial1_6]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=0R
Text="1.6. "
Group=Hidethis

[meterOSDetailsTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
Text="Build (UBR): "
Group=Hidethis

[meterOSDetailsValue]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=158
MeasureName=measureCurrentBuild
MeasureName2=measureUBR
Text="%1 (%2)"
Group=Hidethis
ClipString=2