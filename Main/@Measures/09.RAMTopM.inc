[measureTopUsage1RAM]
Measure=Plugin
Plugin=UsageMonitor
Alias=RAM
Percent=0
Index=1
Substitute="":"."
Group=NonOverview

[measureTopUsage2RAM]
Measure=Plugin
Plugin=UsageMonitor
Alias=RAM
Percent=0
Index=2
Substitute="":"."
Group=NonOverview

[measureTopUsage3RAM]
Measure=Plugin
Plugin=UsageMonitor
Alias=RAM
Percent=0
Index=3
Substitute="":"."
Group=NonOverview

[measureTopUsage4RAM]
Measure=Plugin
Plugin=UsageMonitor
Alias=RAM
Percent=0
Index=4
Substitute="":"."
Group=NonOverview

[measureTopUsage5RAM]
Measure=Plugin
Plugin=UsageMonitor
Alias=RAM
Percent=0
Index=5
Substitute="":"."
Group=NonOverview

[measureTopUsage6RAM]
Measure=Plugin
Plugin=UsageMonitor
Alias=RAM
Percent=0
Index=6
Substitute="":"."
Group=NonOverview

;---------------------------------------------- Calcs ----------------------------------------------

[CalcTopMemory1RAM]
Measure=Calc
Formula=MeasureTopUsage1RAM
Group=Process1
Group=NonOverview

[CalcTopMemory2RAM]
Measure=Calc
Formula=MeasureTopUsage2RAM
Group=Process2
Group=NonOverview

[CalcTopMemory3RAM]
Measure=Calc
Formula=MeasureTopUsage3RAM
Group=Process3
Group=NonOverview

[CalcTopMemory4RAM]
Measure=Calc
Formula=MeasureTopUsage4RAM
Group=Process4
Group=NonOverview

[CalcTopMemory5RAM]
Measure=Calc
Formula=MeasureTopUsage5RAM
Group=Process5
Group=NonOverview

[CalcTopMemory6RAM]
Measure=Calc
Formula=MeasureTopUsage6RAM
Group=Process6
Group=NonOverview
