
# summary

CPU registers are wide (128 or 256 bit).  Can contain many int or float

all instructions except for "move data" use registers

add, subtract, multiply, compare, boolean, shift right or left

on overflow or underflow, result = largest or smallest number


# SIMD usage

-------------

* _mm_shuffle_pd

* _mm_permute_ps/pd - select elements from input

-------------------------------

typedefs in avxintrin.h

"v16si" - what is the suffix for types ?

```
qi -> char
hi -> short
si -> int
di -> long long
f -> float
d -> double
```

--------------------

typedef int v4si __attribute__ ((vector_size (16)));

The int type specifies the base type, the attribute specifies the vector size for the variable, measured in bytes. 

For example, the declaration above causes the compiler to set the mode for the v4si type to be 16 bytes wide and divided into int sized units. 

For a 32-bit int this means a vector of 4 units of 4 bytes, and the corresponding mode of foo is V4SI.

-------------------------------

AVX data types

```
__m128   128-bit vector containing 4 floats
__m128d  128-bit vector containing 2 doubles
__m128i  128-bit vector containing integers
__m256   256-bit vector containing 8 floats
__m256d  256-bit vector containing 4 double
__m256i  256-bit vector containing integers
```

--------------

function name convention

```_mm<bit_width>_<name>_<data_type>
```

The parts of this format are given as follows:

* <bit_width> identifies the size of the vector returned by the function. For 128-bit vectors, this is empty. For 256-bit vectors, this is set to 256.

* <name> describes the operation performed by the intrinsic

* <data_type> identifies the data type of the function's primary arguments

* This last part, <data_type>, is a little complicated. It identifies the content of the input values, and can be set to any of the following values:

```
ps - vectors contain floats (ps stands for packed single-precision)
pd - vectors contain doubles (pd stands for packed double-precision)
epi8/epi16/epi32/epi64 - vectors contain 8-bit/16-bit/32-bit/64-bit signed
integers
epu8/epu16/epu32/epu64 - vectors contain 8-bit/16-bit/32-bit/64-bit unsigned
integers
si128/si256 - unspecified 128-bit vector or 256-bit vector
m128/m128i/m128d/m256/m256i/m256d - identifies input vector types when they're
different than the type of the returned vector
```

----------------

```
$ g++ -mavx2 -mfma

#include <x86intrin.h>
#include <iostream>

typedef int v4si __attribute__ ((vector_size (16)));

__m128d in1_create(double min, double max)
{
  return (__m128d){min, max};
}
      
int main()
{
  v4si a{0, 0, 0, 0};
  v4si b{1, 2, 3, 4}; 
  v4si c{20, 19, 18, 17};

  long l;
                 
  a = b + c;    /* a = b + {1,1,1,1}; */

  for (int i = 0; i < 4; i++)
  {
    std::cout 
      << a[i] << ","
      << b[i] << ","
      << c[i] << std::endl;
  }

  auto x = in1_create(0.5, 3.5);

  std::cout << x[0] << "," << x[1] << std::endl;
}
```

======

https://github.com/vecio/3DM/blob/master/include/3dm/3dm.h

https://github.com/rikusalminen/threedee-simd

http://www.tommesani.com/index.php/simd/42-mmx-examples.html

https://en.wikipedia.org/wiki/Advanced_Vector_Extensions

https://en.wikipedia.org/wiki/FMA_instruction_set

http://stackoverflow.com/questions/11228855/header-files-for-simd-intrinsics

https://gcc.gnu.org/onlinedocs/gcc/Vector-Extensions.html

https://www.strchr.com/strcmp_and_strlen_using_sse_4.2

http://www.codeproject.com/Articles/874396/Crunching-Numbers-with-AVX-and-AVX

