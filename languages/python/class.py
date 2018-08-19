#!/usr/bin/python

'''
    https://docs.python.org/2/reference/datamodel.html
'''

class Empty:
    pass

#base class is object
class BankAccount(object):
#__doc__ next string becomes doc
    """ Bank acount class """

# static variable
    class_variable="bank"

#__new___??

#default args
    def __init__(self, initial_balance=0):
        self.balance = initial_balance
        self.index = 0 # for iter

# cmp called when class instances compared
    def __cmp__(self, dict):
        pass

# representation
# for bytes(x)
    def __bytes__(self):
        pass
    def __format__(self, format_spec):
        pass
# return a valid python expr
    def __repr__(self):
        pass
# when u call print(x)
    def __str__(self):
        pass


    def __new__(cls, *args, **kwargs):
        new_inst = super(BankAccount, cls).__new__(cls, *args, **kwargs)
#        new_inst = object.__new__(cls, *args, **kwargs)
        return new_inst
# called on last dereference
# exceptions raised in dtor are ignored
    def __del__(self):
        pass
    def __hash__():
        pass
# isinstance()
    def __instancecheck__(self):
        pass
# issubclass():
    def __subclasscheck__(self):
        pass
# issubclass()
    def __subclasshook__(self):
        pass

# for classes that act like sets
# called on "x in s"
    def __contains__(self, x):
        pass
# len 
    def __len__(self):
        return 4

# FOR CLASSES THAT ACT LIKE DICTIONARIES
    def __delitem__(self, key):
        pass
    def __setitem__(self, key):
        pass
    def __getitem__(self, key):
        pass
    def __missing__(self, non_existent_key):
        pass

# FOR CLASSES THAT ACT LIKE NUMBERS
    def __add__(self, other):
        pass
    def __sub__(self, other):
        pass
    def __mul__(self, other):
        pass
    def __truediv__(self, other):
        pass
# when x // y
    def __floordiv__(self, other):
        pass
    def __mod__(self, other):
        pass
# when divmod(x,y)
    def __divmod__(self, other):
        pass
    def __pow__(self, other):
        pass
    def __lshift__(self, other):
        pass
    def __rshift__(self, other):
        pass
    def __and__(self, other):
        pass
    def __xor__(self, other):
        pass
    def __or__(self, other):
        pass
# the r variants  for when self is 2nd arg
    def __radd__(self, other):
        pass
    def __rsub__(self, other):
        pass
    def __rmul__(self, other):
        pass
    def __rtruediv__(self, other):
        pass
# when x // y
    def __rfloordiv__(self, other):
        pass
    def __rmod__(self, other):
        pass
# when divmod(x,y)
    def __rdivmod__(self, other):
        pass
    def __rpow__(self, other):
        pass
    def __rlshift__(self, other):
        pass
    def __rrshift__(self, other):
        pass
    def __rand__(self, other):
        pass
    def __rxor__(self, other):
        pass
    def __ror__(self, other):
        pass
# the i variants  for adding to oneself (i.e x <<= y)
    def __iadd__(self, other):
        pass
    def __isub__(self, other):
        pass
    def __imul__(self, other):
        pass
    def __itruediv__(self, other):
        pass
# when x // y
    def __ifloordiv__(self, other):
        pass
    def __imod__(self, other):
        pass
# when divmod(x,y)
    def __idivmod__(self, other):
        pass
    def __ipow__(self, other):
        pass
    def __ilshift__(self, other):
        pass
    def __irshift__(self, other):
        pass
    def __iand__(self, other):
        pass
    def __ixor__(self, other):
        pass
    def __ior__(self, other):
        pass
# unary ops
    def __neg__(self):
        pass
    def __pos__(self):
        pass
    def __abs__(self):
        pass
    def __invert__(self):
        pass
    def __complex__(self):
        pass
    def __int__(self):
        pass
    def __float__(self):
        pass
    def __round__(self):
        pass
    def __round__(self, n):
        pass
    def __ceil__(self, x):
        pass
    def __floor__(self, x):
        pass
    def __trunc__(self, x):
        pass
# called on a_list[x]
    def __index__(self): 
        pass

# compare ops
    def __eq__(self, y):
        pass
    def __ne__(self, y):
        pass
    def __lt__(self, y):
        pass
    def __le__(self, y):
        pass
    def __gt__(self, y):
        pass
    def __ge__(self, y):
        pass
# called on if x:
    def __bool__(self):
        pass
    def __nonzero__(self):
        pass
    def __unicode__(self):
        pass

# class creation
    #__metaclass__="

# SERIALIZE classes
# copy.copy(x)
    def __copy__(self):
        pass
# copy.deepcopy(x)
    def __deepcopy__(self):
        pass
# pickle.dump(x, file)
    def __getstate__(self):
        pass
# pickle.dump(x, file)
    def __reduce__(self):
        pass
# pickle.dump(x, file, protocol version)
    def __reduce_ex__(self, protocol_version):
        pass
# x =pickle.load(file)
    def __setstate__(self):
        pass
# x = pickle.load(file)
    def __getnewargs__(self):
        pass

# for use with "with x:"
    def __enter__():
        pass
    def __exit__(exc_type, exc_value, traceback):
        pass

# called on every ref to attr or method name
    def __getattribute__(self, key):
        pass
# fallback called on every ref to attr
    def __getattr__(self, key):
        pass
# called on every set to attr 
    def __setattr__(self, key, val):
        pass
# called on every delete attr (i.e. del x.var)
    def __detattr__(self):
        pass
# called on dir(x) - list all attrs and methods
    def __dir__(self):
        pass

# CLASS WHICH ACTS LIKE FUNC - i.e. operator()
# called when u type myinstance()
    def __call__(self):
        pass

# CLASSES THAT ACT LIKE ITERATORS
# iter must return some obj (need not be self) which has next method
    def __iter__(self):
        return self
# next method must increment index
    def __next__(self):
        if self.index == 1:
            raise StopIteration
        self.index = self.index + 1
        return self.balance
    def __reversed__(self):
        pass
# defined generator
    def generate(self):
        yield self.balance


# all methods virtual by default

    def deposit(self, amount):
        self.balance += amount
    def withdraw(self, amount):
        self.balance -= amount
    def overdrawn(self):
        return self.balance < 0

# no private variables but name prefixed with _ is considered non-public

# identifier with atleast 2 leading __ is replaced by _classname__ident
    def override_overdrawn(self):
        return self.__overdrawn()

# make pvt copy of method so it can be called from within
    __overdrawn = overdrawn 


# main code follows
if __name__ == "__main__":
    my_account = BankAccount(15)

    print my_account.__class__
    print my_account.__doc__
    
# ptr to func
    wptr = my_account.withdraw
    
    wptr(5)
    print my_account.balance

    print my_account.override_overdrawn()

    print "using iterator" 
    for i in my_account:
        print i
    
    print "using generator which generates iter and next"
    for ch in my_account.generate():
        print ch
# isinstance(obj, type1), issubclass(type1, type2), istype
