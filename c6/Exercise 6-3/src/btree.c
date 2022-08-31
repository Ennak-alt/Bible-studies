#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linkedlist.h"
#include "btree.h"

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
    list *linenumbers;
};

struct tnode *addtree(struct tnode *p, char *w, int linenumber) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->linenumbers = createlist(linenumber);
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;
        append(p->linenumbers, linenumber);
    }
    else if (cond < 0)
        p->left = addtree(p->left, w, linenumber);
    else
        p->right = addtree(p->right, w, linenumber);
    return p;
}

void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        printlist(p->linenumbers);
        treeprint(p->right);
    }
}

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}
