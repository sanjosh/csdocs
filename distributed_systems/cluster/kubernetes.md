
A cluster is formed from a combination of worker nodes and the control plane

# why

container orchestration - bringing it all together

1. scaling
2. customization
3. rolling updates and rollback
4. explicit control plane (API)
5. control plane state stored with interaction (objects and etcd)

# stateful applications

StatefulSets

StatefulSet is the workload API object used to manage stateful applications.

Manages the deployment and scaling of a set of Pods, and provides guarantees about the ordering and uniqueness of these Pods.

# control plane

The control plane is responsible for managing the clusters process, which includes kube-apiserver, etcd, Kubernetes scheduler, kube-controller-manager, and Cloud controller manager

1. An API server that transmits data both within the cluster and with external services
2. A scheduler that handles resource sharing among the nodes
3. A controller manager that watches the state of the nodes
4. A persistent data store to keep configurations
5. A controller manager and a cloud controller manager to manage control loops

https://www.airplane.dev/blog/kubernetes-control-plane

# helm package manager

1. helm search
2. helm install
3. help create
4. help lint

## CI/CD hooks 

https://helm.sh/docs/topics/charts_hooks/

# objects

two categories of objects in Kubernetes

basic objects: Pods, Service, Volumes, Namespace, etc., which are independent and don’t require other objects

high-level objects (controllers): Deployments, Replication Controllers, ReplicaSets, StatefulSets, Jobs, etc., which are built on top of the basic objects

## finalizer


# API

The Kubernetes API is what makes a cluster tick. Every action inside your Kubernetes cluster goes through the API. The entire kubectl tool is essentially a wrapper around this API. When you run kubectl apply, you are sending a request that tells the control plane to create your resources. This request goes through the API, which then hands it over to the right internal services.

https://www.airplane.dev/blog/kubernetes-api

client libraries to interact with API

https://kubernetes.io/docs/reference/using-api/client-libraries/

operators to talk to API

## API groups

# operator

capture human knowledge; customization

https://kubernetes.io/docs/concepts/extend-kubernetes/operator/

# ConfigMap


# ingress

An Ingress is a Kubernetes resource that allows traffic to come into your Kubernetes cluster.

Ingress provides externally available URLs, performs load balancing, terminates SSL/TLS, and offers name-based virtual hosting.

An Ingress controller is a daemon running in a Pod that watches the /ingresses endpoint on the API server. When a new endpoint is created, the daemon uses the configured set of rules to allow traffic into a service.

https://www.airplane.dev/blog/kubernetes-ingress


# microk8s

# playgrounds

