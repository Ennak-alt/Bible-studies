#include <stdio.h>

int main() {
    char c;
    int hasMetChar = 0;
    for(int i = 0; (c = getchar()) != EOF; i++) {
        if (i == 0) printf("\033[1;31mPRINTING CONTENTS:\033[0;33m\n");
        if (c == ' ' && !(hasMetChar)) {
            putchar(c);
            hasMetChar = 1;
        }
        else if (c != ' ') {
            putchar(c);
            hasMetChar = 0;
        }
    }
    printf("\n");
    return 0;
}