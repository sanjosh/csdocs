
https://stackoverflow.com/questions/4892602/how-does-the-github-website-work-architecture

## 2009 overview

Three protocols : ssh, git and http

Load balancer

### Website requests

1. Requests to main website go to four frontend machines
2. Nginx accepts connection and sends it to Unicorn (http server in Ruby)
3. may make request to MySQL
4. User's repo kept on a fileserver
5. Redis keeps persistent the routing info (user to fileserver)
6. Communication using BERT RPC

https://github.blog/2009-10-20-introducing-bert-and-bert-rpc/

https://github.blog/2009-10-09-unicorn/

### git requests 

If you run a command like git clone tom@frost:mojombo/bert, what Git is doing behind the scenes is SSHing to frost, authenticating as the tom user, and then remotely executing git upload-pack mojombo/bert

git-shell restricts commands which can be run remotely

Git relies on the fact that SSH allows you to execute commands on a remote server. 

On Github, ssh command works as follows
1. ssh session hits load balancer
2. then it it sent to frontend sshd
3. the patched sshd performs public key lookups from mysql 
4. the original cmd and args are sent to Git Serve script (a git-shell)
5. Git Serve checks permissions using SQL queries
6. Git Serve looks up Redis to find file server
7. forwards commands to file server

Performing public clones and pulls via Git is similar to how the SSH method works. Instead of using SSH for authentication and encryption, however, it relies on a server side Git Daemon. This daemon accepts connections, verifies the command to be run, and then uses fork(2) and exec(3) to spawn a worker that then becomes the command process.

In addition to the primary web application and Git hosting systems, we also run a variety of other sub-systems and side-systems. 

Sub-systems include the job queue, archive downloads, billing, mirroring, and the svn importer. 

Side-systems include GitHub Pages, Gist, gem server, and a bunch of internal tools. Y

https://github.blog/2009-10-20-how-we-made-github-fast/

## Network

https://github.blog/2016-09-22-introducing-glb/

### Data center & POP

petabytes of Git data stored for users of GitHub.com and do around 100Gb/s across transit, internet exchanges, and private network interfaces in order to serve thousands of requests per second. 

2 POPs, 2 data centers

 the data centers are in standalone cages in less well connected facilities and we use metro waves between the POPs and data centers along with passive dense wavelength division multiplexing (DWDM) to connect them.

one type of cabinet in the POPs which includes management and production border routers, optical networking gear, and enough compute hardware to run core services. 

Our data centers have three different types of cabinets — networking, compute, and storage. The majority of the cabinets are for compute and storage hardware, each of which are in specific sets of cabinets rather than mixing them to allow the tiers to be grown independently. 

Data about the cabinet layout from the integrator is imported into our hardware management system, gPanel, to map serial numbers to rack units and enclosures. gPanel provides hardware discovery via a stateless image that’s run across all chassis that aren’t currently installed.

https://github.blog/2017-10-12-evolution-of-our-data-centers/

https://github.blog/2017-09-05-keeping-an-eye-on-our-network/

https://github.blog/2017-05-31-dns-infrastructure-at-github/

https://github.blog/2017-10-12-transit-and-peering-how-your-requests-reach-github/ 
  
## Spokes replicaton

https://github.blog/2017-10-13-stretching-spokes/

https://github.blog/2016-09-07-building-resilience-in-spokes/

https://github.blog/2016-04-05-introducing-dgit/

## MySQL

https://github.blog/2018-06-20-mysql-high-availability-at-github/

### incidence analysis

loss of connectivity between our US East Coast network hub and our primary US East Coast data center for 43 sec

GitHub operates multiple MySQL clusters varying in size from hundreds of gigabytes to nearly five terabytes, each with up to dozens of read replicas per cluster to store non-Git metadata, so our applications can provide pull requests and issues, manage authentication, coordinate background processing, and serve additional functionality beyond raw Git object storage. Different data across different parts of the application is stored on various clusters through functional sharding.

During loss of connectivity, Orchestrator moved primary mysql to other datacenter

After connectivity restored, failover could not happen because each data center contained writes that were not present in other data center.

We made an explicit choice to partially degrade site usability by pausing webhook delivery and GitHub Pages builds instead of jeopardizing data we had already received from users. In other words, our strategy was to prioritize data integrity over site usability and time to recovery.


While MySQL data backups occur every four hours and are retained for many years, the backups are stored remotely in a public cloud blob storage service. The time required to restore multiple terabytes of backup data caused the process to take hours. A significant portion of the time was consumed transferring the data from the remote backup service. The process to decompress, checksum, prepare, and load large backup files onto newly provisioned MySQL servers took the majority of time. This procedure is tested daily at minimum, so the recovery time frame was well understood, however until this incident we have never needed to fully rebuild an entire cluster from backup and had instead been able to rely on other strategies such as delayed replicas.

Adjust the configuration of Orchestrator to prevent the promotion of database primaries across regional boundaries. Orchestrator’s actions behaved as configured, despite our application tier being unable to support this topology change. Leader-election within a region is generally safe, but the sudden introduction of cross-country latency was a major contributing factor during this incident

https://github.blog/2018-10-30-oct21-post-incident-analysis/

https://github.blog/2016-12-08-orchestrator-github/

While repository data lies in git, metadata is stored in MySQL. This includes Issues, Pull Requests, Comments etc. We also auth against MySQL via a custom git proxy (babeld). 

We have different clusters to provide with different types of services, but the single-writer-multiple-readers design applies to them all. Depending on growth of traffic, on application demand, on operational tasks or other constraints, we take replicas in or out of our pools. Depending on workloads some replicas may lag more than others.

replica which lags by 1 second is taken off

HAProxy to load balance mysql replicas

1. Can we automate exclusion and inclusion of backend servers based on replication status?
2. Can we automate exclusion and inclusion of backend servers based on server role?
3. How can we react to a scenario where too many servers are excluded, and we are only left with one or two “good” replicas?
4. Can we always serve?
5. How easy would it be to override pool membership manually?
6. Will our solution survive a service haproxy reload/restart?

https://github.blog/2016-08-17-context-aware-mysql-pools-via-haproxy/

https://github.blog/2016-08-01-gh-ost-github-s-online-migration-tool-for-mysql/

https://github.blog/2014-09-02-making-mysql-better-at-github/

https://github.blog/2015-11-03-like-injection/

## Redis

https://github.blog/2017-01-10-moving-persistent-data-out-of-redis/

## Ruby GC

https://github.blog/2018-05-18-removing-oobgc/

## git 

faster diff
https://github.blog/2016-12-06-how-we-made-diff-pages-3x-faster/

merge
https://github.blog/2015-12-15-move-fast/

## Frontend

### GraphQL api

GitHub API available through GraphQL, in addition to REST

we heard from integrators that our REST API also wasn’t very flexible. It sometimes required two or three separate calls to assemble a complete view of a resource. It seemed like our responses simultaneously sent too much data and didn’t include data that consumers needed.

We wanted to be smarter about how our resources were paginated. 

We wanted assurances of type-safety for user-supplied parameters

we wanted to identify the OAuth scopes required for each endpoint. 

We wanted to generate clients instead of manually supplying patches to our Octokit suite. 

GraphQL advantages
1. query specifies the fields you want and the number (top 10)
2. batch requests - specify dependencies between 2 queries
3. create subscriptions (i.e. webhook, notification)
4. you can defer part of the response as time-insensitive
5. strongly typed - schema
6. combine multiple REST Api requests into one


Type safety, introspection, generated documentation, and predictable responses benefit both the maintainers and consumers of our platform. 

https://github.blog/2016-09-14-the-github-graphql-api/

https://github.blog/2015-05-19-browser-monitoring-for-github-com/

https://github.blog/2014-01-16-optimizing-large-selector-sets/

## SRE

alarms
https://github.blog/2015-06-16-exception-monitoring-and-response/

metrics
https://github.blog/2015-06-15-brubeck/

## Security

https://github.blog/2014-01-07-improving-our-ssl-setup/

https://github.blog/2013-04-19-content-security-policy/
