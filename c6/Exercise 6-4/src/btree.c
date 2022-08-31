#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "btree.h"

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

struct tnode *copynode(struct tnode *p, struct tnode *p2) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = p2->word;
        p->count = p2->count;
        p->left = p->right = NULL;
    }
    else if (p->count - p2->count > 0)
        p->left = copynode(p->left, p2);
    else
        p->right = copynode(p->right, p2);
    return p;
}

struct tnode *constructCountTree(struct tnode *newtree, struct tnode *tree) {
    if (tree != NULL) {
        newtree = copynode(newtree, tree);
        constructCountTree(newtree, tree->left);
        constructCountTree(newtree, tree->right);
    }
    return newtree;
}

void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}
