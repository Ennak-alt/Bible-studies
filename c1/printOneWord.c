// Exercise 1-12: Output every word
#include <stdio.h>
#define IN 1
#define OUT 0
int main() {
    char c;
    int state = IN;
    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                putchar('\n');
                state = OUT;
            }
        }
        else {
            putchar(c);
            state = IN;
        }
    }
}