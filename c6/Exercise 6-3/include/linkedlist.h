#ifndef LINKEDLIST
#define LINKEDLIST

typedef struct node listnode;
typedef struct linkedlist list;

list *createlist(int);

void append(list*, int);

void printlist(list *);

#endif