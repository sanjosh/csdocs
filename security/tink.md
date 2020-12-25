
# Tink

* hard-to-misuse API
* builtin key rotation
* support for deprecation
* KMS integration
* protection against side-channel
* thread safety

## usage

https://github.com/google/tink/blob/master/docs/JAVA-HOWTO.md

## primitives

* MAC
* AEAD = Authenticated encryption with associated data 
* Digital signature
* Hybrid encryption (symmetric + pke)

https://github.com/google/tink/blob/master/docs/PRIMITIVES.md

## external KMS

* AWS
* GCP
* Android

## Key 

Key Manager understands key type

## Keyset 

Keyset = collection of keys corresponding to single primitive 

user works with keyset via keyset handle

because Keyset understands key rotation; has distinguished primary key

keyset can contain reference to KMS external keys 

disabling obsolete keys; forbid creation of deprecated schemes

https://github.com/google/tink/blob/master/docs/KEY-MANAGEMENT.md

## Registry 

key type -> key manager


https://github.com/google/tink

https://github.com/google/tink/tree/master/docs
