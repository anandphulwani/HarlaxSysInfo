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