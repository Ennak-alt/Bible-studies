#include <stdio.h>
// Exercise 1-10

void printLiteral(char c) {
    switch(c) {
        case '\t':
            putchar('\\');
            putchar('t');
            break;
        case '\n':
            putchar('\\');
            putchar('n');
            break;
        case '\\':
            putchar('\\');
            putchar('\\');
            break;
        default:
            putchar(c);
            break;
    }
}

int main() {
    char c;
    while ((c = getchar()) != EOF) {
        printLiteral(c);
    }
    printf("\n");
    return 0;
}