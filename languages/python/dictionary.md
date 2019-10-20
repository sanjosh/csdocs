
# implementation of dict

rules

1. dict is really a list (hash, key, value)
1. keys are hashed into 32 bits - print(bits(hash(key)) - using bottom n bit of hash
1. collision : key order is sensitive to dictionary insertion order; quadratic probing
1. deleting keys will not free space
1. set is dict without value

for integers, each integer is its own hash

when deleting a key, python leaves dummy key in its place

dicts gets resized when 2/3 full - keys are reinserted and reordered

no insertion during dictionary iteration

http://book.pythontips.com/en/latest/__slots__magic.html

https://pyvideo.org/pycon-us-2010/the-mighty-dictionary-55.html
