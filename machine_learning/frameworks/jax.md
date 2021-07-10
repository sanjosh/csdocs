


# Jax

Jax - (like Autograd 2.0)

JAX uses XLA for array-level program optimization and code generation

JAX is built atop the same tracing library used within Autograd, which, being designed for self-closure, recognizes its own operations as primitives.

The acronym JAX stands for “just after execution”, since to compile a function we first monitor its execution once in Python.

https://mlsys.org/Conferences/2019/doc/2018/146.pdf

```
from jax import grad

@jit
def simple_fun(x):
  return np.sin(x) / x

 Return the gradient of simple_fun with respect to x

grad_simple_fun = grad(simple_fun)
grad_grad_simple_fun = grad(grad(simple_fun))
```

jacobian, hessian

forward-mode

reverse-mode

backprop = reverse-mode autodiff

```
https://iaml.it/blog/jax-intro-english
```

## Stax in Jax

build neural networks, with an interface similar to other deep learning frameworks

## MinMax in Jax

optimization of cost functions.

## four func transformations 

grad : differentiate

jit : auto-optimize (also as func decorator)

vmap : map func across dimensions

pmap : map processes across multiple processors

## jax vs pytorch

jax lacks data loader
