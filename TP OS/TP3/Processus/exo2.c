#include < unistd.h >
#include < sys/types.h >
#include < stdlib.h >
#include < stdio.h >
#include < errno.h >
#include < sys/wait.h >
#define MAX_TAB 4

int main () {
  pid_t pid ;
  pid = fork() ;
  int i ;
  int tab[MAX_TAB] ;

  for (i = 0; i < MAX_TAB; i++) {
    switch (tab[i] = fork()) {
      case -1:
        perror("fork") ;
        exit (EXIT_FAILURE);
        break;

      case 0:
                
    }
  }
}
