#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "btree.h"
#include "getword.h"

#define MAXWORD 100

int main() {
    struct tnode *root;
    char word[MAXWORD];
    int linenumber = 1;
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word, linenumber);
        else if (word[0] == '\n')
            linenumber++;
    treeprint(root);
    return 0;
}