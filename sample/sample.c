// This sample program will print all argument
// inputted by the user, from argv[1] to argv[n]
// The path to executable is sample/path/to/exe/sample

#include <stdio.h>

int main(int argc, char **argv) {
  for (int i = 0; i < argc - 1; i++) {
    (void) printf("%s ", argv[i + 1]);
  }
  
  (void) printf("%c", '\n');
  return 0;
}
