
anti-spoofing

#  SPF - sender policy framework (DNS record)

1. a policy framework as its name implies, 
2. an authentication method 
3. specialized headers in the actual email itself that convey this information. 

# DKIM - DomainKeys identified email

https://admin.google.com/ac/apps/gmail/authenticateemail

# DMARC - Domain message authN, reporting and conformance

ties SPF and DKIM

# process for google hosted domain

Generate DKMI via https://admin.google.com/ac/apps/gmail/authenticateemail   
Generate SPF records  
Push out DKIM + SPF TXT records via Route53  
Validate entry

```host -t txt google._domainkey.<domain_name> 1.1.1.1```

