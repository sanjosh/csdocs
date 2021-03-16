
https://github.com/facebookincubator/ntp

use chrony instead of ntpd
https://chrony.tuxfamily.org/

improve accuracy from 10 milliseconds to 100 microseconds
https://engineering.fb.com/2020/03/18/production-engineering/ntp-service/

 Because of the Earth’s rotation irregularities, we occasionally need to add or remove a second from time, or a leap second.
 https://docs.ntpsec.org/latest/leapsmear.html

Facebook NTP service is designed in four layers, or strata:
1. layer of satellites with extremely precise atomic clocks from a global navigation satellite system (GNSS), such as GPS, GLONASS, or Galileo.
2. Facebook atomic clock synchronizing with a GNSS.
3. pool of NTP servers synchronizing to Stratum 1 devices. Leap-second smearing is happening at this stage.
4. tier of servers configured for a larger scale. They receive smeared time and are ignorant of leap seconds.

estimates from ntpd daemon rely on many assumptions
1. The network path between client and server is symmetric.
1. When timestamps are added to the NTP packet and send() is called, the operating system will dispatch it immediately.
1. Oscillator temperature and supplied voltage are constant.

where is higher precision needed
1. multi-master db
2. logging across systems

how to measure accuracy
1. generate analog signal froom atomic clock (1 pulse per second)
1. generate same from NTP server

commercial devices available

PTP (Precision Time Protocol).

public NTP service time.facebook.com

# Chrony code

https://chrony.tuxfamily.org/documentation.html

https://github.com/mlichvar/chrony

## interesting files

https://github.com/mlichvar/chrony/blob/master/samplefilt.c

https://github.com/mlichvar/chrony/blob/master/smooth.c

https://github.com/mlichvar/chrony/blob/master/tempcomp.c

https://github.com/mlichvar/chrony/blob/master/sourcestats.c

https://github.com/mlichvar/chrony/blob/master/regress.c
