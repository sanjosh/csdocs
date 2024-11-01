

https://blog.cloudflare.com/turnstile-ephemeral-ids-for-fraud-detection/
```
In the early days of the Internet, a single IP address was a reliable indicator of a single user.
However, today’s Internet is more complex. Shared IP addresses are now common, with users connecting
via mobile IP address pools, VPNs, or behind CGNAT (Carrier Grade Network Address Translation).
```


```
Turnstile detects bots by analyzing browser attributes and signals. Using these aggregated client-side signals,
 we generate a short-lived Ephemeral ID without setting any cookies or using similar client-side storage.

These IDs are intentionally not 100% unique and have a brief lifespan, making them highly effective in
identifying patterns of fraud and abuse, without compromising user privacy.
```
