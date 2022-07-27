#include <string.h>
#include <stdio.h>

void test(char testName[], char expected[], char ouput[]) {
  if (strcmp(expected, ouput) == 0) {
    printf("\033[0m%s: \033[0;32mSUCEEDED \n", testName);
  } else {
    printf("\033[0m%s: \033[0;31mFAILED \n", testName);
    printf("\033[0;31m   Expected: \"%s\" but got \"%s\" \n", expected, ouput);
  }
}

/// @brief Convert escape sequences into literals (does copy last null character)
/// @param s string to copy to
/// @param t string to copy from
/// @return s is altered to contain literal escape sequences
void escape(char s[], char t[]);

/// @brief Converts literal escape sequences into actual escape sequences
/// @param s string to copy to
/// @param t string to copy from
/// @return s is altered to contain converted literal escape sequences
void revescape(char s[], char t[]);

int main() {
  char s[1000];

  char t1[] = "\n\t";

  escape(s, t1);
  test("TEST_1", "\\n\\t\\0", s);

  char t2[] = "\a \b \f \n \r \t \v \\ \' \" \? abcdefghijklmnopupqrstuvxyz \0";

  escape(s, t2);
  test("TEST_2", "\\a \\b \\f \\n \\r \\t \\v \\\\ \\\' \\\" \\? abcdefghijklmnopupqrstuvxyz \\0", s);

  char t3[] = "\\a \\b \\f \\n \\r \\t \\v \\\\ \\\' \\\" \\? abcdefghijklmnopupqrstuvxyz \\0";

  revescape(s, t3);
  test("TEST_3", "\a \b \f \n \r \t \v \\ \' \" \? abcdefghijklmnopupqrstuvxyz \0", s);

  return 0;
}

void escape(char s[], char t[]) {
  int si, ti;
  for (si = ti = 0; t[ti] != '\0'; si++, ti++) {
    switch (t[ti])
    { 
    case '\a':
      s[si] = '\\';
      s[++si] = 'a';
      break;
    case '\b':
      s[si] = '\\';
      s[++si] = 'b';
      break;
    case '\f':
      s[si] = '\\';
      s[++si] = 'f';
      break;
    case '\n':
      s[si] = '\\';
      s[++si] = 'n';
      break;
    case '\r':
      s[si] = '\\';
      s[++si] = 'r';
      break;
    case '\t':
      s[si] = '\\';
      s[++si] = 't';
      break;
    case '\v':
      s[si] = '\\';
      s[++si] = 'v';
      break;
    case '\\':
      s[si] = '\\';
      s[++si] = '\\';
      break;
    case '\'':
      s[si] = '\\';
      s[++si] = '\'';
      break;
    case '\"':
      s[si] = '\\';
      s[++si] = '\"';
      break;
    case '\?':
      s[si] = '\\';
      s[++si] = '\?';
      break;
    default:
      s[si] = t[ti];
      break;
    }
  }
  s[si] = '\\';
  s[++si] = '0';
  s[++si] = '\0';
}

void revescape(char s[], char t[]) {
  int si, ti;
  for (si = ti = 0;;si++, ti++) {
    if (t[ti] == '\\') {
      ti++;
      if (t[ti] == '0') {
        s[si] = '\0';
        break;
      } 
      switch (t[ti])
      { 
      case 'a':
        s[si] = '\a';
        break;
      case 'b':
        s[si] = '\b';
        break;
      case 'f':
        s[si] = '\f';
        break;
      case 'n':
        s[si] = '\n';
        break;
      case 'r':
        s[si] = '\r';
        break;
      case 't':
        s[si] = '\t';
        break;
      case 'v':
        s[si] = '\v';
        break;
      case '\\':
        s[si] = '\\';
        break;
      case '\'':
        s[si] = '\'';
        break;
      case '\"':
        s[si] = '\"';
        break;
      case '\?':
        s[si] = '\?';
        break;
      }
    } else 
      s[si] = t[ti]; 
  }
}

// \a	            Alarm or Beep
// \b	            Backspace
// \f	            Form Feed
// \n	            New Line
// \r	            Carriage Return
// \t	            Tab (Horizontal)
// \v	            Vertical Tab
// \\	            Backslash
// \'	            Single Quote
// \"	            Double Quote
// \?	            Question Mark
// \nnn	            octal number
// \xhh	            hexadecimal number
// \0	

