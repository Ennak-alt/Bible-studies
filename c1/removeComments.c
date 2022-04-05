// Exercise 1-23
#include <stdio.h>
#define MAXINPUT 10000
#define IN 0
#define OUT 1

// Remove comments from a file, æh comments

int getLine(char[], int);
void copy (char[], char[]);
void getInput(char[]);
void removeComments(char[]);

int main() 
{
    char input[MAXINPUT];
    getInput(input);
    removeComments(input);
    printf("%s\n", input);
    return 0;
}

void getInput(char s[]) 
{
    int c, i;
    for (i=0; (c=getchar())!=EOF; ++i) 
        s[i] = c;
    s[i] = '\0';
    return;
}

void removeComments(char input[]) {
    char temp[MAXINPUT];
    int i, j, inQuote;
    inQuote = OUT;
    for (i = j = 0; input[i] != '\0'; i++, j++) 
    {
        if (input[i] == '"') 
            inQuote = inQuote == IN ? OUT : IN;
        if (inQuote == OUT && input[i] == '/' && input[i+1] == '/') 
            while (input[i] != '\n')
                ++i;
        else if (inQuote == OUT && input[i] == '/' && input[i+1] == '*') 
        {
            ++i;
            while (input[i+1] != '\0' && !(input[i] == '*' && input[i+1] == '/'))
                ++i;
            i += 2; 
        } 
        temp[j] = input[i];
    }
    copy(input, temp);
    return;
}

int getLine(char s[], int lim) {
    int c, i;
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) 
        s[i] = c;
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0') 
        ++i;
}