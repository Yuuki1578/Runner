#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void collect_arguments(char *dst, int *argc, char **argv) {
  (void) strcat(dst, " ");

  for (int iter = 0; iter < (*argc - 1); iter++) {
    (void) strcat(dst, argv[iter + 1]);
    (void) strcat(dst, " ");
  }
}

void file_context(char *dst, FILE *context) {
  FILE *_cache = context;
  char buffer[1024];

  if (_cache == NULL) {
    perror("Couldn't find file \'Runfile\'");
    exit(EXIT_FAILURE);
  }

  (void) fgets(buffer, sizeof(buffer), context);
  buffer[strcspn(buffer, "\n")] = '\0';

  if (strlen(buffer) < 3) {
    (void) puts("Please provide executable path");
    exit(EXIT_FAILURE);
  }

  (void) strcat(dst, buffer);
  (void) fclose(context);
  (void) fclose(_cache);
}

int main(int argc, char **argv) {
  FILE *context = fopen("./Runfile", "r");
  char arguments[1024];
  char execute_sh[1024];

  collect_arguments(arguments, &argc, argv);
  file_context(execute_sh, context);
  (void) strcat(execute_sh, arguments);
  (void) system(execute_sh);

  return 0;
}
