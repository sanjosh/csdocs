
# OpenFST 

## operations table

| Operations using OpenFST |  description |
| ----------| --------------| 
| Read a batch of strings and build FST | http://www.openfst.org/twiki/bin/view/Forum/FstForum#Making_an_FST_with_C_How_to_defi |
| Search exact string | Build another FST using the String.  Then run Intersect of two FSTs. |
| Search for suffix | One approach is to Reverse the FST and search for the prefix.  Find the cost. |
| Search for regex | http://www.openfst.org/twiki/bin/view/Forum/FstForum#Regex_to_FST |
| Search for approx match | Use Edit Transducer and Shortest Distance algorithm.  http://www.openfst.org/twiki/bin/view/Forum/FstForum#How_to_compute_edit_distance_of |
| Typeahead | Find all strings with common prefix |

# References

1. http://openfst.org/twiki/bin/view/FST/FstQuickTour
2. http://www.openfst.org/twiki/bin/view/FST/FstSltTutorial


