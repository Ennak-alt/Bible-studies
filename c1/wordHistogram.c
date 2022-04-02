// 1-13
#include <stdio.h>
#define IN 1
#define OUT 0
#define SIZE 15
int main() {
    char c;
    int charNum = 0;
    int state = OUT;
    int charCount[SIZE];
    for (int i = 0; i < SIZE; i++) {
        charCount[i] = 0;
    }
    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                if (charNum-1 < SIZE)
                    ++charCount[charNum-1];
                charNum = 0;
                state = OUT;
            }
        }
        else {
            ++charNum;
            state = IN;
        }
    }
    int max = 0;
    for (int i = 0; i < SIZE; i++) {
        max = (charCount[i] > max) ? charCount[i] : max;
    }
    for (int x = max; x > 0; x--) {
        printf("%3d ", x);
        for (int i = 0; i < SIZE; i++) {
            if (charCount[i] >= x) {
                printf("||    ");
            } else {
                printf("      ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < SIZE; i++) {
        printf("    %2d", (i+1));
    }
    printf("\n");
    return 0;
}