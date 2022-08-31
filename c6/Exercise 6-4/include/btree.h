#ifndef BTREE
#define BTREE

struct tnode *addtree(struct tnode *p, char *w);

struct tnode *copynode(struct tnode *p, struct tnode *p2);

struct tnode *constructCountTree(struct tnode *newtree, struct tnode *tree);

void treeprint(struct tnode *p);

struct tnode *talloc(void);

#endif


