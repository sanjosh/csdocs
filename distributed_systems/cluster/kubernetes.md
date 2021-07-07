
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
