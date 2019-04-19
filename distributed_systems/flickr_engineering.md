
## Unique id generation

A Flickr ticket server is a dedicated database server, with a single database on it, and in that database there are tables like Tickets32 for 32-bit IDs, and Tickets64 for 64-bit IDs.

You really really don’t know want provisioning your IDs to be a single point of failure. We achieve “high availability” by running two ticket servers. At this write/update volume replicating between the boxes would be problematic, and locking would kill the performance of the site. We divide responsibility between the two boxes by dividing the ID space down the middle, evens and odds, using:


http://code.flickr.net/2010/02/08/ticket-servers-distributed-unique-primary-keys-on-the-cheap/
