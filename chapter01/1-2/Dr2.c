// 暗号の解読
#include <stdio.h>

int main(void) {
  char table[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O',
                  'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K',
                  'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
  const char *ango = "KSOIDHEPZ";
  int index;

  while (*ango != '\0') {
    if ('A' <= *ango && *ango <= 'Z') {
      index = *ango - 'A';
    } else {
        index = 26;
    }
    putchar(table[index]);
    ango++;
  }
  printf("\n");
}
