#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Provide 2 arguments\n");
    return 1;
  }

  char *string1 = argv[1];
  char *string2 = argv[2];

  if (strlen(string1) < 3 || strlen(string2) < 3) {
    printf("error: one or more arguments have fewer than 3 characters\n");
    return 1;
  }

  char *result = (char *)malloc(6 * sizeof(char));

  strncat(result, string1, 3);
  strncat(result, string2, 3);

  printf("%s\n", result);

  return 0;
}
