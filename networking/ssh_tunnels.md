
https://iximiuz.com/en/posts/ssh-tunnels/

```
Local port forwarding (ssh -L) implies it's the ssh client that starts listening on a new port.
Remote port forwarding (ssh -R) implies it's the sshd server that starts listening on an extra port.
The mnemonics are "ssh -L local:remote" and "ssh -R remote:local" and it's always the left-hand side that opens a new port.
```
