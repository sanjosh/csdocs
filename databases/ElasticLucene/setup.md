
## data

/var/lib/elasticsearch

index lifecycle management
https://www.elastic.co/guide/en/elasticsearch/reference/current/index-lifecycle-management.html

dedicated ingest nodes
https://www.elastic.co/guide/en/elasticsearch/reference/current/ingest.html

searchable snapshot
https://www.elastic.co/guide/en/elasticsearch/reference/current/searchable-snapshots.html

transforms
https://www.elastic.co/guide/en/elasticsearch/reference/current/transforms.html

Frozen index

rolling 
https://www.elastic.co/guide/en/elasticsearch/reference/current/xpack-rollup.html

hot-warm index

## config

/etc/elasticsearch

Elasticsearch has three configuration files:

1. elasticsearch.yml for configuring Elasticsearch
1. jvm.options for configuring Elasticsearch JVM settings
1. log4j2.properties for configuring Elasticsearch logging

### persistent vs transient

https://www.elastic.co/guide/en/elasticsearch/reference/current/cluster-update-settings.html

## Plugin

/usr/share/elasticsearch/plugins

# Logging

/var/log/elasticsearch

# Security

https://www.elastic.co/guide/en/elasticsearch/reference/current/secure-settings.html

# Snapshot

# Monitoring

# Sizing

1. max document limits
2. open file handles
3. thread pool
4. RAM
5. CPU
6. timeout on search and throttling
7. sharding
8. flash vs HDD

# Manual SOP and scripts


