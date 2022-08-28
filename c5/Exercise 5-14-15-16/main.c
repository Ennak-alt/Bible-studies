#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "io.h"

#define MAXLINES 5000
char *lineptr[MAXLINES];

void qsort_(char *lineptr[], int left, int right, int reverse,
            int (*comp)(void *, void *));

int numcmp(char *, char *);

int strcmp_(char *, char *);

int fold, directory, numeric, reverse, field, col;

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;
    field = 0;
    if (argc > 1 && strcmp_("-field", *(argv + 1)) == 0)
    {
        field = 1;
        --argc;
        argv += 2;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) < 0)
    {
        printf("input too big to sort\n");
        return 1;
    }
    do
    {
        fold = directory = numeric = col = 0;
        reverse = 1;
        if (field)
        {
            col = atoi(*argv);
            --argc;
            if (col < 0)
            {
                printf("Collumn number not valid\n");
                return 1;
            }
        }
        while (--argc > 0)
        {
            int sl = strlen(*++argv);
            if (isdigit(*(*argv)) && field)
            {
                argc += 2;
                break;
            }
            if (sl == 2 && *(*argv) == '-')
                switch (*(*argv + 1))
                {
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = -1;
                    break;
                case 'f':
                    fold = 1;
                    break;
                case 'd':
                    directory = 1;
                    break;
                }
        }
        qsort_((char **)lineptr, 0, nlines - 1, reverse,
               (int (*)(void *, void *))(numeric ? numcmp : strcmp_));
    } while (--argc > 0);
    writelines(lineptr, nlines);
    return 0;
}

void separatefield(int *start, int *end, int fieldcol, char *str) {
    int i, j;
    for (i = j = 0; i < fieldcol; j++)
        if (*str == EOF)
            return;
        else if (*str++ == '|')
            i++;
    *start = j;
    while (*str != '\0' && *str++ != '|')
        j++;
    *end = j;
}

void qsort_(char *v[], int left, int right, int reverse,
            int (*comp)(void *, void *))
{
    int i, last, start1, start2, end1, end2;
    char temp1, temp2;
    void swap(char *v[], int, int);
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    start1 = start2 = 0;
    for (i = left + 1; i <= right; i++) {
        if (field) {
            separatefield(&start1, &end1, col, v[i]);
            separatefield(&start2, &end2, col, v[left]);
            temp1 = *(v[i]+end1);
            temp2 = *(v[left]+end2);
            *(v[i]+end1) = '\0';
            *(v[left]+end2) = '\0';
        }
        if (reverse * (*comp)(v[i]+start1, v[left]+start2) < 0) {
            if (field) {
                *(v[i]+end1) = temp1;
                *(v[left]+end2) = temp2;
            }
            swap(v, ++last, i);
        } else {
            if (field) {
                *(v[i]+end1) = temp1;
                *(v[left]+end2) = temp2;
            }
        }
    }
    swap(v, left, last);
    qsort_(v, left, last - 1, reverse, comp);
    qsort_(v, last + 1, right, reverse, comp);
}

int strcmp_(char *s, char *t)
{
    if (directory)
    {
        while (!isalnum(*s) && !isblank(*s))
            s++;
        while (!isalnum(*t) && !isblank(*t))
            t++;
    }
    for (; *s == *t || (fold && tolower(*s) == tolower(*t)); s++, t++)
    {
        if (directory)
        {
            while (!isalnum(*(s + 1)) && !isblank(*(s + 1)))
                s++;
            while (!isalnum(*(t + 1)) && !isblank(*(t + 1)))
                t++;
        }
        if (*s == *t && *s == '\0')
            return 0;
    }
    return fold ? tolower(*s) - tolower(*t) : *s - *t;
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(char *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}