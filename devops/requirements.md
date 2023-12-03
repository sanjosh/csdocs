
# declarative


# Auditability 

to ensure auditability, everything has to be under version control (GitOps - no manual operations).  This ensure we know which code change is causing error.

# Portability (Docker)

Code has to be made portable across machines and cloud providers.
hence, we use Docker image like a "capsule" to bundle all the code.   
Same Docker image works in AWS, Azure, GCP or other providers

# What if there is an error ? - How to trace back the code change which caused the problem (tagging)

Docker image "tags" contain the "git commit sha" (will show later)

It must be easy to figure out the code change from the Docker image (therefore, docker image has a tag which matches the commit, so you know which docker tag matches which code change)

# Eliminate Manual error in creating database/machine/load balancer (IAC)

to eliminate manual error, every environment (server, database, network) is created using automation (IaC like terraform)

# Only code which is tested  can be deployed to customers in Production (CI)

every code change has to be tested in test environment before deployment to production.  That is why we have a pipeline.  The pipeline has multiple steps : first we run tests before deploying the code in production

# Tested code has to be the same as deployed code (use same docker image)

Pipeline must use same Docker image in all steps (test/build)

# How to ensure everyone uses same Docker image ( use a registry) 

Push docker images in a registry (Docker hub, AWS ECR, Google Container registry, private registry)
pull them and use them

https://hub.docker.com/search?q=


https://console.cloud.google.com/gcr/images/google-containers/GLOBAL

https://learn.microsoft.com/en-us/azure/container-registry/container-registry-get-started-portal?tabs=azure-cli

# How to deploy to production on every change (Continuous Deployment)

every code change must be automatically pushed to production.  Hence pipeline is set up to run on every code change
