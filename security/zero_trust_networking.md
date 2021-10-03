
https://en.wikipedia.org/wiki/Zero_trust_networks

John Kindervag

# Gilman Barth book

https://www.amazon.com/dp/B072WD347M/

## three components

disadvantages of traditional perimeter model

three components of zero trust model
1. user or app authentication
2. device auth
3. trust

zero trust is designed to prevent data breaches and limit internal lateral movement. 

control plane sets up paths in data plane

normally, trust delegation is done for
1. OS image
2. provisioning service
3. application artifacts
4. application server

## Trust and authentication

1. credentials may be legitimate but not kept secret
1. hence credentials must be time-boxed (rotation)

PKI (CA) is bedrock of zero-trust

Private (per-company) PKI better over public (global) PKI 

where to store private key ?
1. for device cert : inside a smart card
2. for user cert : with the person

Accessing a critical production system should require additional confirmation (second factor)

how to determine risk of access
1. temporal (outside normal time window)
2. behavioral (resource is abnormal)
3. geographical (outside normal location )

Trust score: a zero trust network will continuously monitor the actions of an actor on the network to update their trust score.

control plane grants ephemeral access

## Network agent 

Policy cannot be applied to user, application and device separately.  

Network agent combines user, application and device.

network agent as an ephemeral entity that is formed on demand to evaluate a policy

Agents only do authorization and do not play any part in authentication

```
authentication is session oriented, but in the case of authorization, it is
best to be request oriented. As a result, caching the outcome of an authentication
request is permissible, but caching an agent or the result of an authorization
request is ill advised. This is because details in the agent, which are used to
make authorization decisions, can change rapidly based on a number of factors,
```

REVOKE AUTHORIZATION FIRST, CREDENTIALS SECOND

example of device data  : SNMP MIB

## Authorization architecture

1. policy engine decides policy in control plane
2. trust engine computes trust scores in control plane
3. data store in control plane
4. enforcement in data plane

policy should not be defined by network implementation but by logical components
1. network services
2. device endpoint classes
3. user roles

example of kubernetes policy which is based on labels

should score be calculated for
1. user ?
2. device ?
3. network agent ?

all of above since compromises can occur as combination of all

we do not want to adversely impact a particular device or user

data store (historical versus primary)
1. user 
2. device
3. workload
4. auth accounting
5. sflow records

## trusting a device

Secure Boot is one way to help fend against these kinds of attacks. It involves loading a public
key into the device’s firmware, which is used to validate driver and OS loader signatures to
ensure that nothing has been slipped in between.

unique device certificate

the private key associated with device certificate must be stored in TPM

process of generating new identity and signing new certificate

It is possible to accomplish provisioning and signature authorization in a single
step through the use of a temporal one-time password (TOTP). The TOTP can
be provided along with the provisioning request and passed through to the
signing service for verification,

certificate signing service

X.509 cert has Subject field stores information about the owner (e.g. a device )

X.509 cert has private key which must be protected

```
TPMs generate and store what is known as a storage root key, or an SRK. This
key pair represents the trust root for the TPM device. Data encrypted using its
public key can be decrypted by the originating TPM only.

Platform configuration registers (PCRs) are an important TPM feature. They
provide storage slots into which hashes of running software is stored. It starts
with the hash of the BIOS, then the boot record, its configuration, and so on.
This sequence of hashes can then be used to attest that the system is in an
approved configuration or state

ensuring that only authorized software configurations are allowed to decrypt data. 
This can be done by passing in a set of known-good PCR values when using the TPM 
to encrypt some data. 
This is known as “sealing” the data. Sealed data can only be decrypted by the
TPM which sealed it, and only while the PCR values match.

Since PCR values cannot be modified or rolled back, we can use TPM sealing to
ensure that our secret data is not only locked to the device, but also locked to a
specific software configuration and version.
```

TPM has endorsement key

Remote attestation is a method by which the TPM generates something called a
“quote,” which is then securely transmitted to a remote party. The quote includes
a list of current PCR values, signed using the EK

strongSwan : IKE daemon

TPM virtualization : vTPM for Xen

for legacy devices in a zero trust network : use an authentication proxy

### Secure introduction

first connection from new device requires trusted third party

good secure introduction msut be
1. single use
2. short-lived
3. leverage third party

example of Chef

```
Instead of having a static validation certificate, the provisioning system (via Chef client utility “knife”)
communicates with the Chef server and creates a new client and associated client certificate. 

It then creates the new host, and passes in its client certificate. In this
way, an expectation for the new client has been set. While these credentials are
not short-lived, it remains as a superior approach.
```


### Renew trust

the less often a device is rotated or reimaged, the more rigorous your endpoint security must be.

OS -> Bootloader -> BIOS -> Hardware

methods of renewing trust
1. Local measurement : TPM remote attestation of software-based agent
2. remote measurement : vulnerability scan

software config management : Chef, Puppet, Ansible

## trusting users

Zero trust networks identify and trust users separately from devices

authentication must be done in control plane

escalation : user may pass additional forms of authentication in order to raise their level of trust

use trust score to decide when to authenticate

using multiple channels to reach the requestor : multiple channels are hard to compromise simultaneously

use control plane tokens rather than application tokens to control authorization, since they are easier to revoke

auth mechanisms
1. know : password
2. have : OTP, cert, security token
3. are  : biometric

choose combination with one from each group

generate per-use X.509 cert

out-of-band : phone call, passive email, 

### SSO : SAML, Kerberos, CAS, OAuth2

```
SSO tokens should be validated against the centralized authority as often as
possible. Every call to the control plane to authorize an SSO token provides an
opportunity to revoke access or alter the trust level (as known to the caller).

A popular mode of operation involves the service performing its own sign in,
backed by SSO authentication. The primary drawback of this approach is that it
allows the control plane to authorize the request only once, and leaves the
application to make all further decisions. Trust variance and invalidation is a key
aspect of a zero trust network, so decisions to follow this pattern should not be
taken lightly.
```

### Local auth

FIDO UAF

users authenticate their presence with a trusted device, and then the device is able to attest to that identity with a remote service

### shared secret

Cloudflare red october project

DNS root zone signing ceremony
```
The ceremony utilizes seven actors, each with a different role. The ceremony mitigates the risk of
compromise to a one-in-a-million chance, assuming a dishonesty rate of 5% among the actors in the
ceremony. A strict procedural document is generated in order to organize the ceremony. HSMs,
biometric scanners, and air-gapped systems are used to protect the digital key. In the end, a new
public/private key pair is generated and signed, continuing the internet’s trust anchor for another
quarter.
```


### recovery

identity authority must have mechanism to regain control of identity in case credentials lost

### bootstrapping

1. govt issued id
2. person contact


## trusting application

supply chain security

compromises at 4 levels
1. developers : signed source code
2. compiler tool : 
3. deployment tools
4. runtime infra

git stores history of commits as DAG
```
storing the cryptographic hashes of ancestor commits on each commit itself, we
form a Merkle tree, which allows one to cryptographically validate that the chain
of commits are unmodified
```

metadata security : Git commits and tags can be signed by GPG of developer

reproducible builds using virtualized build env

immutable builds : cannot be tampered, write once read many

publish a signed manifest, outlining the released versions and their cryptographic hashes.

### APT tool and distribution network

An APT repository contains three types of files: a Release file, a Packages file, and the packages themselves 

Release file contains checksum of Packages file

Release file is signed with private key of maintainer

```
Organizations that release software like this will commonly use “code signing ceremonies,” where the
signing key is stored on a hardware security module (HSM) and unlocked using
authorization from multiple parties, as a mitigation against the theft of this
highly sensitive key.
```

Upgrade-only policy : only install if version is newer (otherwise older vulnerability introduced)

#### response wrapping

```
Rather than giving your deployment system direct access to secrets, it is possible to leverage a trusted
third party, allowing the deployment system to instead assign policy dictating which secrets the
running instance can access. Hashicorp’s Vault, for instance, has a feature called response wrapping in
which an authorized party can request a secret to be generated and stored for later retrieval. In the
context of a deployment system, the deploy itself could contact Vault and direct the creation of secrets
on behalf of the authorized instances, injecting a one-time-token into the runtime which the
application can use to retrieve the generated secrets,
```

1. fuzzing of code (afl-fuzz)
2. injection scanning (sqlmap)
3. network scan (nmap)
4. vulnerability scan nessus

application isolation : SELInux, AppArmor, BSD jail, Virtualization

## trusting traffic

first packet problem : pre-auth using Single packet authorization (SPA)

fwknop SPA 

two dominant security suites : TLS (connection) and IPSec (VPN)

```
IPsec can use a unique security association (SA) per application (see RFC
4301, section 4.4.1.1). Only authorized flows are then allowed to construct
these security policies.
```

IKE is control plane of IPSec - perform key exchange

mTLS : client is also validated

Perfect forward secrecy : compromise of private key


## realizing zero-trust

```
zero trust is not a product that can be bolted onto
the network. It is a set of architectural principles which are applied based on the
needs and constraints of the network.
```

1. use private PKI 
2. network flows must be enumerated
3. device scans, patched, rotated (prefer re-imaging over scanning)

MFA 

prefer security tokens (UFA) over time-based tokens (TOTP)

zero-trust proxies

### PagerDuty’s Cloud Agnostic Network

### Google BeyondCorp

1. Managed device
1. SSO
1. Access proxy

## adversarial view


# BeyondCorp from google


# NIST

https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-207.pdf


