// Exercise 1-20
#include <stdio.h>
#define MAXLINE 1000
#define TABSIZE 8

int getLine(char[], int);
void copy (char[], char[]);
void detabLine (char[]);

int main() {
    char line[1000];
    while(getLine(line, MAXLINE) > 0) {
        detabLine(line);
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

void copy(char to[], char from[]) {
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0') 
        ++i;
}

void detabLine(char line[]) {
    char detabbedLine[MAXLINE];
    int i, j;
    i = j = 0;
    for (; line[i] != '\0'; i++, j++) {
        if (line[i] == '\t') {
            if (j % TABSIZE == 0) {
                detabbedLine[j] = ' ';
                j++;
            }
            while ((j % TABSIZE) != 0) {
                detabbedLine[j] = ' ';
                j++;
            }
            j--;
        } 
        else 
            detabbedLine[j] = line[i];
    }
    detabbedLine[j] = '\0';
    copy(line, detabbedLine);
}