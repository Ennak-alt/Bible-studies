#include <stdio.h>

// Exercise 1-8: Write program to count blanks, tabs, and newlines.

int main() {
    int c, n1, n2, n3;
    n1 = n2 = n3 = 0;
    while((c = getchar()) != EOF) {
        if (c == '\n')
            ++n1;
        else if (c == '\t')
            ++n2;
        else if (c == ' ')
            ++n3;
    }
    printf("\nnewlines: %d, tabs: %d, blanks: %d \n", n1, n2, n3);
    return 0;
}