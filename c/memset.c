#include <stdio.h>
#include <string.h>

int main() {
  char buffer[20];

  // Fill the buffer with '-' characters
  memset(buffer, '-', sizeof(buffer) - 1);

  // Null-terminate the string
  buffer[sizeof(buffer) - 1] = '\0';

  printf("Buffer after memset: %s\n", buffer);

  return 0;
}
