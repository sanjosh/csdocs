
# DNS domains 

root
top-level

DNS server registers with parent domain server

# DNS zones

# Queries

recursive
iterative
inverse


# DNS record types

Hierarchical DB filled with RR - resource record

| record | purpose |
| ---- | ---------|
| SOA | Start of authority - parameters for zone |
| A | domain name to IP addr |
| AAAA | domain name to IPv6 addr | 
| MX | mail exchange |
| NS | name server for domain |
| CNAME | redirect domain name |
| PTR | IP addr to domain |
| TXT | add annotation to domain  |
| SPF | Sender policy framework | text encoding of mail sending policy |
| SRV | Service | host that provides it |

SPF (sender policy framework)|

# Security

## DNSSEC

## DoH dns over https

## DoT dns over tls

## unbound dns

Unbound is a validating, recursive, and caching DNS resolver


# tools

## dig 

## host

## nslookup

# Misc

1. Dents Design of DNS Usenix 99
2. https://github.com/EmilHernvall/dnsguide

