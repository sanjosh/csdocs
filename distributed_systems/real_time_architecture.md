
# why microservice

scale independently

fail independently

independent development lifecycle + programming lang + toolset

# Avoid bad patterns with microservices:

Don’t build a microservice just because you have a well abstracted API in your application code. 
Having a well-abstracted API is necessary but far from being sufficient to turn that into a microservice. 
Think about the key reasons mentioned above such as scaling independently, isolating workloads or leveraging a foreign language runtime & libraries.

Avoid accidental complexities — when your microservices start depending on microservices that depend on other microservices, 
it is time to admit you have a problem, look for a nearest “Microservoholics Anonymous” and laugh at this video 
while realizing you are not alone with these struggles. [3]

# reliability

In your application stack, assume for every level you have in your stack, you will lose one 9 in your application’s reliability. 
This is why a multi-level microservices stack will always be a disaster when it comes to ensuring uptime.

Metadata services used for service discovery are close to the bottom of that stack and they need to provide 1 or 2 orders of 
magnitude higher reliability than any service built on top of that.

https://rockset.com/blog/building-real-time-data-architectures-to-foster-innovation/
