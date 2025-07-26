https://www.atlassian.com/blog/developer/why-atlassian-uses-an-internal-paas-to-regulate-aws-access

micros



Micros is a relatively simple platform. The inputs it takes to deploy a service are just a Docker image containing the service logic, and a YAML file – the Service Descriptor – that describes the backing resources that the service needs (databases, queues, caches, etc.) as well as various configuration settings, such as the service’s autoscaling characteristics. The system takes care of expanding those inputs into production-ready services, ensuring operational functionality (e.g. log aggregation, monitoring, alerting) and best practices (e.g. cross Availability-Zone resiliency, consistent backup/restore/retention configuration, sensible security policies) are present out-of-the-box.

All services on Micros have a metadata record (surfaced in a tool we call Microscope) that includes information such as the service owner, team, on-call roster, SLIs/SLOs – this is invaluable for incident scenarios, in which obtaining this kind of information quickly is essential. Micros also enforces consistent tagging of AWS resources, which helps with cost attribution and setting up filters for automated security, compliance, and best-practices scanning.
