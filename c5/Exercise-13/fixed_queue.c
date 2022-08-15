#include <stdio.h>
#include <string.h>

#define STORESIZE 4
#define QUESIZE 1000

static char storage[STORESIZE];
static char *nxta = storage;
static char *nxtd = NULL; 
static char *end = storage+STORESIZE; // pointer to end of storage

static int qi = 0; // elment to delete
static int max; // max number of elements

static void freeq(char **queue, int max) {
  nxtd = queue[((qi+1) % max)];
}

void alloc(char *s, char **queue, int max) {
  if (qi >= max) {
    printf("|%s|\n", s);
    freeq(queue, max);
  }
  int slen = strlen(s);
  if (nxta < nxtd && nxta+slen >= nxtd) {
    printf("Not enough space\n");
    return;
  } else if (nxta+slen >= end) {
    if (storage+slen < nxtd) {
      nxta = storage;
    }
    else {
      printf("Not enough space store: %s\n", s);
      return;
    }  
  }
  strcpy(nxta, s);
  queue[qi++ % max] = nxta;
  nxta += slen+1;
}

void printq(char **queue, int max) {
  printf("%s\n|", storage);
  for(int i = 0; i < STORESIZE; i++) {
    printf("%c", storage[i]);
  }
  printf("|\n");
  for(int i = 0; i < max; i++)
    printf("%s\n", queue[i]);
}