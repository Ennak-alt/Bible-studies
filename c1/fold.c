// Exercise 1-22
#include <stdio.h>
#define MAXLINE 1000
#define FOLDSIZE 5
// Æ, it good enough, without Æ

int getLine(char[], int);
void copy (char[], char[]);
void foldLine (char[]);

int main() {
    char line[1000];
    while(getLine(line, MAXLINE) > 0) {
        foldLine(line);
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

void foldLine (char line[]) {
    int i, j;
    char tempLine[MAXLINE];
    for (i = j = 0; line[i] != '\0'; ++i, ++j) {
        if (i % FOLDSIZE == 0 && i != 0 && tempLine[j] != '\n') {
            if (line[i-1] == ' ' || line[i-1] == '\t') {
                tempLine[j] = '\n';
            } else {
                if (line[i-1] != ' ') {
                    tempLine[j] = '-';
                    tempLine[++j] = '\n';
                    tempLine[++j] = line[i];
                } else {
                    tempLine[j] = '\n';
                    tempLine[++j] = line[i]; 
                }
            }
            // if (tempLine[j] == ' ' || tempLine[j] == '\t') {
            //     for (; tempLine[j] == ' ' || tempLine[j] == '\t'; --j)
            //         ;
            //     tempLine[j] = '\n';
            // } else {
            //     tempLine[j] = '-';
            //     tempLine[++j] = '\n';
            //     tempLine[++j] = line[i];
            // }
        } else 
            tempLine[j] = line[i];
    }
    tempLine[j] = '\0';
    copy(line, tempLine);
}