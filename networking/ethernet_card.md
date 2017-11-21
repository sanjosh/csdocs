
# Lingo

* RSS = Card distributes incoming packets to many cores based on hash
* RPS = Card cannot do RSS; software does it
* RFS = Receive flow steering (Linux version of Intel Flow Director)
  uses additional table to deal with pkt reordering which occurs after cpu migration of task
   /proc/sys/net/core/rps_sock_flow_entries
   /sys/class/net/<dev>/queues/rx-<n>/rps_flow_cnt
* Accelerated RFS (ndo_rx_flow_steer driver)
 required NIC support
 CONFIG_RFS_ACCEL
* XPS (transmit packet steering)
 CONFIG_XPS 
 /sys/class/net/<dev>/queues/tx-<n>/xps_cpus

# Intel Flow Director
  * Keeps action table in Card [HashTable[hash(ipaddr)] = CPU]
  * ATR mode samples outbound traffic to find which core the inbound traffic must be routed
  * EP mode allows user to program

-----------------

* indirection table
* receive queues = number of cores = each associated with IRQ
* PCIe devices notify using Message signaled intr (MSI-X) to route to particular CPU

----------------


```
Receive packet steering
# echo "f" > /sys/class/net/eth0/queues/rx-0/rps_cpus

Receive flow steering RFS

# echo 32768 > /proc/sys/net/core/rps_sock_flow_entries
# echo 4096 > /sys/class/net/eth0/queues/rx-0/rps_flow_cnt

Set rps_sock_flow table(it's global table) size, and set rps_dev_flow table(it's
per-device-queue table).

Accelerated RFS

XPS Transmit Packet Steering
# echo 1 > /sys/class/net/eth0/queues/tx-0/xps_cpus
# echo 2 > /sys/class/net/eth0/queues/tx-1/xps_cpus
# echo 4 > /sys/class/net/eth0/queues/tx-2/xps_cpus
# echo 8 > /sys/class/net/eth0/queues/tx-3/xps_cpus

Usage of set-rxfh-indir option:
# ethtool --set-rxfh-indir eth3 equal 2
# ethtool --show-rxfh-indir eth3

For example:
To include UDP port numbers in RSS hashing run:
# ethtool -N eth1 rx-flow-hash udp4 sdfn

To exclude UDP port numbers from RSS hashing run:
# ethtool -N eth1 rx-flow-hash udp4 sd

To display UDP hashing current configuration run:
# ethtool -n eth1 rx-flow-hash udp4

Flow steering (Intel Flow Director)

Usage of ethtool RX NFC configuration:

# ethtool -K eth0 ntuple on
# ethtool -k eth0|grep ntuple

ntuple-filters: on

# ethtool --config-nfc ix00 flow-type tcp4 src-ip 10.0.0.1 dst-ip 10.0.0.2
# src-port 10000 dst-port 10001 action 6

Added rule with ID 2045
# ethtool --show-nfc ix0
```

# References
1. https://www.kernel.org/doc/Documentation/networking/scaling.txt
2. http://syuu.dokukino.com/2013/05/linux-kernel-features-for-high-speed.html
