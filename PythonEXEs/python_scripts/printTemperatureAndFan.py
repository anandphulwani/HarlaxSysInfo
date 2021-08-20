import clr #package pythonnet, not clr
import time, math
import os

openhardwaremonitor_hwtypes = ['Mainboard','SuperIO','CPU','RAM','GpuNvidia','GpuAti','TBalancer','Heatmaster','HDD']
cputhermometer_hwtypes = ['Mainboard','SuperIO','CPU','GpuNvidia','GpuAti','TBalancer','Heatmaster','HDD']
openhardwaremonitor_sensortypes = ['Voltage','Clock','Temperature','Load','Fan','Flow','Control','Level','Factor','Power','Data','SmallData']
cputhermometer_sensortypes = ['Voltage','Clock','Temperature','Load','Fan','Flow','Control','Level']


def initialize_openhardwaremonitor():
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
    for i in handle.Hardware:
        i.Update()
        for sensor in i.Sensors:
            parse_sensor(sensor, i, i)
        for j in i.SubHardware:
            j.Update()
            for subsensor in j.Sensors:
                parse_sensor(subsensor, i, j)

def parse_sensor(sensor, i, j):
        if sensor.Value is not None:
            if type(sensor).__module__ == 'CPUThermometer.Hardware':
                sensortypes = cputhermometer_sensortypes
                hardwaretypes = cputhermometer_hwtypes
            elif type(sensor).__module__ == 'OpenHardwareMonitor.Hardware':
                sensortypes = openhardwaremonitor_sensortypes
                hardwaretypes = openhardwaremonitor_hwtypes
            else:
                return

            if sensor.SensorType == sensortypes.index('Temperature') or sensor.SensorType == sensortypes.index('Fan'):
                print()
                print(".".join([i.__class__.__module__, i.__class__.__name__]))
                print(".".join([j.__class__.__module__, j.__class__.__name__]))
                print(".".join([sensor.__class__.__module__, sensor.__class__.__name__]))
                print(sensortypes[sensor.SensorType])
                print(u"%s %s Temperature Sensor #%i %s - %s\u00B0C" % (hardwaretypes[sensor.Hardware.HardwareType], sensor.Hardware.Name, sensor.Index, sensor.Name, sensor.Value))
            #if sensor.SensorType == sensortypes.index('Fan'):
            #   print()
            #   print(u"%s %s Temperature Sensor #%i %s - %s" % (hardwaretypes[sensor.Hardware.HardwareType], sensor.Hardware.Name, sensor.Index, sensor.Name, sensor.Value))

if __name__ == "__main__":   
    HardwareHandle = initialize_openhardwaremonitor()
    fetch_stats(HardwareHandle)
    
