
Firecracker began as a fork of Google's crosvm from ChromeOS. 

(crosvm runs untrusted operating systems along with virtualized devices)

It runs Linux guest VMs using the Kernel-based Virtual Machine (KVM) API and emulates a minimal set of devices. 

Currently, it supports only Intel processors, but AMD and Arm are planned to follow. 

In contrast to the QEMU code base of well over one million lines of C, which supports much more than just qemu-kvm, Firecracker is around 50 thousand lines of Rust.

Firecracker ships as a single static binary linked against the musl C library. 

Each run of Firecracker is a one-shot launch of a single VM

https://lwn.net/Articles/775736/


