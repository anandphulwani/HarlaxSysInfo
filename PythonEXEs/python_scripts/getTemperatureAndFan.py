import clr #package pythonnet, not clr
import time, math
import os

cpuTemp = ""
moboTemp = ""
gpuTemp = ""
hddTemp = []
cpuFan = ""
otherFan = ""


openhardwaremonitor_hwtypes = ['Mainboard','SuperIO','CPU','RAM','GpuNvidia','GpuAti','TBalancer','Heatmaster','HDD']
cputhermometer_hwtypes = ['Mainboard','SuperIO','CPU','GpuNvidia','GpuAti','TBalancer','Heatmaster','HDD']
openhardwaremonitor_sensortypes = ['Voltage','Clock','Temperature','Load','Fan','Flow','Control','Level','Factor','Power','Data','SmallData']
cputhermometer_sensortypes = ['Voltage','Clock','Temperature','Load','Fan','Flow','Control','Level']


def initialize_openhardwaremonitor():
    # file = 'D:\\Data\\Users\\User\\Downloads\\OpenHardwareMonitorReport\\OpenHardwareMonitorLib.dll'
    file = 'OpenHardwareMonitorLib'
    clr.AddReference(file)

    from OpenHardwareMonitor import Hardware

    handle = Hardware.Computer()
    handle.MainboardEnabled = True
    handle.CPUEnabled = True
    handle.RAMEnabled = True
    handle.GPUEnabled = True
    handle.HDDEnabled = True
    handle.Open()
    return handle

def fetch_stats(handle):
    #print(type(handle))
    #print(type(handle.Hardware))
    for i in handle.Hardware:
        i.Update()
        for sensor in i.Sensors:
            #print(type(sensor))
            parse_sensor(sensor, i)
        for j in i.SubHardware:
            j.Update()
            for subsensor in j.Sensors:
                parse_sensor(subsensor, i)


def parse_sensor(sensor, i):
        global cpuTemp, moboTemp, gpuTemp, hddTemp, cpuFan, otherFan
        if sensor.Value is not None:
            if type(sensor).__module__ == 'CPUThermometer.Hardware':
                sensortypes = cputhermometer_sensortypes
                hardwaretypes = cputhermometer_hwtypes
            elif type(sensor).__module__ == 'OpenHardwareMonitor.Hardware':
                sensortypes = openhardwaremonitor_sensortypes
                hardwaretypes = openhardwaremonitor_hwtypes
            else:
                return

            className = ".".join([i.__class__.__module__, i.__class__.__name__])
            if sensor.SensorType == sensortypes.index('Temperature'):
                if cpuTemp == "" and ".Mainboard." in className and "CPU" in sensor.Name:
                    cpuTemp = str(round(int(sensor.Value),0)) + '\u00B0' + " C"
                elif cpuTemp == "" and ".CPU." in className and "CPU" in sensor.Name:
                    cpuTemp = str(round(int(sensor.Value),0)) + '\u00B0' + " C"
                elif moboTemp == "" and ".Mainboard." in className and not "CPU" in sensor.Name:
                    moboTemp = str(round(int(sensor.Value),0)) + '\u00B0' + " C"
                elif gpuTemp == "" and ("GPU" in className or "Gpu" in className) and "Temperature" in sensor.Name:
                    gpuTemp = str(round(int(sensor.Value),0)) + '\u00B0' + " C"
                elif ".HDD." in className and "Temperature" in sensor.Name:
                    hddValue = sensor.Hardware.Name
                    if round(int(sensor.Value),0) != 0:
                        hddValue += " ("+str(round(int(sensor.Value),0)) + '\u00B0' + " C)"
                    hddTemp.append(hddValue)
            elif sensor.SensorType == sensortypes.index('Fan'):
                if cpuFan == "" and "Fan" in sensor.Name:
                    cpuFan = str(math.trunc(int(sensor.Value))) + " RPM"
                elif cpuFan != "" and otherFan == "" and "Fan" in sensor.Name:
                    otherFan = str(math.trunc(int(sensor.Value))) + " RPM"
                # if sensor.SensorType == sensortypes.index('Temperature'):
                #   print(".".join([i.__class__.__module__, i.__class__.__name__]))
                #   print(u"%s %s Temperature Sensor #%i %s - %s\u00B0C" % (hardwaretypes[sensor.Hardware.HardwareType], sensor.Hardware.Name, sensor.Index, sensor.Name, sensor.Value))
                # if sensor.SensorType == sensortypes.index('Fan'):
                #    print()
                #    print(u"%s %s Temperature Sensor #%i %s - %s" % (hardwaretypes[sensor.Hardware.HardwareType], sensor.Hardware.Name, sensor.Index, sensor.Name, sensor.Value))

if __name__ == "__main__":   
    HardwareHandle = initialize_openhardwaremonitor()
    fetch_stats(HardwareHandle)
    
    if cpuTemp == ("0" + '\u00B0' + " C"):
        cpuTemp = ""
    if moboTemp == ("0" + '\u00B0' + " C"):
        moboTemp = ""
    if gpuTemp == ("0" + '\u00B0' + " C"):
        gpuTemp = ""
    if cpuFan == "0 RPM":
        cpuFan = ""
    if otherFan == "0 RPM":
        otherFan = ""
        
    print(cpuTemp+" , "+moboTemp+" , "+gpuTemp+" , "+(" ; ".join(hddTemp))+" , "+cpuFan+" , "+otherFan+" ")
    
