#!/usr/bin/env python

import platform
import socket
import subprocess


def is_valid_ipv4_address(address):
    try:
        socket.inet_pton(socket.AF_INET, address)
    except AttributeError:  # no inet_pton here, sorry
        try:
            socket.inet_aton(address)
        except socket.error:
            return False
        return address.count('.') == 3
    except socket.error:  # not a valid address
        return False

    return True

def main():
    output = subprocess.check_output(["ipconfig", "-all"])
    ipconfig_all_list = output.decode().split('\n')

    ip_addresses = []
    current_section = ""
    for i in range(0, len(ipconfig_all_list)):
        current_row = ipconfig_all_list[i]
        if " : " in current_row:
            current_section = current_row
        if "IPv4 Address" in current_section:
            # get the first ip address ip
            if "                                 " in ipconfig_all_list[i]:
                first_ip = ipconfig_all_list[i].strip().replace("(Preferred)", "")
            else:
                first_ip = ipconfig_all_list[i].split(":")[1].strip().replace("(Preferred)", "")
            if not is_valid_ipv4_address(first_ip):
                continue
            ip_addresses.append(first_ip)
            # get all other ip address ips if they exist
            k = i+1
            while k < len(ipconfig_all_list) and ":" not in ipconfig_all_list[k]:
                ip = ipconfig_all_list[k].strip()
                if is_valid_ipv4_address(ip):
                    ip_addresses.append(ip)
                k += 1
            # at this point we're done
            # break
    print("IP Addresses:",end ="")
    print(*ip_addresses, sep = ",")
    
    subnet_masks = []
    for i in range(0, len(ipconfig_all_list)):
        if "Subnet Mask" in ipconfig_all_list[i]:
            # get the first subnet masks
            first_ip = ipconfig_all_list[i].split(":")[1].strip()
            subnet_masks.append(first_ip)
            # get all other subnet masks ips if they exist
            k = i+1
            while k < len(ipconfig_all_list) and ":" not in ipconfig_all_list[k]:
                ip = ipconfig_all_list[k].strip()
                if is_valid_ipv4_address(ip):
                    subnet_masks.append(ip)
                k += 1
            # at this point we're done
            # break
    print("Subnet Masks:",end ="")
    print(*subnet_masks, sep = ",")

    gateway_ips = []
    current_section = ""
    for i in range(0, len(ipconfig_all_list)):
        current_row = ipconfig_all_list[i]
        if " : " in current_row:
            current_section = current_row
        if "Default Gateway" in current_section:
            # get the first default gateways ip
            if "                                 " in ipconfig_all_list[i]:
                first_ip = ipconfig_all_list[i].strip()
            else:
                first_ip = ipconfig_all_list[i].split(":")[1].strip()
            if not is_valid_ipv4_address(first_ip):
                continue
            gateway_ips.append(first_ip)
            # get all other default gateways ips if they exist
            k = i+1
            while k < len(ipconfig_all_list) and ":" not in ipconfig_all_list[k]:
                ip = ipconfig_all_list[k].strip()
                if is_valid_ipv4_address(ip):
                    gateway_ips.append(ip)
                k += 1
            # at this point we're done
            # break
    print("Default Gateways:",end ="")
    print(*gateway_ips, sep = ",")

    dns_ips = []
    for i in range(0, len(ipconfig_all_list)):
        if "DNS Servers" in ipconfig_all_list[i]:
            # get the first dns server ip
            first_ip = ipconfig_all_list[i].split(":")[1].strip()
            if not is_valid_ipv4_address(first_ip):
                continue
            dns_ips.append(first_ip)
            # get all other dns server ips if they exist
            k = i+1
            while k < len(ipconfig_all_list) and ":" not in ipconfig_all_list[k]:
                ip = ipconfig_all_list[k].strip()
                if is_valid_ipv4_address(ip):
                    dns_ips.append(ip)
                k += 1
            # at this point we're done
            # break
    print("DNS Servers:",end ="")
    print(*dns_ips, sep = ",")

    macs = []
    for i in range(0, len(ipconfig_all_list)):
        if "Physical Address" in ipconfig_all_list[i]:
            # get the first mac server ip
            first_ip = ipconfig_all_list[i].split(":")[1].strip()
            macs.append(first_ip)
            # get all other mac server ips if they exist
            k = i+1
            while k < len(ipconfig_all_list) and ":" not in ipconfig_all_list[k]:
                ip = ipconfig_all_list[k].strip()
                if is_valid_ipv4_address(ip):
                    macs.append(ip)
                k += 1
            # at this point we're done
            # break
    print("MAC Addresses:",end ="")
    print(*macs, sep = ",")

    nic_names = []
    for i in range(0, len(ipconfig_all_list)):
        if "Description" in ipconfig_all_list[i]:
            # get the first nic name
            first_ip =  ipconfig_all_list[i].split(":")[1].strip()
            nic_names.append(first_ip)
            # get all other nic name if they exist
            k = i+1
    print("NIC Names:",end ="")
    print(*nic_names, sep = ",")

    nic_types = []
    for i in range(0, len(ipconfig_all_list)):
        if " adapter " in ipconfig_all_list[i]:
            # get the first nic types
            first_ip = ipconfig_all_list[i].split(" adapter ")[0].strip()
            nic_types.append(first_ip)
    print("NIC Types:",end ="")
    print(*nic_types, sep = ",")

    descs = []
    for i in range(0, len(ipconfig_all_list)):
        if "Description" in ipconfig_all_list[i]:
            first_ip = ipconfig_all_list[i].split(":")[1].strip()
            descs.append(first_ip)

    try:            
        output2 = subprocess.check_output(['wmic', 'nic', 'where', 'netEnabled=true','get', 'name',',','speed'], stderr=subprocess.STDOUT)
    except subprocess.CalledProcessError as exc:
        output2 = exc.output

    nic_speeds_list = []
    if not "No Instance(s) Available." in output2.decode():
        nic_speeds_list = output2.decode().split('\r\r\n')
        while("" in nic_speeds_list) :
            nic_speeds_list.remove("")        
        nic_speeds_list.pop(0)

    nic_speeds = []
    for desc in descs:
        for i in range(0, len(nic_speeds_list)):
            if desc in nic_speeds_list[i]:
                nic_speed = int(nic_speeds_list[i].replace(desc,"").strip())
                if nic_speed >= int("1000000000"):
                    nic_speed = str(int(nic_speed/int("1000000000")))+" GBPS"
                elif nic_speed >= int("1000000"):
                    nic_speed = str(int(nic_speed/int("1000000")))+" MBPS"
                nic_speeds.append(nic_speed)
    print("NIC Speeds:",end ="")
    print(*nic_speeds, sep = ",")

if __name__ == "__main__":
    main()
