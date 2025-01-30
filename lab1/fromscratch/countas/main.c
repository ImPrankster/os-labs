#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("countas <arg>\n");
    return 1;
  }

  char *inputString = argv[1];
  int count = 0;

  while (*inputString != '\0') {
    if (*inputString == 'a') {
      count++;
    }
    inputString++;
  }

  printf("%d\n", count);

  return 0;
}