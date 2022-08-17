#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(int argc, char **argv) {
  char *str;
  int temp;
  while(--argc > 0) {
    str = *++argv;
    if (*(str+1) == '\0') {
      switch(*str) {
        case '+':
          push(pop() + pop());
          break;
        case '-':
          temp = pop();
          push(pop() - temp);
          break;
        case '*':
          push(pop() * pop());
          break;
        case '/':
          temp = pop();
          push(pop() / temp);
          break;
        default:
          if (isdigit(*str))
            push(atoi(str));
          break;
      }
    }
    else 
      push(atoi(str));
  }
  printf("Result: %d\n", pop());
  return 0;
}