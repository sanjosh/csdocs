
* Verb      :  RC  :  UC  : UD
* SEND/RECV :  Y   :  Y   : Y+
* rdma Write:  Y   :  Y+
* rdma Read :  Y  

Notes
* Connected = 2 qpairs communicate exclusively with each other (RC & UC)
* UC : no Ack/Nak packet
* UD : qpair can talk to multiple qpair
* Memory semantics : RDMA read/write do not consume CPU on responder.  Lowest latency, highest throughput
* Channel semantics: SEND will write in memory address provided by pre-posted RECV
* SEND/WRITE/READ are posted to send queue of QP
* RECV is posted n recv queue of QP
* Inlined post command involves no DMA

----------------

XRC - https://www.spinics.net/lists/linux-rdma/msg08055.html

------------

# Verbs (infiniband/verbs.h)

```
ibv_qp_type
{
  IBV_QPT_UC = Unreliable conn
  IBV_QPT_UD = Datagram
  IBV_QPT_RC = Reliable conn
  IBV_QPT_RAW_PACKET
}

ibv_wr_opcode
{
  IBV_WR_RDMA_WRITE
  IBV_WR_RDMA_WRITE_WITH_IMM
  IBV_WR_SEND
  IBV_WR_SEND_WITH_IMM
  IBV_WR_RDMA_READ
  IBV_WR_ATOMIC_CMP_AND_SWP
  IBV_WR_ATOMIC_FETCH_AND_ADD
}
```

Types
* ibv_device
* ibv_context
* verbs_context
* ibv_srq
* ibv_comp_channel

Completion Queue (ibv_cq)
Completion Event Channel
Shared Receive queue (ibv_srq)

```
Queue Pair (ibv_qp)
{
   states = RTR, RTS, SQD, SQE (Ready to Receive, Ready to Send)
   attributes
}
```
Protection Domain (ibv_pd)
Address Handle (ibv_ah)
Work Completion (ibv_wc)

Sequence of commands
* ibv_get_device_list
* ibv_create_ah
* ibv_open_device
* ibv_alloc_pd
* ibv_create_cq( 
* ibv_create_qp( pass UC, RC, UD)
* ibv_create_srq(
* ibv_modify_qp
* ibv_reg_mr(
* ibv_post_send
* ibv_post_recv
* ibv_poll_cq(

-----------

# librdma

file = rdma_cma.h, rdma_verbs.h

```
rdma_event_channel
{
  int fd
}
rdma_cm_id = socket
{
  ibv_context
  rdma_event_channel
  ibv_qp
  ibv_cq
  ibv_comp_channel
  ibv_seq
  ibv_pd
}

rdma_create_id(
    RDMA_PS_IPOIB or UDP => IBV_QPT_UD
    RDMA_PS_TCP   => IBV_QPT_RC
  )


rdma_create_qp( can give qp_type = any of 3)

rdma_post_ud_send - IBV_WR_SEND
rdma_post_sendv - IBV_WR_SEND
rdma_post_writev - IBV_WR_RDMA_WRITE
rdma_post_readv - IBV_WR_RDMA_READ

RDMA_PS_TCP = 
RDMA_PS_UDP
RDMA_PS_IPOIB
RDMA_PS_IB
```

Reference
1. https://www.spinics.net/lists/linux-rdma/msg23063.html
2. https://www.spinics.net/lists/linux-rdma/msg23071.html

---------------

# rsocket

Only RC 
it calls rdma_create_qp with qp_type = IBV_QPT_RC)

rsocket calls rdma_create_id (RDMA_PS_TCP)
raccepts creates qpair with IBV_QPT_RC

-------------

# Accelio API

xio_rdma_management : IB_QPT_RC

xio_common.h

```
xio_wc_op
{
   XIO_WC_OP_RECV
   XIO_WC_OP_SEND
   XIO_WC_OP_RDMA_READ
   XIO_WC_OP_RDMA_WRITE
}
```

xio_rdma_transport.h
```
xio_ib_op_code
{
   XIO_IB_RECV
   XIO_IB_SEND
   XIO_IB_RDMA_WRITE
   XIO_IB_RDMA_READ
   XIO_IB_RDMA_WRITE_DIRECT
   XIO_IB_RDMA_READ_DIRECT
}
```

calls to xio_prep_rdma_op (xio_rdma_path.c)

* xio_rdma_task->out_ib_op = RDMA_WRITE
* ibv_send_wr.send_flags  
* ibv_send_wr.opcode = ibv opcode
* xio_rdma_perform_direct_rdma - opcpde = IBV_WR_RDMA_WRITE/READ
* xio_sched_rdma_rd - IBV_WR_RDMA_READ
* xio_sched_rdma_wr_req - IBV_WR_RDMA_WRITE
* xio_rdma_send_setup_req
* xio_rdma_prep_req_out_data - IB_SEND

-----------

# HERD paper 

sequence of calls
* send request using RDMA WRITE over UC
* send reply   using SEND over UD
* No RDMA READ
* Avoid overhead of posting RECV on server
* RNIC needs memory to maintain qpair context.  Cache miss causes PCI transaction

MICA - Flow director feature on NIC

* ibv_get_device_list
* ibv_open_device
* ibv_alloc_pd
* ibv_reg_mr
* ibv_create_cq
* ibv_create_qp(UC or RC)
* ibv_create_cq
* ibv_create_qp(UD)
* ibv_modify_qp(state = IBV_QPS_INIT
* ibv_create_ah (server)
* ibv_modify_qp(state = IBV_QPS_RTR -> RTS)
* ibv_poll_cq
* ibv_post_send
* ibv_post_recv
* ibv_destroy_qp
* ibv_destroy_cq
* ibv_dealloc_pd
* ibv_close_device

------------

# UCX API

Has unreliable datagram and reliable conn

IBV_QPT_UD and IBV_QPT_RC

* UCM : comm mgr
* UCP :
* UCS : 
* UCT : 

------------

# Description

(from somewhere)

Building queue pairs and connecting them to each other, such that operations
posted on one side are executed on the other, involves the following steps:

1. Create a protection domain (which associates queue pairs, completion queues, 
memory registrations,
etc.), a completion queue, and a send-receive queue pair.
2. Determine the queue pair’s address.
3. Communicate the address to the other node (through some out-of-band
mechanism).
4. Transition the queue pair to the ready-to-receive (RTR) state and then the
ready-to-send (RTS) state.
5. Post send, receive, etc. operations as appropriate.  

Step four in particular isn’t very pleasant, so we’ll use a event-driven
connection manager (CM) to connect
queue pairs, manage state transitions, and handle errors. 

We could use the InfiniBand Connection Manager (ib cm), but the RDMA Connection Manager 
(available in librdmacm, and also known as the connection manager abstraction2), 
uses a higher-level IP address/port number abstraction that should be familiar to
anyone who’s written a sockets program.

-------------------

# References

1. https://www.zurich.ibm.com/sys/rdma/interfaces.html
2. https://thegeekinthecorner.wordpress.com/2010/08/14/building-an-rdma-capable-application-with-ib-verbs-part-3-the-client/
3. http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.189.1285&rep=rep1&type=pdf


