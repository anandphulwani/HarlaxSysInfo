[Serial4_1]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=4R
Text="4.1. "
Group=Hidethis

[meterMotherboardNameTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
Text="Motherboard Name: "
Group=Hidethis

[meterMotherboardNameValue]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=122
MeasureName=measureMotherboardname
Text="%1"
Group=Hidethis
ClipString=2

[Serial4_2]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=0R
Text="4.2. "
Group=Hidethis

[meterMotherboardTemperatureTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
Text="Motherboard Temperature: "
Group=Hidethis

[meterMotherboardTemperatureValue]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=100
MeasureName=measureMoboTempValue
Text="%1"
InlineSetting=Color | 50,250,50,255
InlinePattern=([2-3][0-9]°\sC)
InlineSetting2=Color | 255,215,0,255
InlinePattern2=([4][0-9]°\sC)
InlineSetting3=Color | 255,120,73,255
InlinePattern3=([5-9][0-9]°\sC)
Group=Hidethis
ClipString=2

[Serial4_3]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=0R
Text="4.3. "
Group=Hidethis

[meterOtherFanTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
Text="Other Fan: "
Group=Hidethis

[meterOtherFanValue]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=120
MeasureName=measureOtherFanValue
InlineSetting=Color | 50,250,50,255
InlinePattern=([0-9][0-9][0-9]\sRPM|[1][0-9][0-9][0-9]\sRPM|)
InlineSetting2=Color | 255,215,0,255
InlinePattern2=([2][0-9][0-9][0-9]\sRPM)
InlineSetting3=Color | 255,120,73,255
InlinePattern3=([3-9][0-9][0-9][0-9]\sRPM)
Text="%1"
Group=Hidethis
ClipString=2

[Serial4_4]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=0R
Text="4.4. "
Group=Hidethis

[meterGPUNameTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
Text="GPU Name: "
Group=Hidethis

[meterGPUNameValue]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=162
MeasureName=measureGPUName
Text="%1"
Group=Hidethis
ClipString=2

[Serial4_5]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=0R
Text="4.5. "
Group=Hidethis

[meterGPUTemperatureTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
Text="GPU Temperature: "
Group=Hidethis

[meterGPUTemperatureValue]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=120
MeasureName=measureGPUTempValue
Text="%1"
InlineSetting=Color | 50,250,50,255
InlinePattern=(\([2-3][0-9]°\sC\))
InlineSetting2=Color | 255,215,0,255
InlinePattern2=(\([4][0-9]°\sC\))
InlineSetting3=Color | 255,120,73,255
InlinePattern3=(\([5-9][0-9]°\sC\))
Group=Hidethis
ClipString=2

[Serial4_6]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#-8)
Y=0R
Text="4.6. "
Group=Hidethis

[meterHDDModelsTemperatureTitle]
Meter=String
MeterStyle=StyleLeft
X=3R
Y=0r
W=135
Text="HDD Models (Temperature): "
Group=Hidethis

[meterHDDModelsTemperatureValue]
Meter=String
MeterStyle=StyleBoldLeft
X=(#widthtoggle#-8)+22
Y=0R
W=180
MeasureName=measureHDDModelsAndTempValue
Text="%1"
InlineSetting=Color | 50,250,50,255
InlinePattern=(\([2-3][0-9]°\sC\))
InlineSetting2=Color | 255,215,0,255
InlinePattern2=(\([4][0-9]°\sC\))
InlineSetting3=Color | 255,120,73,255
InlinePattern3=(\([5-9][0-9]°\sC\))
Group=Hidethis
ClipString=2