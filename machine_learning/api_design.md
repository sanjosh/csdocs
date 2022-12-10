
# API design for machine learning software: experiences from the scikit-learn project

https://arxiv.org/abs/1309.0238

1. consistency
1. inspection
1. non-proliferation of classes
1. composition
1. sensible defaults

the public interface is oriented towards processing batches of samples rather than single samples per API call

```
From the start, the choice to let a single object serve dual purpose as estimator and model has mostly been driven by usability and technical considerations.
From the user point of view, having two coupled instances (i.e., an estimator
object, used as a factory, and a model object, produced by the estimator) indeed decreases the ease of use and is also more likely to unnecessarily confuse
newcomers. From the developer point of view, decoupling estimators from models also creates parallel class hierarchies and increases the overall maintenance
complexity of the project. For these practical reasons, we believe that decoupling
estimators from models is not worth the effort. 
```

## extending

```
To ease code reuse, simplify implementation and skip the introduction of superfluous classes, the Python principle of duck typing is exploited throughout
the codebase. This means that estimators are defined by interface, not by inheritance, where the interface is entirely implicit as far as the programming
language is concerned. Duck typing allows both for extensibility and flexibility:
```

provide hooks

Our rule of thumb is that user code should not be tied to scikit-learn—which is a library, and not a framework
