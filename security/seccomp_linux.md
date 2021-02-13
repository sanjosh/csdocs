
use seccomp to limit syscalls from a linux process

system calls seccomp() or prctl(2)

add seccomp filters in BPF syntax

two main uses for seccomp filters are 
1. sandboxing and 
2. failure-mode testing

libseccomp - high level API for creating filters
https://github.com/seccomp/libseccomp

BPF compiler 

# applications

QEMU "--sandbox" 

Docker "--security-opt"

Google Chrome sandbox renderer and flash player

Android zygote


