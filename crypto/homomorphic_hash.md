

#  merkle tree

However, this improved update and verification performance can be attained only by subscribers who keep a representation of the entire Merkle tree in memory — thus requiring memory overhead linear in the number of database rows.

# homomorphic hash

A truly efficient solution would allow the distributor and its subscribers to update the database hash entirely independent of the size of the database. These requirements are satisfiable through the use of homomorphic hashing.

“Given the hash of an input, along with a small update to that input, how can we compute the hash of the new input (with the update applied) without having to recompute the entire hash from scratch?” 

 We use LtHash, a specific homomorphic hashing algorithm based on lattice cryptography, to create an efficiently updatable checksum of a database. This checksum, along with a signature from the distributor of the database, allows a subscriber to validate the integrity of database update

https://code.fb.com/security/homomorphic-hashing/
