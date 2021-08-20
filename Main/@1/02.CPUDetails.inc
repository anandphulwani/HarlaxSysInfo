[Serial2_1]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=4R
Text="2.1. "
Group=Hidethis

[meterCPUNameTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
Text="CPU: "
Group=Hidethis

[meterCPUNameValue]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=192
MeasureName=measureCPUName
MeasureName2=measureSocketDesignation
Text="%1 %2"
DynamicVariables=1
Group=Hidethis
ClipString=2

[Serial2_2]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=0R
Text="2.2. "
Group=Hidethis

[meterCPUCoresNumbersTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
Text="CPU Cores (Phy. / Vir.): "
Group=Hidethis

[meterCPUCoresNumbersValue]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=105
MeasureName=CPUPhyC
MeasureName2=CPUVirC
Text="%1 / %2"
Group=Hidethis
ClipString=2

[Serial2_3]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=0R
Text="2.3. "
Group=Hidethis

[meterCPUTemperatureTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
Text="Temperature / Fan: "
Group=Hidethis

[meterCPUTemperatureValue]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
MeasureName=measureCPUTempValue
Text="%1"
InlineSetting=Color | 50,250,50,255
InlinePattern=([0-4][0-9]°\sC)
InlineSetting2=Color | 255,215,0,255
InlinePattern2=([5][0-9]°\sC|[6][0-2]°\sC)
InlineSetting3=Color | 255,120,73,255
InlinePattern3=([6][3-9]°\sC|[7-9][0-9]°\sC)
Group=Hidethis

[meterCPUFanValue]
Meter=String
MeterStyle=StyleBoldLeft
X=0R
Y=0r
MeasureName=measureCPUFanValue
InlineSetting=Color | 50,250,50,255
InlinePattern=([0-9][0-9][0-9]\sRPM|[1][0-9][0-9][0-9]\sRPM|)
InlineSetting2=Color | 255,215,0,255
InlinePattern2=([2][0-9][0-9][0-9]\sRPM)
InlineSetting3=Color | 255,120,73,255
InlinePattern3=([3-9][0-9][0-9][0-9]\sRPM)
Text="  %1"
Group=Hidethis
