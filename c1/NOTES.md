# Chapter 1
**Running a simple program** \
`cc helloworld.c && ./a.out` \

**Piping file contents into outputfile** \
`cat helloWorld.c | ./a.out*` \

**Get input from user** \
`while((char c = getchar()) != EOF) {}` \

**Output** \
Either `putchar()` or `printf()` \

**Printing colors in a c program**
`\033[1;31mPRINTING CONTENTS:\033[1;33m\n"` \
Here `\033[1;31m` is red and `\033[1;33m` means gold \
To reset to original color use `\033[0m` \
To set bold set from 0 to 1 in code "\033[*(0 = normal or 1 = bold)*;33m"

**Get size of array**
To get the size of an array the following can be used: \
`int arr[10]` \
`int size = sizeof(arr)/sizeof(arr[0])` \

**Additional notes**
Function declarations should be before main, and then implementaition after, this is called the
"prototype"

Functions are default call by value, it is a copy of the original variable (not call by reference)

Although it is a different story for arrays, these are not a local copy

The null character `\0` is used to mark the end of a string of characters

The `extern` keyword can be used to get global variables

- [x] Exercise 1-1
- [x] Exercise 1-2
- [x] Exercise 1-3
- [x] Exercise 1-4
- [x] Exercise 1-5
- [x] Exercise 1-6
- [x] Exercise 1-7
- [x] Exercise 1-8
- [x] Exercise 1-9
- [x] Exercise 1-10
- [x] Exercise 1-11
- [x] Exercise 1-12
- [x] Exercise 1-13
- [x] Exercise 1-14
- [x] Exercise 1-15
- [x] Exercise 1-16
- [x] Exercise 1-17
- [x] Exercise 1-18
- [x] Exercise 1-19
- [x] Exercise 1-20
- [x] Exercise 1-21
- [x] Exercise 1-22
- [x] Exercise 1-23
- [ ] Exercise 1-24
