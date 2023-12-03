
# terminology

* Pod = collection of containers with same network stack, installed on "pause container"
* API server which uses etcd

https://sookocheff.com/post/kubernetes/understanding-kubernetes-networking-model/

# Networking in Kubernetes

* uses iptables
* Layer-3
* almost no portmapping
* CNI spec
* minikube for test cluster
* kubenet = linux network plugin created bridge called cbr0

CNI has 3 required functions : ADD, DEL and VERSION

https://blog.neuvector.com/article/advanced-kubernetes-networking


# CNI 

overlay network

CNI plugins work on different OSI Network Layers to cover their use-cases. 

Many of them work on Layer 2, Layer 3 and Layer 4. 

If a CNI works on Layer 2, they are generally faster but don’t have as many features as Layer 3 or Layer 4 based CNIs.

## Calico uses BGP

## Flannel

## Canal

## Multus


# load balancing

* within cluster, use netfilter linux or IPVS (IP virtual server)

# Anthos

# Ranchos

# Redhat Openshift 

# service discovery

https://www.openshift.com/blog/multicluster-service-discovery-in-openshift

# secret

cert-manager Vault multicluster secrets https://cert-manager.io/docs/configuration/vault/

# Submariner

cross-domain networking

handle overlapping CIDR using globalnet

connect overlay networks of different Kubernetes clusters.

https://submariner.io/getting-started/architecture/

# KubeVirt

https://kubevirt.io/

# K3os

https://k3os.io/

# Harvester

https://harvesterhci.io/

# hardening guide

NSA Kubernetes Hardening Guidance

## threat model

### supply chain

### malicious threat actor

### insider threat



## guidance

Kubernetes Pod security
1. Use containers built to run applications as non-root users
1. Where possible, run containers with immutable file systems
1. Scan container images for possible vulnerabilities or misconfigurations
1. Use a Pod Security Policy to enforce a minimum level of security including:
-  Preventing privileged containers
-  Denying container features frequently exploited to breakout, such as hostPID, hostIPC, hostNetwork, allowedHostPath
-  Rejecting containers that execute as the root user or allow elevation to root
-  Hardening applications against exploitation using security services such as SELinux®, AppArmor®, and seccomp

Network separation and hardening
1. Lock down access to control plane nodes using a firewall and role-based access control (RBAC)
1. Further limit access to the Kubernetes etcd server
1. Configure control plane components to use authenticated, encrypted communications using Transport Layer Security (TLS) certificates
1. Set up network policies to isolate resources. Pods and services in different namespaces can still communicate with each other unless additional separation is enforced, such as network policies
1. Place all credentials and sensitive information in Kubernetes Secrets rather than in configuration files. Encrypt Secrets using a strong encryption method


Authentication and authorization
1. Disable anonymous login (enabled by default)
1. Use strong user authentication
1. Create RBAC policies to limit administrator, user, and service account activity

Log auditing
1. Enable audit logging (disabled by default)
1. Persist logs to ensure availability in the case of node, Pod, or container level failure
1. Configure a metrics logger

Upgrading and application security practices
1. Immediately apply security patches and updates
1. Perform periodic vulnerability scans and penetration tests
1. Remove components from the environment when they are no longer needed

https://media.defense.gov/2021/Aug/03/2002820425/-1/-1/1/CTR_KUBERNETES%20HARDENING%20GUIDANCE.PDF

# visual guide debugging

https://learnk8s.io/troubleshooting-deployments
