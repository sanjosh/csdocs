
# Does processor have AES-NI enabled in BIOS ?

`grep -o aes /proc/cpuinfo | wc -l`


# AES-NI enabled in Linux ?

`cpuid | grep -i aes | sort | uniq`

# Is AES-NI optimized driver loaded 

`sort -u /proc/crypto | grep module | grep aes`

# Does openssl have aes-ni

`openssl engine`

 must show

`(aesni) Intel AES-NI engine`

# higher MB/s if server has AES-NI support

`
dd if=/dev/zero count=1000 bs=1M | ssh -l sandeep -c aes128-cbc serverB "cat >/dev/null"
`

# openssl benchmark

compare output of 

`openssl speed aes-256-cbc`

versus

`openssl speed -evp aes-256-cbc`

EVP (envelope encryption) functions auto-detect if AES-NI supported by CPU
 
# References

1. http://unix.stackexchange.com/questions/14077/how-to-check-that-aes-ni-is-supported-by-my-cpu

2. https://software.intel.com/en-us/articles/intel-advanced-encryption-standard-instructions-aes-ni/
3. https://www.cyberciti.biz/faq/how-to-find-out-aes-ni-advanced-encryption-enabled-on-linux-system/
