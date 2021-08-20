[Serial5_1]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=4R
Text="5.1. "
Group=Hidethis

[meterLANConnectedTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
Text="LAN / Internet Connected: "
Group=Hidethis

[MeterLANConnectedImage]
Meter=Image
X=3R
Y=2r
W=10
H=10
Group=Hidethis

[meterLANConnectedValue]
Meter=String
MeterStyle=StyleBoldLeft
X=3R
Y=-2r
Text=" / "
Group=Hidethis

[MeterInternetConnectedImage]
Meter=Image
X=3R
Y=2r
W=10
H=10
Group=Hidethis

[Serial5_2]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=2R
Text="5.2. "
Group=Hidethis

[meterDomainNameTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
Text="Domain: "
Group=Hidethis

[meterDomainNameValue]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=177
MeasureName=measureDomainName
Text="%1"
Group=Hidethis
ClipString=2

[Serial5_3]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=0R
Text="5.3. "
Group=Hidethis

[meterDomainWorkgroupTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
Text="Workgroup: "
Group=Hidethis

[meterDomainWorkgroupValue]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=162
MeasureName=measureDomainWorkgroup
Text="%1"
Group=Hidethis
ClipString=2