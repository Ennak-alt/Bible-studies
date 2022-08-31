#include <stdlib.h>

#include "linkedlist.h"
#include "stdio.h"

struct node {
    int val;
    struct node *nxt;
};

struct linkedlist {
    struct node *startnode;
    struct node *endnode;
};

listnode *createnode(int val) {
    listnode *newnode = (listnode *) malloc(sizeof(listnode));
    newnode->val = val;
    newnode->nxt = NULL;
    return newnode;
}

list *createlist(int val) {
    list *newlist = (list *) malloc(sizeof(list));
    newlist->startnode = createnode(val);
    newlist->endnode = newlist->startnode;
		return newlist;
}

void append(list *l, int val) {
    l->endnode->nxt = createnode(val);
    l->endnode = l->endnode->nxt;
}

void printlist(list *l) {
    listnode *node = l->startnode;
    while (node != NULL) {
        printf ("\t|%4d| -> \n", node->val);
        node = node->nxt;
    }
}