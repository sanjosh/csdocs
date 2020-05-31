
The Security Impact of HTTPS Interception

Zakir Durumeric, et al

HTTPS interception products typically function as transparent proxies:
* they terminate the browser’s TLS connection,
* inspect the HTTP plaintext,
* relay the HTTP data over a new TLS


Weakened security:
intercepted connections used weaker cryptographic algorithms, but 10–40% advertised support for known-broken ciphers that would allow an active man-in-the-middle attacker to later intercept, downgrade, and decrypt the connection

How to detect interception:
Web servers can detect interception by identifying a mismatch between the expected behaviour of the browser specified in the HTTP User-Agent header and the actual behavior of the TLS client
each browser family selects a unique set of options, and that these options differ from those used by both common libraries (e.g., OpenSSL) and popular interception products.
However, while each browser, library, and security product produces a unique Client Hello message, the parameters selected by browsers are not statically defined.
Instead, browsers alter their behavior based on hardware support, operating system updates, and user preferences
Chrome was one of the most challenging browsers to fingerprint because its behavior is dependent on hardware support and operating system


How to inject CA certificate: 
For network middleboxes, administrators deploy the middlebox’s CA certificate to devices within their organization. Subsequently, when the proxy intercepts a connection to a particular site, it will dynamically generate a certificate for that site’s domain name signed with its CA certificate and deliver this certificate chain to the browser


Variations in TLS:
As of early 2016, there exist more than
340 cipher suites,
36 elliptic curves,
3 elliptic curve point formats,
28 signature algorithms, and
27 extensions that clients can advertise


TLS variations:
* OpenSSL is well known
* Mozilla maintains its own TLS implementation, Mozilla Network Security Services
* Chrome uses BoringSSL, an OpenSSL fork, connections have a similar structure to OpenSSL.
* Apple Safari ships with its own TLS implementation, Apple Secure Transport

SDK for TLS interception:
* Komodia redirector
* Netfilter

Firefox browsers routinely check for software updates by retrieving an XML document from a central
Mozilla server over HTTPS. This check uses Firefox’s standard TLS library (Mozilla NSS) and
occurs every 24 hours while the browser is running and on browser launch if the last update
occurred more than 24 hours prior.

We can partially validate our methodology by checking whether we failed to detect any connections that included proxy-related HTTP headers as intercepted

Public key pinning in HTTPS does not apply:
Contrary to widespread belief, public key pinning [19]— an HTTPS feature
that allows websites to restrict connections to a specific key— does not prevent
this interception. Chrome, Firefox, and Safari only enforce pinned keys when
a certificate chain terminates in an authority shipped with the browser or
operating system. The extra validation is skipped when the chain terminates in
a locally installed root (i.e., a CA certificate installed by an administrator) [34].
Internet Explorer and Edge do not support key pinning

Many network middleboxes inject HTTP headers, such as X-Forwarded-For and Via,
to assist managing simultaneous proxied connections.

To overcome weaknesses in existing revocation protocols, Firefox ships with OneCRL [43] and Chrome, CRLSets

Known TLS attacks :
* BEAST
* FREAK
* Heartbleed

Alternatives to interception:
-HTTP 2.0 Explicit Trusted Proxy RFC
-TLS Proxy Server Extension
