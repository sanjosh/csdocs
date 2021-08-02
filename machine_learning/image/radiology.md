
# qure talk medical.ai radiology

in x-ray image, about 20-30 pixels are abnormal; it is difficult to train algo on that small a feature

chest x-ray : corners should be sharp - hence fluid

look at ABCDE in x-ray scan
1. Airway
1. Breathing
1. Cardiac
1. disability (bone)

CT-scan : slices of chest - have small abnormal nodules which indicate disease

symptoms data (reported by patient) can be collected and used to correlate (annotation)

X-ray and corresponding reports. Run NLP on report to generate soft labels for X-ray

time-based differencing for same patient : to measure progression of disease

quality : for 2 perc of data, compare ML model output with radiologist

demographical ethnicity : age groups matter, X-ray scans differ for same disease

scanning technology evolves but not rapidly

learning
1. how to build trust
2. india based
3. used attribution methods for ML models to find why model was highly accurate (model was misled by handwriting found on x-ray scan)
4. medical certification

