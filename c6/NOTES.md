# Introduction Structures
A structure is a collection of one or more variables, possible of different ypes, grouped together under a single name for convenient handling. They help to organize complicated data, particularly in large programs, because they permit a group of related variables to be treated as a unit instead of as separate entities.

# Structure declaration and use
```c
// Declaration
struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
}

// Initialization
struct point pt;
struct point maxpt = { 320, 200 };

// Member access
printf("%d, %d", pt.x, pt.y);

// Passed and returned in functions
struct point addpoint(struct point p1, struct point p2) 
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}
// It works cause its by value

/* If a large structure is to be passed to a function, it is generallly more efficient to pass a pointer than to copy the whole structure */
struct point *pp;
(*pp).x
(*pp).y
```

`.` has higher precedence than `*`. Pointers to structures are so frequently used that an alternative notation is provided as a shorthand. If p is a pointer to a structure, then
`p->member-of-structure`refers to the particular member.
```c
(*pp).x /* is the same as */ pp->x

// These expressions are equivalent
r.pt1.x
rp->pt1.x
(r.pt1).x
(rp->pt1).x
```
The structure operators . and -> togeether with () for function calls and [] for subscripts, are at the top of the precedence hierachy.

# Arrays of Structures
The following is perfectly legal because it works the same way as `struct key keytab[NKEYS]`:
```c
struct key {
    char *word:
    int count;
} keytab[NKEYS];
```
C provides a compile-time unart operator called sizeof that can be used to compute the size of any object: `sizeof`. Like `sizeof object` for specific object or `sizeof(type name)` for a type. Sizeof produces an unsigned integer value whose type, size_t, is defined in the header <stddef.h>. An object can be a variable or array or structure. 
