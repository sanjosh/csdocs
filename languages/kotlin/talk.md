
1. null safety (?)
1. Higher order func
1. extensions func : final type can be extended
1. data classes

1. add annotations to close gaps
1. JvmOverloads : default param
1. JvmStatic : static 
1. Throws : checked exception

1. Intellij : suspending functions indicator
1. Add Kapt, Gradle 5

## Watch out
1. Kotlin classes are final by default : mockito 1 needs classes to be open; or use Mockk
1. Jackson mappers needs some small changes : mapper.registerModule(kotlinModule)
1. Lombok integration issues

## Coroutine
1. wait for all children
1. automatic cancellation of children
1. context and dispatchers
1. IO dispatcher has only 64 threads

* Mockk : mockito for. kotlin
* ktlint : linter
* deteket : findbugs
* koin : dependency injection (also kodein)

