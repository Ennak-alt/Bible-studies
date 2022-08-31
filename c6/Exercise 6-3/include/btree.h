#ifndef BTREE
#define BTREE

struct tnode *addtree(struct tnode *p, char *w, int linenumber);

void treeprint(struct tnode *p);

struct tnode *talloc(void);

#endif


