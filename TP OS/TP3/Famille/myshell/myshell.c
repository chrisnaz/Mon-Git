#include "header.h"

int main() {
  struct args argument;
  int stop = FALSE;
  pid_t pid;

  do {
    printf("myshell$ ");
    
    read_arguments(&argument);
    if (argument.count == 0) {
      printf("Usage: command [arg1, arg2, ...]\n");
      printf("To exit type \"quit\"\n");
    } else { 
      if ((strcmp(argument.args[0], "quit") == 0))
        stop = TRUE;
      else {
        pid = fork();

        switch (pid) {
          // cas d'erreur
          case -1:
            perror("fork()");
            exit(EXIT_FAILURE);

          // on est dans le fils
          case 0:
            execvp(argument.args[0], argument.args);
            perror("execvp");
            exit(EXIT_FAILURE);

          // on est dans le père
          default:
            wait(NULL);
            free_arguments(&argument);
        }
      }
    }
  } while (!stop);

  exit(EXIT_SUCCESS);
}

void free_arguments(struct args * argument) {
  int i = 0;

  for (i = 0; i < (*argument).count; i++) {
    free((*argument).args[i]);
  }
}
