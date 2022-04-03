#include <stdio.h>
#define MAXLINE 1000
// 1-16 Revise so it correcly print the length of arbitrarily long input lines, and as much as 
// possible of the text, here i have chosen just to print 1000 chars.

long getLine(char line[], long maxline); 
void copy(char to[], char from[]);

int main() {
    long len;
    long max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("Chars in line: %ld\nLine: %s\n", max, longest);
    return 0;
}

long getLine(char s[], long lim) {
    int c;
    long i;

    for (i=0; (c=getchar()) != EOF && c!='\n'; ++i) 
        if (i<lim-1) 
            s[i] = c;
    if (c == '\n') {
        ++i;
    }
    if (i > lim-1)
        s[lim-1] = '\0';
    else 
        s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0') 
        ++i;
}