[meterCPUTopTitle]
Meter=String
MeterStyle=StyleBoldLeft
X=(#widthtoggle#+310)
Y=0R
W=182
H=18
Text="CPU Top 5 Process"
Group=Hidethis

[CPUtopitem]
Meter=String
MeterStyle=StyleBoldLeft
X=(#widthtoggle#+247)
Y=0R
W=(#Scale#*10)+50
MeasureName=MeasureTopUsage1CPU
MeasureName2=MeasureTopUsage2CPU
MeasureName3=MeasureTopUsage3CPU
MeasureName4=MeasureTopUsage4CPU
MeasureName5=MeasureTopUsage5CPU
MeasureName6=MeasureTopUsage6CPU
Text=%1#CRLF#%2#CRLF#%3#CRLF#%4#CRLF#%5#CRLF#%6
ClipString=1
Group=Hidethis

[CPUtopused]
Meter=String
MeterStyle=StyleBoldRight
X=5R
Y=0r
W=(#Scale#*4)
Text=[MeasureTopUsage1CPU:1]%#CRLF#[MeasureTopUsage2CPU:1]%#CRLF#[MeasureTopUsage3CPU:1]%#CRLF#[MeasureTopUsage4CPU:1]%#CRLF#[MeasureTopUsage5CPU:1]%#CRLF#[MeasureTopUsage6CPU:1]%#CRLF#
DynamicVariables=1
NumOfDecimals=1
ClipString=1
Group=Hidethis
