
Types of obfuscation
1. surface or Layout  : names replaced, push related functions apart
2. alter control flow
3. alter data structure
4. inserting dead code

Obfuscators
1. Zelix
1. Proguard
1. yGuard
1. JBCO

C. Collberg, C. Thomborson, D. Low, A Taxonomy of Obfuscating Transformations.  Auckland New Zealand

* all fields declared in the same class must have distinct names 
* all classes that belong to the same package must have distinct names. 
* method overriding - must have same name
* any two packages within same package must have distinct names
* ignore generic types because they are removed by the compiler during the type erasure process 

KNOWN
* Nodes that represent packages, classes, methods, and fields that are part of the Android API are known.
* Constructor methods have fixed names are known

(DeGuard) Bischel et al, Statistical Deobfuscation of Android Applications

-----------

```
BCEL : java bytecode framework
ASM  : java bytecode framework
Soot : static analysis framework
Dava : decompiler for Java
JODE : decompiler
Fernflower
Procyon
CFR
JDCore
JAD
ANTLR : lexer, parser
```

* E. Kuleshov. Using the ASM framework to implement common Java bytecode transformation patterns.
* P. Lam, E. Boddeny, O. Lhotk and L. Hendren. The Soot framework for Java program analysis: a retrospective.

--------------

UML diagram 
1. Class visualizer
2. Intellij plugin
3. jGrasp
