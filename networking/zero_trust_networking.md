
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


## trusting application

## trusting traffic

## realizing zero-trust

## adversarial view


# BeyondCorp from google




# NIST

https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-207.pdf


