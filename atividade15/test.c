#include <ctype.h>
#include <stdio.h>
#include <string.h>

void capitalize_all_words(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
      str[i + 1] = toupper(str[i + 1]);
    }
  }
}

int main() {
  char str[] = "hello world this is a test";

  capitalize_all_words(str);

  printf("%s\n", str);

  return 0;
}
