
# Facebook Encryption at scale

https://atscaleconference.com/videos/networking-scale-2019-enforcing-encryption-scale/

developed SSLWall : monitor outbound connections and kill non-compliant ones

why not link layer encryption between network switches ?

defence in depth (misconfiguration, dependency on vendors)

SSLWall built using BPF (tc-bpf, kprobes, bpf maps)

why not L7 Firewall ? 

SSLWall runs on every host. Reduces cost of processing. More configurable.

