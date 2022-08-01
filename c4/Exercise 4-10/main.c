#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAXOP   100
#define NUMBER  '0'
#define VARMAX  26
#define VAR     '1'
#define MAXLINE 1000

#define TOP       'T'
#define DUPLICATE 'D'
#define SWAP      'W'
#define CLEAR     'C'
#define SIN       'S'
#define EXP       'X'
#define POW       '^'

int getop(char [], char []);
void push(double);
double pop(void);
void clear(void);
int getl(char [], int);

int main() {
  int type;
  double op2, num, sndNum;

  char inp[MAXLINE];
  char s[MAXOP];

  double vars[VARMAX];
  int taken[VARMAX] = {0};

  double lp = 0;

  getl(inp, MAXLINE);
  while ((type = getop(inp, s)) != EOF) {
    switch(type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        push(fmod(pop(), op2));
        break;
      case '^':
        op2 = pop();
        push(powf(pop(), op2));
        break;
      case '#':
        push(lp);
        break;
      case SIN:
        push(sin(pop()));
        break;
      case EXP:
        push(exp(pop()));
        break;
      case TOP: 
        num = pop();
        printf("\tTop: %.8g\n", num);
        push(num);
        break;
      case DUPLICATE:
        num = pop();
        push(num);
        push(num);
        break;
      case SWAP:
        num = pop();
        sndNum = pop();
        push(num);
        push(sndNum);
        break;
      case CLEAR:
        clear();
        break;
      case '\n':
        printf("\t%.8g\n", lp = pop());
        getl(inp, MAXLINE);
        break;
      default:
        if (islower(type)) {
          int index = type - 'a';
          if (taken[index])
            push(vars[index]);
          else  {
            taken[index] = 1;
            vars[index] = pop();
          } 
          break;
        }
        else 
          printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else 
    printf("error: stack full, can't push %g\n", f);
}

void clear(void) {
  for (;sp > 0; sp--)
    pop();
}

double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

// int getop(char s[]) {
//   int i, c;
//   while ((s[0] = c = getch()) == ' ' || c == '\t')
//     ;
//   s[1] = '\0';
//   if (!isdigit(c) && c != '.') 
//     return c;
//   i = 0;
//   if (isdigit(c))
//     while (isdigit(s[++i] = c = getch()))
//       ;
//   if (c == '.')
//     while (isdigit(s[++i] = c = getch()))
//       ;
//   s[i] = '\0';
//   if (c != EOF)
//     ungetch(c);
//   return NUMBER;
// }

int stri = 0;

int getop(char input[], char s[]) {
  if (input[stri] == '\n') {
    stri = 0;
    return '\n';
  }

  int i, c;
  while ((s[0] = c = input[stri++]) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.') 
    return c;
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = input[stri++]))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = input[stri++]))
      ;
  s[i] = '\0';
  if (c != EOF)
    stri--;
  return NUMBER;
}

int getl(char s[], int lim) {
    int c, i;
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) 
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
