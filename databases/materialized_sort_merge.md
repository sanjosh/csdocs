
# MaSM (materialized sort merge)

Instead of Differential updates cached in RAM, they cache on SSD and then merge with results on HDD.

No Random writes on SSD.

Use external sorting algo since they have small memory footprint and avoid random writes to SSD.

Analysis showing cost of using LSM on SSD.

[TODO]

# References

Athanassoulis.  MaSM.  SIGMOD 11


