
# template induction

figure out template used in a machine-generated email

## applications of template induction

1. spam and phishing detection
1. causal threading
1. email search ranking

# Juicer (google)

two steps
1. induction of template from set of emails
2. annotation of each email

offline Annotation service with MapReduce

## vertical classifier

binary classifier for each vertical

hyperparameters are picked using the Gaussian Process Bandits algorithm in Vizier

## generate clusters using fingerprint

1. Convert DOM tree of email into set S of XPath using inorder traversal.
1. XPath includes HTML tags and indices and omits HTML attributes and values.
1. Draw three subsets using MinHash.
1. For emails from same template, probability is high that at least one hash will coincide
1. Why MinHash better than Exact hash : because list of items which appears in email keeps changing.
1. cluster is accepted if same email was sent to at least k unique recipients
1. User-defined cluster aggregator : Process emails using template to further define extraction rules or field classifiers (e.g. determine date format)

## recency of cluster

if template changes, the MinHash may still allow new emails to map to cold template.

## (can do here) 

1. invalidate and re-induce a template if errors cross threshold and then reprocess the emails after that date
1. keep versions of template if same origin

## email annotation

use field classifier to extract field values, and insert in key-value store (emailId, templateId, list of keys-values)

field classifiers depend on vertical classifier
1. hotel-checkin date triggered only if its a hotel email
2. bill due date triggered only if its a bill

## privacy

use k-anonymity.  There is also l-diversity and t-closeness

1. use donated emails for sanity checking
2. use opt-in rating program 
3. Generate synthetic email for human reviewer 


## ref

Sheng, Anatomy of a privacy-safe large-scale information extraction system over email https://research.google/pubs/pub46991/

# Crusher

Online approach
1. Annotation service
2. Clustering service

## ref

Whittaker, Online Template Induction for Machine-Generated Emails https://research.google/pubs/pub48356/

# other

multiple algorithms for template induction have been described [2, 4] 

# Threading machine-generated email

Nir Ailon, Zohar S Karnin, Edo Liberty, and Yoelle Maarek. 2013. Threading machine generated email. In WSDM. 405–414.

# Structural clustering of machine-generated email

Noa Avigdor-Elgrabli, Mark Cwalinski, Dotan Di Castro, Iftah Gamzu, Irena Grabovitch-Zuyev, Liane Lewin-Eytan, and Yoelle Maarek. 2016. Structural Clustering of Machine-Generated Mail. In CIKM. 217–226

applications like email threading [2] and hierarchical classification [44]

# plain text emails 

Julia Proskurnia, Marc-Allen Cartright, Lluís Garcia-Pueyo, Ivo Krka, James B
Wendt, Tobias Kaufmann, and Balint Miklos. 2017. Template Induction over
Unstructured Email Corpora. In WWW. 1521–1530.

# email extraction at Yahoo 

Dotan Di Castro, Iftah Gamzu, Irena Grabovitch-Zuyev, Liane Lewin-Eytan,
Abhinav Pundir, Nil Ratan Sahoo, and Michael Viderman. 2018. Automated
Extractions for Machine Generated Mail. In Companion Proceedings of The Web
Conference. 655–662.

# TODO

generalizing XPaths using decision trees to “forgiving XPaths” shown to improve extraction accuracy [32]
