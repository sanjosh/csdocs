
# Microdata problem

Release microdata where each row corresponds to user

Each record has a number of attributes, which can be divided into
the following three categories. 
1. Explicit : Attributes that clearly identify individuals. e.g. Social Security Number, Address, and Name, and so on. 
2. Quasi-identifier : Attributes whose values when taken together can potentially identify an individual. e.g., Zip-code, Birthdate, and Gender. 
3. Sensitive : Attributes that are considered sensitive, such as Disease and Salary.

Two types of information disclosure 
1. identity disclosure 
2. attribute disclosure. new info about individual is revealed. 

A common anonymization approach is generalization, which replaces quasi-identifier 
values with values that are less-specific but semantically consistent

# statice

https://www.youtube.com/watch?v=QHmV92Sf8iY
https://www2.slideshare.net/figago/privacypreserving-data-sharing-pydata-berlin-2018



## earlier techniques

These techniques compromised data integrity of the tables
1. Sampling, 
1. Cell Suppression, 
1. Rounding, 
1. Data Swapping and Perturbation.

## PII removal 

1. pseudonymization
2. sanitize
3. de-identification
4. anonymization

## differential privacy

NIST Differential Privacy Synthetic Data Challenge.

https://www.nist.gov/itl/applied-cybersecurity/privacy-engineering/collaboration-space/focus-areas/de-id/tools

https://github.com/google/differential-privacy

https://github.com/IBM/differential-privacy-library

https://github.com/prashmohan/GUPT

https://diffprivlib.readthedocs.io/en/latest/index.html

## k-anonymity 

each combination of quasi-identifiers appears in at least k rows

using suppression, generalization, binning, top-coding

While k-anonymity protects against identity disclosure, it is insufficient to prevent attribute disclosure.

Latanya Sweeney. 2002. k-anonymity: A model for protecting privacy. International Journal of Uncertainty, Fuzziness and Knowledge-Based Systems 10, 05 (2002), 557–570

## l-diversity 

distribution of a sensitive attribute in each equivalence class has at least  “wellrepresented” values

it is possible for an adversary to gain information
about a sensitive attribute as long as she has information
about the global distribution of this attribute

Ashwin Machanavajjhala, Johannes Gehrke, Daniel Kifer, and Muthuramakrishnan Venkitasubramaniam. 2006. l-diversity: Privacy beyond k-anonymity. In ICDE. 24–24

## t-closeness 

formalizes the idea of global background knowledge by requiring that the distribution of a sensitive attribute 
in any equivalence class is close to the distribution of the attribute in the overall table 
(i.e., the distance between the two distributions should be no more than a threshold t).

Further, in order to incorporate distances between values of sensitive attributes, we use the
Earth Mover Distance metric [14] to measure the distance between the two distributions

Ninghui Li, Tiancheng Li, and Suresh Venkatasubramanian. 2007. t-closeness: Privacy beyond k-anonymity and l-diversity. In ICDE. 106–115.

## aggregate query answering

N. Koudas, D. Srivastava, T. Yu, and Q. Zhang. Aggregate query answering on anonymized tables. In Proc. 23rd Intnl. Conf. Data Engg. ICDE, 2007


## COCOA synthetic data generator

https://github.com/ucd-pel/COCOA

