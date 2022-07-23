First character in names of variables must be a letter.
Traditionally C is to use lower case for variable names, and all upper case for symbolic constants.

There are only a few basic data types in C:
- `char`: single bute, capable of holding one character in the logical character set.
- `int`:  typically reflecting the natural size of intergers on the host machine.
- `float`: single-precision floating point.
- `double`: double-precision floating point.
In addition there are a number of qualifiers that can be  applied to these basic types, `short` and 
`long` apply to integers. `short` is often 16 bits and `long` 32 bits.
`signed` and `unsigned` may be applied to `char`or any integer.
`unsigned` numbers are always positive or zero, and obey the laws of arithemtic modulo 2^n, where n is the 
number of bits in the type.

Hexadecimal number can be written with the `0x` prefix, and octal can be written with the prefix `0`.

It's possible to write strings over multiple lines like:
```
char c[] =
  "Hello " 
  "World"
```

Every string has the null character, so they all technically hold one more space for that character.
Therefore `'x'` is not at all the same as `"x"` because with string literals, there is an 'invisible'
`'\0'` at the end.

There exists *enumeration constant*. It is a list of constant integer values, as in:
`enum bollean { NO, YES };`, so here NO has the value 0, and YES has the value 1. It is also possible,
to determine where to start, forexample: `enum months { JAN = 1, FEB, MAR, APR}` It is also possible to 
specify every value `enum escapes { BELL = '\a', BACKSPACE = '\b'}`.

const can be used with array arguments to specify, that it will not be altered: `strlen(const char[]);`.

1 - is true 
0 - is false 
in a logical expression.

Type conversions are automatic narrow to wider, to not lose information. 

`<ctype.h>` is a standard header that provides tests and conversions that are independent of character
set. For example `tolower`.

Explicit type conversions can be forced ("coerced") in any expression, with a unary operator called a 
cast: `(type-name) expression`.

If arguments are declared by a function prototype, the declaration causes automatic coercien of any 
arguments when the function is called. 


