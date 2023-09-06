import socket
import struct
from ipaddress import ip_address


def ip2int(addr: str) -> int:
    return struct.unpack("!I", socket.inet_aton(addr))[0]


def ips_between(start: str, end: str) -> int:
    return ip2int(end) - ip2int(start)


def ips_between_smart(start: str, end: str) -> int:
    return int(ip_address(end)) - int(ip_address(start))


print(ips_between("10.0.0.0", "10.0.0.50"))
print(ips_between("20.0.0.10", "20.0.1.0"))

print(ips_between_smart("10.0.0.0", "10.0.0.50"))
print(ips_between_smart("20.0.0.10", "20.0.1.0"))
