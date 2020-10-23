
using LLVM

https://github.com/SVF-tools/SVF

-------------

Android

https://arxiv.org/abs/1804.02903
Do Android Taint Analysis Tools Keep their Promises?

Challenges
1. Handle component lifecycles
2. Inter-component communication - Intents can propagate data
3. Intra-Component
3. Reflection
4. NDK

All tools except Amandroid are based on Soot [16, 25] 
https://sable.github.io/soot/

operate on Jimple as intermediate language.

Source and Sink specified using SuSi

IAC = Inter-app comm 
ICC = Inter-component comm

=============

Amandroid : ICC

http://pag.arguslab.org/argus-saf

https://github.com/arguslab/Argus-SAF

=============
DialDroid : IAC, ICC
https://github.com/dialdroid-android/DIALDroid
=============

DidFail : IAC, ICC

https://www.wklieber.com/didfail/
https://resources.sei.cmu.edu/library/asset-view.cfm?assetID=508078
=============

DroidSafe : IAC, ICC
development stopped sine 2016
last supported version is Android 4.4.1

https://github.com/MIT-PAC/droidsafe-src
=============
FlowDroid : ICC

https://github.com/secure-software-engineering/FlowDroid

=============
IccTA : ICC

https://sites.google.com/site/icctawebpage/

https://github.com/lilicoding/soot-infoflow-android-iccta
=============

Use ApkCombiner

jadx to decompile

EpiCC
http://siis.cse.psu.edu/epicc/
