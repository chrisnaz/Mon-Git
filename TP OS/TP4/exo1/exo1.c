#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE* fichier = NULL;
  int Actuel = 0, i, b;
  char a [50];
  
  printf ("Combien de fichier avez-vous ?\n");
  scanf ("%d", &b);

  for (i = 1; i <= b; i ++) {
    printf ("Ecrire le nom du fichier : ");
    scanf ("%s", a);
    fichier = fopen(a, "r");
 
    if (fichier != NULL) {
      do {
        Actuel = fgetc (fichier);
        printf("%c", Actuel);
    } while (Actuel != EOF);
    fclose (fichier);
    }

    else
      printf ("Impossible d'ouvir le fichier %s\n", a);
  }
 
  return 0;
}
