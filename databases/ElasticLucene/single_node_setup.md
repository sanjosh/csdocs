
## install

https://www.elastic.co/guide/en/elasticsearch/reference/current/deb.html

## use service instead of systemctl

https://askubuntu.com/questions/903354/difference-between-systemctl-and-service-commands

sudo -i service elasticsearch start
sudo -i service elasticsearch stop

start from command line
./bin/elasticsearch

## test

curl -X GET "localhost:9200/?pretty"

