
Debasis Ghosh - Mining Func patterns

PATTERN 1
* adding two maps with groupby
* replace it with combine op in Monoid with add or max operation
* they are just different modes of aggregation

PATTERN 2
* iterations over list = fold with different aggregation over binary func
* not really using list ops
* replace List with Foldable
* its a map reduce on Foldable trait

Difference between hadoop mapreduce and functional mapreduce.  in hadoop, ops in MapReduce have to be commutative; not in func programming

Twitter algebird - everythin is a monoid !

Antipatterns
* repetition
* imperative
* exception handling
* not modular

```
Handle exception and convert it to algebra of disjunction (Either data type). 
type ErrorOr[A] = Either[Exception, A]
```

For Config management, where u are reading various parameter

use monadic comprehension and algebraic composition

use Reader Monad (Kleisli ?) and Monad transformer 

```
def readConf(config:Config) : ErrorOr[KafkaSettings] = {
}
```

