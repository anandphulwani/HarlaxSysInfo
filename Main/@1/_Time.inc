
[Title]
Meter=String
X=#In#
Y=10R
MeasureName=MeasureComputerName
MeasureName2=MeasureUsername
FontColor=#Accent#
Text=%1 %2
FontSize=(24*(#Scale#/20))
FontWeight=#FontWeight#
MeterStyle=Text
InlinePattern=\s(.*)
InlineSetting=Size | (#Scale#+8)
MiddleMouseUpAction=[!Refresh]
UpdateDivider=-1

[TimeDate]
Meter=String
MeasureName=MeasureTime
MeasureName2=MeasureDate
Text=%1 %2 
MeterStyle=Text

[PrductInfo]
Meter=String
MeasureName=MeasureProductName
MeasureName2=MeasureOSBits
MeasureName3=Measureversion
MeasureName4=MeasureCurrentBuild
MeasureName5=MeasureUBR
Text=%1 %2 bits %3 %4.%5
InlineSetting=Color | #BarColor#
InlinePattern=bits(.*)
MeterStyle=Text
UpdateDivider=-1