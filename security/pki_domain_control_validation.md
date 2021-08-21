
## Domain control validation

1. HTTP validation done by uploading a text file to a specific HTTP endpoint on the webserver they want to secure.  
   The CA must retrieve the text file by sending an HTTP GET request to

2. email verification where an email with a validation code link is sent to the administrative contact for the domain.

3. add a DNS TXT record containing a verification string or token from the CA to their domain’s resource records


## bgp based attacks

network-level adversaries advertise false routes over BGP to steal traffic, especially if that traffic contains something important, like a domain’s certificate.

two main approaches to attacking the DCV process with BGP hijacking:
1. Sub-Prefix Attack : When BGP announces a route, the router always prefers to follow the more specific route.
1. Equally-Specific-Prefix Attack

DNS spoofing : impersonate DNS nameserver while responding to CA

Bamboozling Certificate Authorities with BGP Henry Birge-Lee
https://www.princeton.edu/~pmittal/publications/bgp-tls-usenix18.pdf

## protection

RPKI : sign and verify BGP routes.

DNS query source IP randomization : make the source IP unpredictable to the attacker; becomes more challenging to spoof the second fragment of the forged DNS response to the DCV validation agent.

```
perform domain validation from multiple vantage points (data centers) to mitigate the impact of localized BGP attacks
Each datacenter has a unique path to DNS nameservers or HTTP endpoints, which means that successful hijacking of a BGP route can only affect a subset of DCV requests, further hampering BGP hijacks.
```

https://blog.cloudflare.com/secure-certificate-issuance/


