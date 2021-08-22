
# PIR

client must read a bit from a replicated database without revealing to the servers the index being read.

distributed point function

## DIT deidentified data collection facebook privacy 

To gather analytics data in a de-identified and authenticated way, the logging requests from WhatsApp clients cannot contain anyone’s identity or any identifiable information, such as the IP address of the client

At a high level, DIT addresses this conundrum by splitting the logging workflow into two distinct steps. First, WhatsApp clients use an authenticated connection to the server to obtain an anonymous token (also referred to as an anonymous credential) in advance. Then, whenever the clients need to upload logs, they send the anonymous token along with the logs in an unauthenticated connection to the server. The anonymous token serves as proof that the client is legitimate

Our decision to use VOPRFs for de-identified interactions was inspired by the Privacy Pass protocol and blind signatures. While Privacy Pass uses VOPRFs to prevent service abuse from third-party browsers, we’ve shown that the same construction can also be useful in first-party data minimization.


Here is how the new logging workflow functions:

For the first step:

1.   Initially, the WhatsApp mobile client obtains a batch of tokens from our servers using a Verifiable Oblivious Pseudorandom Functions (VOPRF) scheme. Each token is an evaluation of the VOPRF, with a random string that the client chooses as the input.

2.   The client then sends a network request with a token.

3.   When a request hits our servers, the authentication server verifies the legitimacy of the request and the ACS, which manages keys for several applications, evaluates the VOPRF using its secret key.

4.   The result is returned as the credential to the mobile client via the application server.

For the second step:

1.   When the WhatsApp mobile client logs telemetry data, it attaches the input associated with the token to the logging request and binds the request with an HMAC applied to the data with a key derived from the token.

2.   The application server forwards the request to the ACS, which validates the token and limits the number of times it can be used, then derives the HMAC secret and returns it to the application server.

3.   The application server verifies the integrity of the log and decides whether to proceed with it.

If DIT proves to be both reliable and effective at scale, it will eventually allow WhatsApp to understand, for example, how many people have experienced an app crash without knowing which people were impacted by the crash.

We reduce the re-identification risk of a VOPRF token by actively measuring the re-identification and joinability potential of the data that’s collected and sounding an alert if the potential exceeds a particular threshold.

Since we cannot rate limit people during the anonymous redemption of the tokens, we use key rotation to rate limit them.

https://engineering.fb.com/2021/04/16/security/dit/
