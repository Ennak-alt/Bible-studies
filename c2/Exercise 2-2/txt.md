Write a loop equivalent to the for loop above without using `&&` and `||`

```c
// Orginal 
for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) 
  s[i] = c;
// New
char c;
int i = 0;
while (i < lim-1) {
  if (c != '\n') {
    if (c != EOF){
      s[i] = c;
      ++i;
      continue;
    }
  } 
  break;
}