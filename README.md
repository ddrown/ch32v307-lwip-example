# CH32V307 example LWIP based apps

Forked from https://github.com/smartmx/lwip_study_examples

This is LWIP using the CH32V307 and its on-chip 10M Ethernet PHY

For the dev board, connect PB8 to ELED1 (green) and PB9 to ELED2 (amber) for link and data activity LEDs on the Ethernet jack

This sends ch32v307 as the DHCP hostname if your router automatically assigns it a DNS name

iperf server requires a v2.x client (iperf) and not a v3.x client (iperf3)

```
$ iperf -i 1 -c ch32v307.lan
------------------------------------------------------------
Client connecting to ch32v307.lan, TCP port 5001
TCP window size: 16.0 KByte (default)
------------------------------------------------------------
[  1] local x.x.x.x port 50954 connected with x.x.x.y port 5001 (icwnd/mss/irtt=14/1460/447)
[ ID] Interval       Transfer     Bandwidth
[  1] 0.00-1.00 sec  1.13 MBytes  9.44 Mbits/sec
[  1] 1.00-2.00 sec  1.12 MBytes  9.44 Mbits/sec
[  1] 2.00-3.00 sec  1.12 MBytes  9.44 Mbits/sec
[  1] 3.00-4.00 sec  1.12 MBytes  9.44 Mbits/sec
[  1] 4.00-5.00 sec  1.12 MBytes  9.44 Mbits/sec
[  1] 5.00-6.00 sec  1.12 MBytes  9.44 Mbits/sec
[  1] 6.00-7.00 sec  1.12 MBytes  9.44 Mbits/sec
[  1] 7.00-8.00 sec  1.12 MBytes  9.44 Mbits/sec
[  1] 8.00-9.00 sec  1.12 MBytes  9.44 Mbits/sec
[  1] 9.00-10.00 sec  1.12 MBytes  9.44 Mbits/sec
[  1] 0.00-10.05 sec  11.4 MBytes  9.49 Mbits/sec
```

tcp echo client example:
```
$ dd if=/dev/zero | nc ch32v307.lan 5002 | pv >/dev/null
14.4MiB 0:00:12 [1.12MiB/s]
27825+0 records in
27824+0 records out
14245888 bytes (14 MB, 14 MiB) copied, 12.0476 s, 1.2 MB/s
```
