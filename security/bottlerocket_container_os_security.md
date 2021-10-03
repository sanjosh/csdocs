
https://aws.amazon.com/blogs/opensource/security-features-of-bottlerocket-an-open-source-linux-based-operating-system/

## container attack surface

remove all shells, interpreters, and package managers from the Bottlerocket image.  run additional software as containers

Bottlerocket provides the control and admin containers by default.

control container : 

admin container  

## image based updates

uses TUF for software updates https://theupdateframework.io/

Embedded within each Bottlerocket image is a root.json file that begins the chain of trust in that it lists the keys that Bottlerocket will trust. This file is signed by multiple keys to hinder an attacker’s ability to replace it with a different version

## kernel lockdown

configure kernel lockdown in integrity mode. 
1. cannot overwrite the kernel’s memory 
2. cannot modify its code. 
3. cannot load unsigned kernel modules. 

## readonly FS

prevent changes to files on the root filesystem by mounting rootfs as a read-only volume

dm-verity : transparent integrity checking of block devices using a cryptographic digest. 

## SELinux 

Linux has DAC discretionary access control : access governed by identity

cannot be disabled

provides mandatory access control

labeling scheme for different system resources : processes, sockets, and files. 

labels
1. container_t : unprivileged
2. super_t : privileged
3. control_t : can write to API socket and change config

These labels are referenced in the rules SELinux enforces.

admission controller on K8
1. https://github.com/open-policy-agent/gatekeeper
2. https://kyverno.io/

## config storage

the /etc is a tmpfs mount on Bottlerocket rather than a directory on a persisted filesystem.

to change the configuration of the system, use Bottlerocket API, which runs locally on the instance

