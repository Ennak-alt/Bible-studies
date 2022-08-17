# What a pointer is
A pointer is a variable that contains the address of a variable. Poiters and arrays are closely related.

# Why are they used 
Are used much in C, partly because they are sometimes the only way to express a computation, and partly because they usually lead to more compact and efficient code.

# How memory is organized
A typical machine has an array of consecutively numbered or addressed memory cells that may be manipulated individually or in a group. Forexample a byte can be used for a char. A pointer is a group of cells (often two or four) that can hold an address. The `&` operator gives the address of an object  forexample `p = &c;` assigns teh address of c to the  variable `p`. The `*` is the *indirection* or *dereferencing* operator. This example shows hoe to use `&` and `*`:
```c
int x = 1, y = 2, z[10];
int *ip;      /* ip is a pointer to int */

ip = &x;      /* ip now points to x */
y = *ip;      /* y is now 1 */
*ip = 0;      /* x is now 0 */
ip = &z[0];   /* ip now points to z[0] */
```
Pointers are constrained to point to a particular kind of object (except a *pointer to void* which is used to hold any type of pointer but cannot be dereferenced itself). If `ip` points to the an integer, then `*ip` can occur in any context where x could: `*ip = *ip + 10`. The `*` and `&` bind more tightly than arithemetic operators. Remember `(*ip)++` where paranthese are necessaary since without them, the expression would incrememnt `ip` instedad of what it points to. You can also assign pointers to each other `iq = ip`, so now `iq` points to whatever `ip` pointed to.

# Function arguments
Since c passes arguments to functions by value, there is no direct way for the called function to alter a variable in the calling function. The way to obtain the desired effect is for the calling program to pass *pointers* to the values to be changed: `swap(&a, &b);`, since `&` produces the address of a variable, `&a` is a pointer to `a`. In `swap` itself, the parameters are declared to be pointers, adn the operands are accessed indirectly through them:
```c
void swap(int *px, int *py) {
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;
}
```
Pointer arguements enable a fucntion to access and change objects in the function that called it.

# Pointers and arrays
In C, there is a strong relationship between pointers and arrays. Any operation that can be achieved by array subscripting can also be done with pointers. The pointer ersion will in general be faster, but, at leas to the uninitiated, somewhat harder to understand.
If a pointer is set to the first element in an array `pa = &a[0];`, then `pa+i` points to the ith element in the array. So the name of an array is a sysnonym for the location of the initial element, so you could also write `pa = a`. That means `&a[i]` and `a+i` is also equivalent. One key difference, is that a pointer is a variable, so expressions like `pa++` are legal, but an array name is not a variabl, so `a++` is not legal. That means you can also write a function with an array as a parameter as `int strlen(char *s)`, it is therefore also possible to pass part of an array to a function, forexample `f(&a[2])` or `f(a+2)`.

# Address arithemetic
C is consistent and regular in its approach to address arithemetic; its intergation of pointers, arrays, and address arithemetic is one of the strengths of the language. To illustrate a rudiementary storage allocator:
```c
#define ALLOCSIZE 100000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
    allocp += n;
    return allocp - n; /* old p */
  } else  /* not enough room */
    return 0;
}

void afree(char *p) { /* free storage pointed to by p */
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}
```
C guarantees that zero is never a valid address of data, so a return value of zero can be used to signal an abornaml event. Pointers and integers are not interchangeable. Zero is the sole exception: the constant zero may be assigned to a pointer, and a pointer may be compared with the constant zero. NULL is more normally used in place of zero, to more clearly indicate that this is a special value for a pointer.
Pointers may be compared under certain cicumstances. If p and q pointer to members of the same array, then relations like ==, !=, <, >=, etx., work properly. For example p < q is trye if p points to an earlier member of the array than q does

# Character pointers and functions
A string constant written as `"I am a string"`, is an array of characters.

# Pointers vs. Multi-dimensional Arrays
The important advantage of the pointer array is that the rows of the array may be of different lengths. The most frequent use of arrays of pointers is to store character strings of diverse lengths, as in the function month_name.

# Commandline arguments
Argc is argument count, argv is the argument vector, which is a pointer to an array of character strings. argv[0] is the name by which the program was invoked, so argc is at least 1. Minus sign is a common convention for an optional flag 



