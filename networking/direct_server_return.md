
# Direct Server Return for Load Balancer

In DSR mode, the load-balancer routes packets to the backends without changing anything in it but the destination MAC address.  The backends process the requests and answer directly to the clients, without passing through the load-balancer.  The backends must have the service IP configured on a loopback to be able to accept the requests.

https://www.haproxy.com/blog/layer-4-load-balancing-direct-server-return-mode/

## The Drawbacks of DSR

1. Backend servers have to crank up the amount of work that they must do, responding to health check requests with their own IP address and to content requests with the VIP assigned  by the load balancer.
2. Cookie insertion and port translation are not able to be implemented.
3. ARP (Address Resolution Protocol) requests must be ignored by the backend servers. If not, the VIP traffic routing will be bypassed as the backend server establishes a direct two way connection with the client.
4. Application acceleration is not an option, as the load balancer plays no part in the handling of outbound traffic.
5. Protocol vulnerabilities are not protected. Slack enforcement of RFCs and incorrectly specified protocols are unable to be addressed and resolved.
6. Caching needs to take place on the routers using WCCP. This means a more complex network, an additional potential point of failure and greater latency due to an additional network hop.
7. There is no way to handle SOAP/Error/Exception issues. The user receives classic error messages such as 404 and 500 without the load balancer having the chance to retry the request or even notify the administrator.

https://kemptechnologies.com/in/white-papers/what-is-direct-server-return/

 ```
 The Real Server is configured with an IP address as normal but it is also given the IP address of the Virtual Service. Normally you cannot have two machines on a network with the same IP address. To get around this, the Virtual IP (VIP) address on a Real Server must be configured so that the server does not respond to ARP requests on the VIP address.
 ```
 https://support.kemptechnologies.com/hc/en-us/articles/202040805-Direct-Server-Return-DSR-

* TCP multiplexing can't be accomplished in a DSR configuration because it relies on separating client connections from server connections. This reduces the efficiency of your servers and minimizes the value added to your network by a load balancer


https://devcentral.f5.com/articles/the-disadvantages-of-dsr-direct-server-return


