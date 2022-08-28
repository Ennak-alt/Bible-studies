#include <stdio.h>
#include <string.h>
#include "fixed_queue.h"

#define STORESIZE 1000000

static char storage[STORESIZE];
static char *nxta = storage;
static char *nxtd = NULL;
static char *end = storage + STORESIZE;

static int qi = 0;
static int max;

static void freeq(char **queue, int max) {
    nxtd = queue[((qi + 1) % max)];
}

void alloc(char *s, char **queue, int max) {
    if (qi >= max)
        freeq(queue, max);
    int slen = strlen(s);
    if (nxta < nxtd && nxta + slen >= nxtd) {
        printf("Not enough space\n");
        return;
    } else if (nxta + slen >= end) {
        if (storage + slen < nxtd) {
            nxta = storage;
        } else {
            printf("Not enough space store: %s\n", s);
            return;
        }
    }
    strcpy(nxta, s);
    queue[qi++ % max] = nxta;
    nxta += slen + 1;
}

void printq(char **queue, int max) {
    max = qi < max ? qi : max;
    for (int i = 0; i < max; i++)
        printf("%s", queue[(qi + i) % max]);
}