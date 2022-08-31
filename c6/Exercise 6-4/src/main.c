#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "btree.h"
#include "getword.h"

#define MAXWORD 100

int main() {
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    struct tnode *countroot;
    countroot = NULL;
    countroot = constructCountTree(countroot, root);
    treeprint(countroot);
    return 0;
}