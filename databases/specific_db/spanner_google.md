
# Google Spanner

* spanserver stores tablet
* tablet : key + ts => string
* spanner assigns the ts
* tablet stored in B-tree like files and WAL on Colossus (Colossus is successor to Google File system)

* directory = range of keys with common prefix
* directories are unit of movement between span server

* directory can be sharded if it grows too big
