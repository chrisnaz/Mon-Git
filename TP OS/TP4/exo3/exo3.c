#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char *argv[]) {
  FILE* fichier = NULL;
  int Actuel = 0, i;
  char a [50];
  pid_t pid = fork();

  printf ("Ecrire le nom du fichier : ");
  scanf ("%s", a);
  
  fichier = fopen(a, "r");
  if (fichier != NULL) {
    //do {
      //Actuel = fgetc (fichier);
      //printf ("%c", Actuel);
      switch (pid) {
        case -1:
        perror ("fork");
        exit (EXIT_FAILURE);
        break;
    
      case 0:
        do {
          Actuel = fgetc (fichier);
        for (i = 1; i <= 10; i ++) {
          printf ("%c", Actuel);
          
        } printf("\n");
        //break;
        }
      
      /*case 1:
        for (i = 1; i <= 5; i ++) {
          printf ("%c", Actuel);
          printf("\n");
        }
        //break;*/
      }
      
  
      
    } while (Actuel != EOF);
  /*}*/ fclose (fichier);
  
  return 0;
}