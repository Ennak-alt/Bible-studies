#include <stdio.h>

// Exercise 1-6 Verify that the expression getchar() != EOF is 0 or 1.
// Exercise 1-7 Write a program to print the value of EOF.

/* copy input to output; 2nd version */
int main() {
    int c;
    printf("EOF: %d\n", EOF);
    while((c = getchar()) != EOF)
        printf("%c EOF: %d\n", c, EOF);
        putchar(c);
    printf("%c EOF: %d\n", c, EOF);
    return 0;
}