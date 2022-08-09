To compile multiple source files, use `cc main.c getline.c strindex.c`, or to recompile one file, 
say main.c, use `cc main.c getline.o strindex.o`
Given the basic framwork, it's straightforward to extend the calculator. Add the modulus (%) 
operator and provisions for negative numbers.

Functions and external variables need not all be compiled at the same time, the source text of the program 
may be kept in several files, and previously compiled routines may be loaded from libraries.

A declaration announces the properties of a variable (it's type); a definition also causes storage to be set aside.
If `int spa; double val[MAXVAL];` appear outside of any function, they define the external variables sp and val,
cause storage to be set aside, and also serve as the declaration for the rest of that source file. 
On the other hand `extern int spa; extern double val[MAXVAL];`, declare for the rest of the source file
that sp is an int and that val is a double array, but they do not creat the variabels or reserve storage for them.

There must only be one definition, but other files may contain extern declarations to access them. 
Array sizes must be speicified with the definition, but are optional with an extern declaration.

There is a tradeoff between the desire that each file have access only to the information it needs for its job
and the practical reality that it is harder to maintain more header files. Up to some moderate program size, 
it is probably best to have on header file that contains everything that is to be shared between any 
two parts of the program.

The `static` declaration, applied to an external variabel of function, limits the scope of that object 
to the rest of the source file being compiled.

Internal static variables are local to a particular funciton just as automatic variables are, but
unlike automatics, they remain in existence rather that coming and going each time the function is 
activated. It therefore provides private, permanent storage withing a single function.

A register declaration advises the compiler that the variable in question will be heavily used. The 
idea is that register variables are to be placed in machine registers, which may result in smaller and 
faster programs. But compilers are free to ignore the advice.

A static variable is initialized only the first time the block is entered.

In the absence of explicit initialization, external and static variables are guaranteed to be initalized 
to zero. Automatic and register variables have underfined (i.e. garbage) initial values.

For external and static variables, the inializer must be a constant expression. For automatic and register 
variables, it is done each time the function or block is entered.

If there are fewer initalizers for an array than the number speciffied, the missing elements will be 
zero for external, static and automatic variables.

`#include` to include the contents of a file during compilation and `#define` to replace a token by 
an arbitrary sequence of characters.¨

If the filename that is included is quoted, searching for the file typically begins where the source 
program was found, if it is not found there, or if the name is enclosed in < and >, searching follows
an implementation-defined rule to find the file.

Macro substitution is by `#define`. Normally the replacement text is the res of the line, but a long definition may be continued onto several lines by placing a \ at the end of each line to be continued. `#define` works from the definition to the end of the source file. It is also possible to define macros with arguments, so the replacement text can be different for different calls of rhte macro, forexample:
```
#define max(A, B) ((A) > (B) ? (A) : (B))
```
There is some pit falls, for example square(z+1) will not have the desired effect. 

Names may be undefined with #undef, to ensure that a routine is really a function, and not a macro, you can use # in the parameter to make the parameter quoted. It is also possible to concatenate arguements with ## like 
```
#define paste(front, back) front ## back
```
which with `paste(name, 1)` creates the token name1.