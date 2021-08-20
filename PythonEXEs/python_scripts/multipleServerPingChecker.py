from sys import exit
import os,time
import getopt, sys
import platform, socket, subprocess
import re, json
# import logging
from urllib.request import urlopen
from shlex import quote

iniToRead = ""
callIntervalSeconds = ""
pingFilesPath = ""
internetConnected = ""
loadServerDetails = False
loadServerData = ""

# logging.basicConfig(filename='C:/errorMultiple.log', level=logging.DEBUG, format='%(asctime)s %(levelname)s %(name)s %(message)s')
# logger=logging.getLogger(__name__)
# logger.info(" ".join(quote(arg) for arg in sys.argv))

argumentList = sys.argv[1:] # Remove 1st argument from the list of command line arguments
options = "i:c:p:n:s:l" # Options
long_options = ["iniToRead =", "CallIntervalSeconds =", "PingFilesPath =", "InternetConnected =", "serverDetails =", "loadServerDetails"] # Long options
 
try:
    arguments, values = getopt.getopt(argumentList, options, long_options) # Parsing argument
    for currentArgument, currentValue in arguments: # checking each argument
        if currentArgument.strip() in ("-i", "--iniToRead"):
            iniToRead = currentValue
        elif currentArgument.strip() in ("-c", "--CallIntervalSeconds"):
            callIntervalSeconds = int(currentValue)
        elif currentArgument.strip() in ("-p", "--PingFilesPath"):
            pingFilesPath = currentValue
        elif currentArgument.strip() in ("-n", "--InternetConnected"):
            internetConnected = int(currentValue)
        elif currentArgument.strip() in ("-s", "--serverDetails"):
            loadServerData = currentValue
        elif currentArgument.strip() in ("-l", "--loadServerDetails"):
            loadServerDetails = True
except getopt.error as err:
    # logger.error(err)
    print (str(err)) # output error, and return with an error code
except Exception as ex:
    # logger.error(ex)
    print("Got error: "+ex)
    exit(0)

if (iniToRead == "") or (pingFilesPath == ""):
    print("One of the required arguments iniToRead, pingFilesPath missing.")
    exit(0)


if loadServerDetails:
    loadServerData = []
    loadServerData.append("Localhost:127.0.0.1,0,0,0")
    with open(iniToRead) as iniToReadHandle:
        for line in iniToReadHandle:
            if (not line.startswith("#")) and "=" in line:
                serverNameAndAddress = line.split("=")
                serverName = serverNameAndAddress[0].strip()
                serverAddress = serverNameAndAddress[1].strip()
                isInternetRequired = int(serverNameAndAddress[2].strip())
                
                pingFile=pingFilesPath+serverName+".txt"

                if not os.path.exists(pingFile):
                    os.makedirs(os.path.dirname(pingFile), exist_ok=True)
                    pingFileHandle = open(pingFile,"w+")    
                    initData = ["0\n0\n"]
                    pingFileHandle.writelines(initData)
                    pingFileHandle.close()
                    
                pingFileHandle = open(pingFile,"r")
                pingMSTotal = int(pingFileHandle.readline().strip())
                pingCnt = int(pingFileHandle.readline().strip())
                pingFileHandle.close()
                
                loadServerData.append(serverName+":"+serverAddress+","+str(isInternetRequired)+","+str(pingMSTotal)+","+str(pingCnt))
                
    loadServerData = "{:-:}".join(loadServerData)
    print("|||||"+loadServerData)
else:
    if (callIntervalSeconds == "") or (internetConnected == ""):
        print("One of the required arguments callIntervalSeconds, internetConnected missing.")
        exit(0)
    if loadServerData == "":
        print("No Load Server Data Provided.")
        exit(0)
    
    serversList = loadServerData.split("{:-:}")
    localhostPingCnt = 0
    for listCnt in range(len(serversList)):
        try:
            serverDetails = serversList[listCnt].split(":")
            serverName = serverDetails[0].strip()
            serverOtherDetails = serverDetails[1].strip()
            serverOtherDetails = serverOtherDetails.split(",")
            serverAddress = serverOtherDetails[0].strip()
            isInternetRequired = int(serverOtherDetails[1].strip())
            serverPingMSTotal = int(serverOtherDetails[2].strip())
            serverPingCnt = int(serverOtherDetails[3].strip())
        except:
            # logger.error(err)
            print(serversList[listCnt])
            exit(0)

        if listCnt == 0:
            localhostPingCnt = serverPingCnt

        print(serverName+":", end="")

        if isInternetRequired == 1 and (internetConnected != 1 and internetConnected != 2):
            print("4")
            continue

        try:
            output = subprocess.check_output(["ping", serverAddress, "-n", "1", "-w", "1000"])
        except subprocess.CalledProcessError as exc:
            output = exc.output

        pingReply = output.decode().split('\n')
        if len(pingReply) >= 3:
            pingReply = pingReply[2]
            if bool(re.search("Reply from(.+)bytes(.+)time(.+)TTL=(.+)", pingReply)):
                totalMS = re.search("time.(.*)ms", pingReply)
                try:
                    totalMS = int(totalMS.group(1))
                except Exception as exc:
                    # logger.error(exc)
                    print("Found Exception, Reply is:"+pingReply)
                if (serverPingCnt == 0) or (totalMS <= serverPingMSTotal/serverPingCnt):
                    print("1")
                else:
                    print("2")
                serverPingMSTotal=serverPingMSTotal+int(totalMS)
                serverPingCnt=serverPingCnt+1
                loadServerData = re.sub(r'(?is)'+serverName+":(.*?),(.),(\d+),(\d+)", serverName+":"+serverAddress+","+str(isInternetRequired)+","+str(serverPingMSTotal)+","+str(serverPingCnt), loadServerData)
            else:
                print("3")
        else:
            print("3")            
    # intervalForWrite = (1 * 10 * 60) / callIntervalSeconds # write files every 10 mins
    intervalForWrite = (4 * 60 * 60) / callIntervalSeconds # write files every 4 hours
    intervalForWrite = int(round(intervalForWrite, 0))
    if not localhostPingCnt == 0 and localhostPingCnt % intervalForWrite == 0:
        for listCnt in range(len(serversList)):
            if listCnt == 0:
                continue
            serverNameAndDetails = serversList[listCnt].split(":")
            serverName = serverNameAndDetails[0].strip()
            serverDetails = serverNameAndDetails[1].strip().split(",")
                
            pingFile=pingFilesPath+serverName+".txt"

            fileWritePingMSTotal = int(serverDetails[2])
            fileWritePingCnt = int(serverDetails[3])

            pingFileHandle = open(pingFile,"w")
            pingFileHandle.writelines(str(fileWritePingMSTotal)+'\n')
            pingFileHandle.writelines(str(fileWritePingCnt)+'\n')
            pingFileHandle.close()
    print("|||||"+loadServerData)
