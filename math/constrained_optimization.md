
# Lagrange multipliers

Constrained optimization : we want to find solution in a constrained input space defined by `g(x1,x2..)`

`Constrained optimization problem in N dimension` has same solution as  `Free optimization problem in N+1 dimension`

```
f(x,y,...)
g(x,y,...)
```

gradient field of g() is perpendicular to g(x,..) = 0

gradient field of g() is the direction we cannot go while searching input space

Two types of extrema
1. natural extrema of which happend to be on g=0
2. induced extrema : we cannot move in direction where f grows 

```
(D(f) = Lambda.D(g))

gradient of g is same direction as gradient of f

```

so create func `L = f - (lambda).g` 

Lagrange multipliers are easy to extend to more than one constraint.  Add one Lambda for each constraint.

## example

```
f(x, y) = 
g(x, y) = 

L(x, y) = f - (Lambda).g

take gradient (dL/dx, dL/dy, dL/dLambda) 

set all to zero
```


## ref

https://www.youtube.com/watch?v=s8j-pI_tPlM

