// 1-13
#include <stdio.h>
#define IN 1
#define OUT 0
#define SIZE 93 // total printable ascii characters
// Did not want to count space and such with, to much workz
int main() {
    char c;
    int charNum = 0;
    int state = OUT;
    int charCount[SIZE];
    for (int i = 0; i < SIZE; i++) {
        charCount[i] = 0;
    }
    while((c = getchar()) != EOF) {
        if (c >= 33 && c <= 126)
            ++charCount[c-33];
    }
    for (int x = 0; x < SIZE; x++) {
        printf("%3c ", (x+33));
        for (int i = 0; i < charCount[x]; i++) {
            putchar('-');
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}