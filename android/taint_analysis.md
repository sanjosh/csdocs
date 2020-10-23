# Problem statement

Determine if data read from one program location is consumed in another location.

# Challenges wrt Android

Ability to track data movement
    1. across component lifecycles
    2. across inter-component communication (intents and intent filters)
    3. Via use of Reflection
    4. NDK

# Overview

Static tools

Dynamic tools

# Dynamic taint analysis tools

AppFence

TaintDroid

# Static taint analysis tools

## Amandroid

Project page : http://pag.arguslab.org/argus-
Source code : https://github.com/arguslab/

## DialDroid

Source code : https://github.com/dialdroid-

## DidFail

https://www.wklieber.com/
https://resources.sei.cmu.edu/

## DroidSafe

Development has stopped since 2016
Last supported version is Android 4.4.1
Source code : https://github.com/MIT-PAC/

## FlowDroid

Source code : https://github.com/secure-

## IccTA

Project page : https://sites.google.com/site/
Source code : https://github.com/lilicoding/

# Related tools/concepts

## JADX

Decompiler

## Soot

https://sable.github.io/soot/
Paper : https://sable.github.io/soot/
Introduced Baf, Jimple and Grimp.

## Jimple

A typed 3-address intermediate representation

## SuSi

A tool to automatically discover and categorize sources and sinks in the Android framework

Source code : https://github.com/secure-

## using LLVM

https://github.com/SVF-tools/SVF


## EpiCC

http://siis.cse.psu.edu/epicc/

# References

1. Felix Pauck, et al.  Do Android Taint Analysis Tools Keep their Promises? 2018 (arxiv)
2. https://github.com/brucespang/

