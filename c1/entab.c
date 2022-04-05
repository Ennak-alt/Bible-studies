// Exercise 1-21
#include <stdio.h>
#define MAXLINE 1000
#define TABSIZE 8
// Eh, it good enough

int getLine(char[], int);
void copy (char[], char[]);
void entabLine (char[]);

int main() {
    char line[1000];
    while(getLine(line, MAXLINE) > 0) {
        entabLine(line);
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

void entabLine(char line[]) {
    char entabbedLine[MAXLINE];
    int i, j;
    i = j = 0;
    for (; line[i] != '\0'; i++, j++) {
        if (i % TABSIZE == 0 && line[i-1] == ' ') {
            int blanks = 0;
            j--;
            while (blanks != TABSIZE && entabbedLine[j] == ' ') {
                blanks++;
                j--;
            }
            j++;
            entabbedLine[j] = '\t';
            j++;
            entabbedLine[j] = line[i];
        } 
        else 
            entabbedLine[j] = line[i];
    }
    entabbedLine[j] = '\0';
    copy(line, entabbedLine);
}