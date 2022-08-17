#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "getline.h"
#include "fixed_queue.h"
#define QUEUESIZE 10000 // Max tail lines

int main(int argc, char **argv) {
  char *queue[QUEUESIZE];
  char *str;
  char *input;
  int n;
  str = *++argv;
  if (argc == 1) {
    n = 10;
  }
  else if (*str == '-' && *(str+1) != '\0') {
    input = str+1;
    while (*++str != '\0') {
      if (!isdigit(*str)) {
        printf("To use tail: \"tail -n\", where \"n\" is a number.\n");
        return EAGAIN;
      }
    } 
    n = atoi(input);
  } else {
    printf("To use tail: \"tail -n\", where \"n\" is a number.\n");
    return EAGAIN;
  }
  char temp[1000];
  while(getlinev2(temp, 1000) > 0)
    alloc(temp, queue, n);
  printq(queue, n);
  return 0;
}
