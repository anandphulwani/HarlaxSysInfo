from sys import exit
import os,os.path,time
import getopt, sys
import platform, socket, subprocess
import re, json
from urllib.request import urlopen

iniToRead = ""
meterFile = ""
measureFile = "" 


argumentList = sys.argv[1:] # Remove 1st argument from the list of command line arguments
options = "i:t:a:" # Options
long_options = ["iniToRead =", "meterFile =", "measureFile ="] # Long options
 
try:
    arguments, values = getopt.getopt(argumentList, options, long_options) # Parsing argument
    for currentArgument, currentValue in arguments: # checking each argument
        #print("currentArgument:"+currentArgument)
        #print("currentValue:"+currentValue)
        if currentArgument.strip() in ("-i", "--iniToRead"):
            iniToRead = currentValue
        elif currentArgument.strip() in ("-t", "--meterFile"):
            meterFile = currentValue
        elif currentArgument.strip() in ("-a", "--measureFile"):
            measureFile = currentValue
except getopt.error as err:
    print (str(err)) # output error, and return with an error code

if (iniToRead == "") or (meterFile == "") or (measureFile == ""):
    print("One of the required arguments iniToRead, meterFile, measureFile missing.")
    exit(0)

if not os.path.isfile(iniToRead):
    print("Input iniToRead file not found.")
    exit(0)


iniToReadModifiedTime = 0
meterFileModifiedTime = 0
measureFileModifiedTime = 0

if os.path.isfile(iniToRead):
    iniToReadModifiedTime = int(os.path.getmtime(iniToRead))
if os.path.isfile(meterFile):
    meterFileModifiedTime = int(os.path.getmtime(meterFile))
if os.path.isfile(measureFile):
    measureFileModifiedTime = int(os.path.getmtime(measureFile))
    
if (iniToReadModifiedTime > meterFileModifiedTime) or (iniToReadModifiedTime > measureFileModifiedTime):
    serversList = []
    with open(iniToRead) as iniToReadHandle:
        for line in iniToReadHandle:
            if (not line.startswith("#")) and "=" in line:
                serversList.append(line)

    measureFileHandle = open(measureFile, "w")
    meterFileHandle = open(meterFile, "w")

    measureFileHandle.write(";--------------------------------------------------------------------------------------------------------------------------------------\n")
    measureFileHandle.write("[measureLoadServersPingDetails]\n")
    measureFileHandle.write("Measure=Plugin\n")
    measureFileHandle.write("Plugin=RunCommand\n")
    measureFileHandle.write("Parameter=#ROOTCONFIGPATH#/PythonEXEs/multipleServerPingChecker.exe -i \"../ServersToPing.ini\" -p #ROOTCONFIGPATH#/PingFiles/CheckServerConnectivity/ -l\n")
    measureFileHandle.write("State=Hide\n")
    measureFileHandle.write("OutputType=UTF8\n")
    measureFileHandle.write("FinishAction=[!SetVariable \"initServersPingDetails\" \"[measureLoadServersPingDetails]\"][!EnableMeasure \"measureUpdateLoadServersPingDetails\"][!UpdateMeasure \"measureUpdateLoadServersPingDetails\"]\n")
    measureFileHandle.write("UpdateDivider=-1\n")
    measureFileHandle.write("DynamicVariables=1\n\n")

    measureFileHandle.write("[measureUpdateLoadServersPingDetails]\n")
    measureFileHandle.write("Measure=String\n")
    measureFileHandle.write("String=#initServersPingDetails#\n")
    measureFileHandle.write("RegExpSubstitute=1\n")
    measureFileHandle.write("Substitute=\"(?s)(.*)\|\|\|\|\|(.*)\":\"\\2\",\"^(\s+)\":\"\",\"(\s+)$\":\"\",\"([[:blank:]][[:blank:]]+)\":\" \",\"\\\\2\":\"\"\n")
    measureFileHandle.write("OnUpdateAction=[!SetVariable \"loadServersPingDetails\" \"[measureUpdateLoadServersPingDetails]\"]\n")
    measureFileHandle.write("UpdateDivider=-1\n")
    measureFileHandle.write("DynamicVariables=1\n")
    measureFileHandle.write("Disabled=1\n")
    measureFileHandle.write(";--------------------------------------------------------------------------------------------------------------------------------------\n\n")


    measureFileHandle.write("[measureServerPingDetailsDataError101Checker]\n")
    measureFileHandle.write("Measure=String\n")
    measureFileHandle.write("String=#isServerPingDetailsDataError101#\n")
    measureFileHandle.write("IfMatch=^0$\n")
    measureFileHandle.write("IfMatchAction=[!SetVariable \"isServerPingDetailsDataError101\" 1][!UpdateMeasure \"measureServerPingDetailsData\"][!CommandMeasure \"measureServerPingDetailsData\" \"Run\"]\n")
    measureFileHandle.write("IfMatchMode=1\n")
    measureFileHandle.write("UpdateDivider=-1\n")
    measureFileHandle.write("DynamicVariables=1\n")
    measureFileHandle.write("Disabled=1\n\n")

    measureFileHandle.write("[measureServerPingDetailsData]\n")
    measureFileHandle.write("Measure=Plugin\n")
    measureFileHandle.write("Plugin=RunCommand\n")
    measureFileHandle.write("Parameter=#ROOTCONFIGPATH#/PythonEXEs/multipleServerPingChecker.exe -i \"../ServersToPing.ini\" -c #internetConnCheckInterval# -p #ROOTCONFIGPATH#/PingFiles/CheckServerConnectivity/ -n #isInternetConnected# -s #loadServersPingDetails#\n")
    measureFileHandle.write("State=Hide\n")
    measureFileHandle.write("OutputType=UTF8\n")
    measureFileHandle.write("FinishAction=[!SetVariable \"isServerPingDetailsDataError101\" 0][!SetVariable \"initServersPingDetails\" \"[measureServerPingDetailsData]\"][!UpdateMeasure \"measureUpdateLoadServersPingDetails\"][!UpdateMeasure \"measureServerPingDetailsDataSub1\"]\n")
    measureFileHandle.write("UpdateDivider=-1\n")
    measureFileHandle.write("DynamicVariables=1\n\n")

    measureFileHandle.write("[measureServerPingDetailsDataSub1]\n")
    measureFileHandle.write("Measure=String\n")
    measureFileHandle.write("String=[measureServerPingDetailsData]\n")
    measureFileHandle.write("RegExpSubstitute=1\n")
    measureFileHandle.write("Substitute=\"(?s)(.*)\|\|\|\|\|(.*)\":\"\\1\",\"([[:blank:]][[:blank:]]+)\":\" \",\"\\\\1\":\"\"\n")
    measureFileHandle.write("OnUpdateAction=[!SetVariable \"serverPingDetailsData\" \"[measureServerPingDetailsDataSub1]\"]")
    for count in range(len(serversList)):
        measureFileHandle.write("[!UpdateMeasure \"measureServer"+str(count+1)+"\"]")
    measureFileHandle.write("\n")
    measureFileHandle.write("UpdateDivider=-1\n")
    measureFileHandle.write("DynamicVariables=1\n\n")

    measureFileHandle.write("[measureSetServerStatusToNull]\n")
    measureFileHandle.write("Measure=String\n")
    measureFileHandle.write("String=\n")
    measureFileHandle.write("OnUpdateAction=[!SetVariable \"serverPingDetailsData\" \"")
    for listCnt in range(len(serversList)):
        serverNameAndAddress = serversList[listCnt].split("=")
        serverName = serverNameAndAddress[0].strip()
        measureFileHandle.write(serverName+":-2[\\13][\\10]")
    measureFileHandle.write("\"]")
    for count in range(len(serversList)):
        measureFileHandle.write("[!UpdateMeasure \"measureServer"+str(count+1)+"\"]")
    measureFileHandle.write("\n")
    measureFileHandle.write("UpdateDivider=-1\n")
    measureFileHandle.write("DynamicVariables=1\n\n")


    meterFileHandle.write("[meterServerStatusTitle]\n")
    meterFileHandle.write("Meter=String\n")
    meterFileHandle.write("MeterStyle=StyleBoldLeft\n")
    meterFileHandle.write("X=(#widthtoggle#+310)\n")
    meterFileHandle.write("Y=0R\n")
    meterFileHandle.write("W=182\n")
    meterFileHandle.write("H=18\n")
    meterFileHandle.write("Text=\"Server Status\"\n")
    meterFileHandle.write("Group=Hidethis\n\n")

    for listCnt in range(len(serversList)):
        # print(serversList[listCnt])
        serverNameAndAddress = serversList[listCnt].split("=")
        serverName = serverNameAndAddress[0].strip()
        serverAddress = serverNameAndAddress[1].strip()
        count=listCnt+1

        measureFileHandle.write("[measureServer"+str(count)+"]\n")
        measureFileHandle.write("Measure=String\n")
        measureFileHandle.write("String=#serverPingDetailsData#\n")
        measureFileHandle.write("RegExpSubstitute=1\n")    
        measureFileHandle.write("Substitute=\"(?s).*"+serverName+":(.*?\\n).*\":\"\\1\",\"(#CRLF#+)\":\"\",\"^(\s+)\":\"\",\"(\s+)$\":\"\",\"([[:blank:]][[:blank:]]+)\":\" \",\"-2\":\"\",\"1\":\"Online\",\"2\":\"Online(Lag)\",\"3\":\"Offline\",\"4\":\"No Internet\"\n")
        measureFileHandle.write("OnUpdateAction=[!UpdateMeasure \"measureServer"+str(count)+"UpdateIcon\"]\n")
        measureFileHandle.write("UpdateDivider=-1\n")
        measureFileHandle.write("DynamicVariables=1\n\n")

        measureFileHandle.write("[measureServer"+str(count)+"UpdateIcon]\n")
        measureFileHandle.write("Measure=String\n")
        measureFileHandle.write("String=[measureServer"+str(count)+"]\n")
        measureFileHandle.write("IfMatch=^Online\(Lag\)$\n")
        measureFileHandle.write("IfMatchAction=[!SetOption meterServer"+str(count)+"Image ImageName Warning.png][!UpdateMeter meterServer"+str(count)+"Image]")
        if listCnt+1 != len(serversList):
            measureFileHandle.write("\n")
        else:
            measureFileHandle.write("[!Redraw]\n")        
        measureFileHandle.write("IfMatch2=^Online$\n")
        measureFileHandle.write("IfMatchAction2=[!SetOption meterServer"+str(count)+"Image ImageName Online.png][!UpdateMeter meterServer"+str(count)+"Image]")
        if listCnt+1 != len(serversList):
            measureFileHandle.write("\n")
        else:
            measureFileHandle.write("[!Redraw]\n")        
        measureFileHandle.write("IfMatch3=^Offline$\n")
        measureFileHandle.write("IfMatchAction3=[!SetOption meterServer"+str(count)+"Image ImageName Offline.png][!UpdateMeter meterServer"+str(count)+"Image]")
        if listCnt+1 != len(serversList):
            measureFileHandle.write("\n")
        else:
            measureFileHandle.write("[!Redraw]\n")        
        measureFileHandle.write("IfMatch4=^No Internet$|^$\n")
        measureFileHandle.write("IfMatchAction4=[!SetOption meterServer"+str(count)+"Image ImageName \"\"][!UpdateMeter meterServer"+str(count)+"Image]")
        if listCnt+1 != len(serversList):
            measureFileHandle.write("\n")
        else:
            measureFileHandle.write("[!Redraw]\n")        

        measureFileHandle.write("UpdateDivider=-1\n")
        measureFileHandle.write("DynamicVariables=1")
        if listCnt+1 != len(serversList):
            measureFileHandle.write("\n\n")
            
        meterFileHandle.write("[meterServer"+str(count)+"Image]\n")
        meterFileHandle.write("Meter=Image\n")
        meterFileHandle.write("X=(#widthtoggle#+247)\n")
        if count == 1:
            meterFileHandle.write("Y=0R\n")
        else:
            meterFileHandle.write("Y=4R\n")
        meterFileHandle.write("W=10\n")
        meterFileHandle.write("H=10\n")
        meterFileHandle.write("Group=Hidethis\n\n")

        meterFileHandle.write("[meterServer"+str(count)+"]\n")
        meterFileHandle.write("Meter=String\n")
        meterFileHandle.write("MeterStyle=StyleBoldLeft\n")
        meterFileHandle.write("X=10R\n")
        meterFileHandle.write("Y=-2r\n")
        meterFileHandle.write("MeasureName=measureServer"+str(count)+"\n")
        meterFileHandle.write("Text=\""+serverName+": %1\"\n")
        meterFileHandle.write("Group=Hidethis\n\n")

    measureFileHandle.close()
    meterFileHandle.close()
    
    print("1")
else:
    print("0")
