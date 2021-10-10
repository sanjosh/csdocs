
(Python Cookbook Chap 7)

any number of args - use * : def func(first, *many_args)

keyword args : use ** : def func (first, **kwarg)

accept certain args only by keyword - after * :  def func(a, *, b)

annotate arg : def func(x:int, y:bool) -> int: (no type checking done)

return multiple values : 

default args : def func(arg_with_def = 42):

lambda func :  f = lambda_func x y : x * y
capturing variables (closure) 

reduce num of args : functools.partial()

replace single method classes with function (function object)
def funcobj(template):
    def opener(**kwargs):
        return some_func(template, format_map(kwargs))
    return opener #return the function here

carry state in callback function : coroutine

inlining callback func: use generator and coroutine

