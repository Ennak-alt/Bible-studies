#include <stdio.h>
#define MAXLINE 1000
#define IN 1
#define OUT 0
// 1-18 remove execessive blanks, and empty lines

int getLine(char line[], int maxline); 
int getLineNoBlanks(char s[], int lim);
void copy(char to[], char from[]);

int main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getLineNoBlanks(line, MAXLINE)) > 0) {
        printf("%s", line);
    }
    return 0;
}

int getLine(char s[], int lim) {
    int c, i;
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) 
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int getLineNoBlanks(char s[], int lim) {
    int c, i;
    int state = OUT;
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
        if (c == ' ' || c == '\t') {
            if (state == IN) 
                --i;
            else 
                state = IN;
                s[i] = ' '; 

        }
        else {
            state = OUT;
            s[i] = c;
        }
    }
        
    if (c == '\n') {
        if (i == 0) {
            s[0] = '\0';
            ++i;
        }
        else {
            s[i] = c;
            ++i;
            s[i] = '\0';
        }
    }
    
    return i;
}

void copy(char to[], char from[]) {
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0') 
        ++i;
}