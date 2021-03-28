
# Architectures That Scale Deep - Regaining Control in Deep Systems

https://www.youtube.com/watch?v=xCRFlhkAF1s
Ben Sigelman Lightstep
QCon 2021

deep = four layers of independently operated service

as your system gets deeper, you don't really get to control anything more than the service you started with, but your scope of responsibility is actually proportional to the square of the depth of your system.

The most valuable thing that traces can do is not to explain what happened but to explain what did not happen.

most important thing for architecting around depth is probably some sort of rigorous standardization of the way that services are deployed and operated

Kafka lag : single bad actor can delay everything

