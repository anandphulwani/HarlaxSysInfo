; ----------------------------------
; METERS display images, text, bars, etc.
; ----------------------------------
[Serial7_1]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#+247)
Y=0R
Text="7.1. "
Group=Hidethis

[meterLabelCPU]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=190
H=14
Text=CPU
Group=Hidethis

[meterValueCPU]
Meter=String
MeterStyle=StyleBoldRight
MeasureName=measureCPU
X=(#widthtoggle#+462)
Y=0r
W=190
H=14
Text=%1%
Group=Hidethis

[meterBarCPU]
Meter=Bar
MeterStyle=styleBar
X=(#widthtoggle#+268)
Y=0R
W=195
H=1
MeasureName=measureCPU
Group=Hidethis

[Serial7_2]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#+247)
Y=4R
Text="7.2. "
Group=Hidethis

[meterLabelRAM]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=190
H=14
Text=RAM
Group=Hidethis

[meterValueRAMTotalCapacityValue]
Meter=String
MeterStyle=StyleBoldRight
X=(#widthtoggle#+462)
Y=0r
W=190
H=14
MeasureName=measurePhysMemUsedReadable
MeasureName2=measurePhysMemTotalReadable
Text=" (%1 GB / %2 GB)"
NumOfDecimals=2
Group=Hidethis

[meterValueRAM]
Meter=String
MeterStyle=StyleBoldRight
X=-110r
Y=0r
W=40
H=14
MeasureName=measureRAMUsage
Text="%1%"
Percentual=1
Group=Hidethis

[meterBarRAM]
Meter=Bar
MeterStyle=styleBar
X=(#widthtoggle#+268)
Y=0R
W=195
H=1
MeasureName=measureRAMUsage
Group=Hidethis

[Serial7_3]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#+247)
Y=4R
Text="7.3. "
Group=Hidethis

[meterLabelSWAP]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=190
H=14
Text=SWAP
Group=Hidethis

[meterValueSWAP]
Meter=String
MeterStyle=StyleBoldRight
X=(#widthtoggle#+462)
Y=0r
W=190
H=14
MeasureName=measureSWAP
Text=%1%
Percentual=1
Group=Hidethis

[meterBarSWAP]
Meter=Bar
MeterStyle=styleBar
X=(#widthtoggle#+268)
Y=0R
W=195
H=1
MeasureName=measureSWAP
Group=Hidethis

[Serial7_4]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#+247)
Y=4R
Text="7.4. "
Group=Hidethis

[meterLabelDisk1]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=190
H=14
Text=#disk1#\
Group=Hidethis

[meterValueDisk1]
Meter=String
MeterStyle=StyleBoldRight
X=(#widthtoggle#+462)
Y=0r
W=190
H=14
MeasureName=measureUsedDisk1
MeasureName2=measureTotalDisk1
Text=%1B/%2B used
NumOfDecimals=1
AutoScale=1
LeftMouseUpAction=["#disk1#\"]
Group=Hidethis

[meterBarDisk1]
Meter=Bar
MeterStyle=styleBar
X=(#widthtoggle#+268)
Y=0R
W=195
H=1
MeasureName=measureUsedDisk1
Group=Hidethis

[Serial7_5]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#+247)
Y=4R
Text="7.5. "
Group=Hidethis

[meterLabelDisk2]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=190
H=14
Text=#disk2#\
LeftMouseUpAction=["#disk2#\"]
Group=Hidethis

[meterValueDisk2]
Meter=String
MeterStyle=StyleBoldRight
X=(#widthtoggle#+462)
Y=0r
W=190
H=14
MeasureName=measureUsedDisk2
MeasureName2=measureTotalDisk2
Text=%1B/%2B used
NumOfDecimals=1
AutoScale=1
Group=Hidethis

[meterBarDisk2]
Meter=Bar
MeterStyle=styleBar
X=(#widthtoggle#+268)
Y=0R
W=195
H=1
MeasureName=measureUsedDisk2
Group=Hidethis

[Serial7_6]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#+247)
Y=4R
Text="7.6. "
Group=Hidethis

[meterIPLabel]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=190
H=14
Text=IP Address
Group=Hidethis

[meterIPValue]
Meter=String
MeterStyle=StyleBoldRight
X=(#widthtoggle#+462)
Y=0r
W=190
H=14
MeasureName=measureIP
Text=%1
Group=Hidethis
DynamicVariables=1

[Serial7_7]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#+247)
Y=4R
Text="7.7. "
Group=Hidethis

[meterISPLabel]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=190
H=14
Text=ISP
Group=Hidethis

[meterISPValue]
Meter=String
MeterStyle=StyleBoldRight
X=(#widthtoggle#+462)
Y=0r
W=150
MeasureName=measureISP
Text=%1
DynamicVariables=1
ClipString=2
ClipStringW=150
Group=Hidethis


[Serial7_8]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#+247)
Y=4R
Text="7.8. "
Group=Hidethis

[meterUploadLabel]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=190
H=14
Text=Upload
Group=Hidethis

[meterUploadValue]
Meter=String
MeterStyle=StyleBoldRight
X=(#widthtoggle#+462)
Y=0r
W=190
H=14
MeasureName=measureNetOut
Text=%1B/s
NumOfDecimals=1
AutoScale=1
Group=Hidethis

[meterUploadBar]
Meter=Bar
MeterStyle=styleBar
MeasureName=measureNetOut
X=(#widthtoggle#+268)
Y=0R
W=195
H=1
Group=Hidethis

[Serial7_9]
Meter=String
MeterStyle=StyleLeft
X=(#widthtoggle#+247)
Y=4R
Text="7.9. "
Group=Hidethis

[meterDownloadLabel]
Meter=String
MeterStyle=StyleBoldLeft
X=4R
Y=0r
W=190
H=14
Text=Download
Group=Hidethis

[meterDownloadValue]
Meter=String
MeterStyle=StyleBoldRight
X=(#widthtoggle#+462)
Y=0r
W=190
H=14
MeasureName=measureNetIn
Text=%1B/s
NumOfDecimals=1
AutoScale=1
Group=Hidethis

[meterDownloadBar]
Meter=Bar
MeterStyle=styleBar
X=(#widthtoggle#+268)
Y=0R
W=195
H=1
MeasureName=measureNetIn
Group=Hidethis