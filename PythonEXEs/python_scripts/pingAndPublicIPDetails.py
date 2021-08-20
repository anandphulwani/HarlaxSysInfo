from sys import exit
import os,time
import getopt, sys
import platform, socket, subprocess
import re, json
# import logging
from urllib.request import urlopen
from shlex import quote

icmpServers=["1.1.1.1",
"1.0.0.1",
"8.8.8.8",
"8.8.4.4",
"4.2.2.2",
"208.67.222.222",
"208.67.220.220",
"198.153.192.1",
"198.153.194.2",
# "205.210.42.205",
# "64.68.200.200",
"139.130.4.5",
"198.41.0.4",
"199.9.14.201",
"192.33.4.12",
"199.7.91.13",
"192.203.230.10",
"192.5.5.241",
# "192.112.36.4",
"198.97.190.53",
"192.36.148.17",
"192.58.128.30",
"193.0.14.129",
"199.7.83.42",
"202.12.27.33"]

callIntervalSeconds = 1
pingFilesPath = "./"
totalMS = 0
loadServerDetails = False
loadServerData = ""

# logging.basicConfig(filename='C:/errorPingAndPublicIP.log', level=logging.DEBUG, format='%(asctime)s %(levelname)s %(name)s %(message)s')
# logger=logging.getLogger(__name__)
# logger.info(" ".join(quote(arg) for arg in sys.argv))

argumentList = sys.argv[1:] # Remove 1st argument from the list of command line arguments
options = "c:p:s:l" # Options
long_options = ["CallIntervalSeconds =", "PingFilesPath =", "loadServerDetails", "serverDetails ="] # Long options
 
try:
    arguments, values = getopt.getopt(argumentList, options, long_options) # Parsing argument
    for currentArgument, currentValue in arguments: # checking each argument
        #print("currentArgument:"+currentArgument)
        #print("currentValue:"+currentValue)
        if currentArgument.strip() in ("-c", "--CallIntervalSeconds"):
            callIntervalSeconds = int(currentValue)
        elif currentArgument.strip() in ("-p", "--PingFilesPath"):
            pingFilesPath = currentValue
        elif currentArgument.strip() in ("-s", "--serverDetails"):
            loadServerData = currentValue
        elif currentArgument.strip() in ("-l", "--loadServerDetails"):
            loadServerDetails = True
except getopt.error as err:
    # logger.error(err)
    print (str(err)) # output error, and return with an error code

if loadServerDetails:
    loadServerData = []
    for icmpServer in icmpServers:
        pingFile=pingFilesPath+icmpServer+".txt"

        if not os.path.exists(pingFile):
            os.makedirs(os.path.dirname(pingFile), exist_ok=True)
            pingFileHandle = open(pingFile,"w+")    
            initData = ["0\n0\n"]
            pingFileHandle.writelines(initData)
            pingFileHandle.close()

        pingFileHandle = open(pingFile,"r")
        pingMSTotal = pingFileHandle.readline().strip()
        pingCnt = pingFileHandle.readline().strip()
        loadServerData.append(icmpServer+":"+pingMSTotal+","+pingCnt)
        pingFileHandle.close()
    print ("{:-:}".join(loadServerData))
else:
    if loadServerData == "":
        print("No Load Server Data Provided.")
        exit(0)
        
    icmpServersCount = len(icmpServers) # print (icmpServersCount)
    icmpServersSequence = (int(time.time()/callIntervalSeconds)) % icmpServersCount # print (icmpServersSequence)

    serverPingMSTotalAndCnt = re.search(icmpServers[icmpServersSequence]+":(\d+),(\d+)", loadServerData)
    serverPingMSTotal = int(serverPingMSTotalAndCnt.group(1))
    serverPingCnt = int(serverPingMSTotalAndCnt.group(2))

    try:
        output = subprocess.check_output(["ping", icmpServers[icmpServersSequence], "-n", "1", "-w", "1000"])
    except subprocess.CalledProcessError as exc:
        output = exc.output
        
    # PING: transmit failed. General failure.
    # Request timed out.
    # Reply from 192.203.230.10: bytes=32 time=20ms TTL=59
    outputToPrint="3"
    pingReply = output.decode().split('\n')
    if len(pingReply) >= 3:
        pingReply = pingReply[2]
    else:
        pingReply = ""
    if pingReply.startswith("Reply from "):
        totalMS = re.search("time.(.*)ms", pingReply)
        totalMS = int(totalMS.group(1))
        if (serverPingCnt == 0) or (totalMS <= serverPingMSTotal/serverPingCnt):
            outputToPrint="1"
        else:
            outputToPrint="2"
        serverPingMSTotal=serverPingMSTotal+int(totalMS)
        serverPingCnt=serverPingCnt+1

        loadServerData = re.sub(r'(?is)'+icmpServers[icmpServersSequence]+":(\d+),(\d+)", icmpServers[icmpServersSequence]+":"+str(serverPingMSTotal)+","+str(serverPingCnt), loadServerData)

        # intervalForWrite = (1 * 30 * 60) / callIntervalSeconds # write files every 30 mins
        intervalForWrite = (4 * 60 * 60) / callIntervalSeconds # write files every 4 hours
        intervalForWrite = int(round(intervalForWrite, 0))
        intervalForWrite = int(round((intervalForWrite / icmpServersCount), 0))
        
        if icmpServersSequence == 0 and (serverPingCnt % intervalForWrite == 0):
            for icmpServer in icmpServers:
                pingFile=pingFilesPath+icmpServer+".txt"

                fileWritePingMSTotalAndCnt = re.search(icmpServer+":(\d+),(\d+)", loadServerData)
                fileWritePingMSTotal = int(fileWritePingMSTotalAndCnt.group(1))
                fileWritePingCnt = int(fileWritePingMSTotalAndCnt.group(2))

                pingFileHandle = open(pingFile,"w")
                pingFileHandle.writelines(str(fileWritePingMSTotal)+'\n')
                pingFileHandle.writelines(str(fileWritePingCnt)+'\n')
                pingFileHandle.close()

    publicIP = ""
    isp_string = ""

    if outputToPrint != "3":
        urlHandle = urlopen("https://checkip.amazonaws.com/")
        publicIP = urlHandle.read().decode('utf-8').strip()

        ispHandle = urlopen('http://ip-api.com/json/'+publicIP)
        json_string = ispHandle.read().decode('utf-8')
        json_obj = json.loads(json_string)
        isp_string = json_obj['as'].split(" ")
        isp_string.pop(0)
        isp_string = (" ".join(isp_string)).title()
    print(loadServerData +"|||||"+outputToPrint+"{:-:}"+publicIP+"{:-:}"+isp_string)
