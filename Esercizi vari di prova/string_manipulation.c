#include <stdio.h>
#include <string.h>

int main() {
  char str[] = "Hello, world!";
  char sub[] = "world";

  // Find the first occurrence of "world" in "Hello, world!"
  char *result = strstr(str, sub);

  // Print the result
  printf("%s\n", result);

  return 0;
}
