#ifndef BTREE
#define BTREE

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *p, char *w);

void treeprint(struct tnode *p);

struct tnode *talloc(void);

#endif


