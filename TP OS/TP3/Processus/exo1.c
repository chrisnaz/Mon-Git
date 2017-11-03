#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main (){
  pid_t pid;
  pid = fork();

  switch (pid){
    case -1:
      perror ("fork");
      exit (EXIT_FAILURE);
      break;
  
    case 0:
      printf("\n");
      printf ("Je suis le fils et mon pid est %d et le ppid est %d\n", (int)getpid(), (int)getppid());
      break;

    case 1:
      printf("\n");
      printf ("Je suis le père et mon pid est %d et le pid du fil est %d", (int)getpid(), (int)getppid());
      break;
  }
  return 0;
}
