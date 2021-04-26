
# TLS

Michael W Lucas - has book TLS Mastery 

## Concept of Trust bundle

Contains a list of authorities to trust

Mozilla bundle

You can setup your own trust bundle

Tools to manage trust bundle
1. Certctl
1. Add-trusted-cert
1. Update-ca

command `Openssl -CAfile`

bugs in chain of trust
1. intermediate CA promoted to root CA

## openssl 

use `openssl --connect` or `openssl -crif`

add `--verify_return_error` to check TLS and certs

connect to webserver
```
openssl s_client -crlf --verify_return_error -connect www.mwl.io:443
```

harder to prove it does not support older TLS versions

Use `--tls1_3` or `-no_tls1_3`

## Certificates

X.509 built on ASN.1

gives information labels like OU=, O=, ST=

each label has an ASN.1 identifier

Certificate signing request (CSR) : form sent to CA

Certificate File : signed extract of CSR information

Certificate validation level 
1. Domain validated : CA verifies entity controls the host
2. Org validated : entity belongs to org
3. Extended validation : org requesting cert is a specific legal entity

All of them provide browser lock icon

### Certificate algo

1. RSA 
2. ECDSA : newer standard.  Requires less computing to validate, so use in mobile.

### CN : Common name of certificate

Could be email address, UID, first and last name, device serial number

Can be hostname too but its deprecated

CN can have max 63 char

Replacement is called server alternative name (SAN)

### viewing cert

```
openssl x509 -in file.crt -text -nout
```

to view SAN
```
openssl x509 -in mwlio.cer -nout -ext subjectAltName
```

## wildcard certificate

## revoking certificates

if private key is compromised, tell the CA

distributed by 2 different methods
1. Certificate revocation list (CRL)
2. online cert status protocol : must enable on Chrome and Safari.

Firefox and safari distribute revoked cert lists to users

But Chrome filters the revocation list that users see

CA distributes file containing serial numbers of all unexpired revoked certs

Usually in DER format

CRL does not scale well

Server can make OCSP queries, attach cert and return with client request (called stapling)

If revocations can be ignored (as in Chrome), what to do
1. use short lived cert 
2. DANE (DNS)
3. deploy chromium forks that enable secure features, or use Firefox, Safari
4. store private keys in HSM


## Generating a cert

use modern config file based method

```
openssl req --newkey rsa -config mwl.io.conf -out mwl.io.csr
```

## Connecting Certs with keys

keypair modulus is a shared numeric value to connect crt, csr and key files

openssl x509 -nout -modulus -in server.crt | openssl md5
openssl rsa  -nout -modulus -in server.csr | openssl md5 
openssl req  -nout -modulus -in server.key | openssl md5

## ACME (automated cert management)

free CA - Lets Encrypt

LE provides free 90 day DV X.509 cert

How ACME works
1. Domain validation  : prove you control the host

ACME challenges
1. HTTP-01 : put file in certain location
2. DNS-01 : make change in DNS
3. ALPN-01 : make change in TLS protocol in destination

* Single server ? use http-01
* wildcard cert ? DNS-01
* load balancer, server pool, clustering : ALPN-01

Use cron to renew them

## conclusion

Use higher than 1.2 or 1.3

Use HSTS header : Strict transport security

TLS testing : ssllabs.com

Private testing  https://testssl.sh

certificate transparency : public record of issued certs (https://crt.sh)

certs contain CT signatures

Failures : badssl.com has expired cert, edge cases

Running your own CA : openssl-ca, easy-rsa, XCA, Dogtag, FreeIPA, EJBCA


