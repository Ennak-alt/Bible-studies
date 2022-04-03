# Running a simple program:
`cc helloworld.c && ./a.out`

# Piping file contents into outputfile:
`cat helloWorld.c | ./a.out*`

# Get input from user:
`while((char c = getchar()) != EOF) {}`

# Output:
Either `putchar()` or `printf()`

# Printing colors in a c program:
`\033[1;31mPRINTING CONTENTS:\033[1;33m\n"`
Here `\033[1;31m` is red and `\033[1;33m` means gold
To reset to original color use `\033[0m`
To set bold set from 0 to 1 in code "\033[*(0 = normal or 1 = bold)*;33m"

# Get size of array:
**To get the size of an array the following can be used:**
`int arr[10];`
`int size = sizeof(arr)/sizeof(arr[0])`

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
