
ifup & ifdown

/etc/network/interfaces

(for static IP)
put the following in /etc/network/interfaces
```
iface eth0 inet static
address 192.168.2.85
netmask 255.255.255.0
network 192.168.2.0
broadcast 
gateway
dns-nameservers <>
```

(for DHCP)
```
auto eth0
iface eth0 inet dhcp
```

(NetworkManager)
* nmcli
* nm-tool
* /etc/NetworkManager
* /var/lib/NetworkManager

-----------

(Wireless)

* First get the wireless net connected
* then get DHCP
* then get DNS and gateway working

* iwlist for scanning
* iwconfig

* for wpa, use wpa_supplicant, wpa_cli, wpa_passphrase
* rfkill to reinitialize wireless
* wvdial 
--------------

(DNS)
host and dig commands
nslookup
/etc/resolv.conf

----------------
usb-devices

----------------


```
tcpdump -l -v -iwlan0 -w <file> -K -q
```

WIRESHARK:
```
apt-get install wireshark
dpkg-reconfigure wireshark-common
groupadd wireshark
	groupadd: group 'wireshark' already exists
usermod -a -G wireshark root
chgrp wireshark /usr/bin/dumpcap
chmod 755 /usr/bin/dumpcap
setcap cap_net_raw,cap_net_admin=eip /usr/bin/dumpcap
wireshark&
```

tcpstat

```
sudo tshark -i lo -w mispk -f "dst port 9999"
```


----------------

iftop
