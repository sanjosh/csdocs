
openssl s_client -showcerts -servername "domainname" -connect "domainname:443"

copy them to /etc/ssl/certs/ca-bundle.crt

# client versus server certificate

https://security.stackexchange.com/questions/1438/what-is-the-difference-between-an-x-509-client-certificate-and-a-normal-ssl-ce

# multi-domain vs ssl cert

https://sectigostore.com/page/multi-domain-ssl-vs-wildcard-ssl/

https://security.stackexchange.com/questions/121003/benefits-of-a-wildcard-vs-per-subdomain-certificates

# DV, EV, OV, IV validation


Domain Validation (DV) is the lowest level of validation, and verifies that whoever requests the certificate controls the domain that the certificate protects.

Organization Validation (OV) verifies the identity of the organization (e.g. a business, nonprofit, or government organization) of the Subject listed in the certificate, along with the location where the organization operates.

Individual Validation (IV) verifies the identity of the individual person listed as the Subject of the certificate. This may be the same as the person who requested the certificate. Often, the address of the Individual is also verified.

Extended Validation (EV), like OV, verifies the identity of an organization. However, EV represents a higher standard of trust than OV and requires more rigorous validation checks to confirm that the organization is properly registered with the authorities in its jurisdiction and that it meets the requirements set by the CA/Browser Forum.


https://www.ssl.com/article/dv-ov-and-ev-certificates/

# SSL Site seal

https://www.ssl.com/faqs/faq-what-is-a-site-seal/

# CNAME and subdomain takeover

https://developer.mozilla.org/en-US/docs/Web/Security/Subdomain_takeovers
