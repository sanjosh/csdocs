
# Mojibake

UTF-8 variable length - first four bits  1111 - expect 32 bit

existing solutions github python-ftfy

use low word-level bi-gram frequency as indicator of mojibake
but need to know language 
mixed language text

trigram - increase recall, reduce precision

n-gram db fo 72 lang

split into words; sanitize words

unicode normalization : NFC
four different types

same abstract char can be represented by multiple codepoint combinations
two types of formal equivalence
1. canonical : always have same visual appearance
2. compatibility : distinct visual appearance

rule-based regex detection for common mojibake 

encoding fixer : use n-gram frequencies
iterative lookup  - multi pass algo
176 known mojibake
cannot fix - what about ?

ideograph : char represent more than a single letter; hard to create n-grams; large alphabets

number of encodings * number of languages
