
# Facebook (Sara knodeir)

Since not enough ground truth is available, do multi-stage multi-task learning with small amount of high precision human labels and large amount of low precision labels (9 minute)

Direct features for each entity
1. User
1. Device
1. Group
1. Photo
1. Status Update
1. IP address

Fanout types for each entity
1. User : entities interacted with
1. IP address
1. Page
1. Group
1. Device
1. Status Update

2 stage neural network

For imbalanced data, use stratification; upsample abusive accounts

https://atscaleconference.com/videos/fighting-abuse-scale-2019-deep-entity-classification-an-abusive-account-detection-framework/

# Facebook (Aude Hofleitner)

source embedding : who posted

target embedding (who interacted) + action embedding (what was interaction) -> fed to seq2seq

uses BigGraph library for pages, posts, users - unsupervised embeddings

Training data ?

is time of interaction taken into account ?

https://atscaleconference.com/videos/fighting-abuse-scale-2019-temporal-interaction-embeddings-incorporating-context-for-finding-abuse-at-scale/

