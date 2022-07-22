// Exercise 1-23
#include <stdio.h>
#define MAXINPUT 10000
#define IN 0
#define OUT 1

int checkBalancing(char s[]);

int main()
{
  int i;
  char input[MAXINPUT];
  char currentChar;
  for (i = 0; (currentChar = getchar()) != EOF; i++)
  {
    input[i] = currentChar;
  }
  input[i] = '\0';
  if (checkBalancing(input))
  {
    putchar('T');
  }
  else
  {
    putchar('F');
  }
  return 0;
}

int checkBalancing(char s[])
{
  char list[1000];
  int braces, paranth, brackets, index;
  index = -1;
  braces = paranth = brackets = 0;
  char currentChar;
  for (int i = 0; s[i] != EOF; i++)
  {
    switch (s[i])
    {
    case '(':
      list[++index] = '(';
      paranth++;
      break;
    case ')':
      if ('(' != list[index])
      {
        return 0;
      }
      index--;
      paranth--;
      break;
    case '[':
      list[++index] = '[';
      brackets++;
      break;
    case ']':
      if ('[' != list[index])
      {
        return 0;
      }
      index--;
      brackets--;
      break;
    case '{':
      list[++index] = '{';
      braces++;
      break;
    case '}':
      if ('{' != list[index])
      {
        return 0;
      }
      index--;
      braces--;
      break;
    default:
      break;
    }
  }
  if (braces != 0 || paranth != 0 || brackets != 0)
  {
    return 0;
  }
  return 1;
}
