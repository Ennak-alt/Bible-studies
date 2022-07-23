Write an alternate version of `squeeze(s1, s2)`, that deletes each character in `s1` that matches any 
character in the strig `s2`.

# Squeeze orignial code
```C
void squeeze(char s[], int c) {
  int i,j;

  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c) 
      s[j++] = s[i];
  s[j] = '\0';
}
```