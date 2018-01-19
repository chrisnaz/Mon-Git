#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  FILE* fichier;
  FILE* fichier1;
  char ligne[90];
  char a [50];
  char b [50];
  
  printf ("Le deuxième fichier sera dans le même repertoire que le premier\n");
  printf ("Ecrire le nom du fichier : ");
  scanf ("%s", a);
 
  if ((fichier = fopen(a, "r")) == NULL) {
    return 1;
  }

  printf ("Ecrivez le nom du nouveau fichier : ");
  scanf ("%s", b);
  if ((fichier1 = fopen(b, "w")) == NULL) {
    fclose(fichier);
    return 2;
  }
 
  fgets(ligne, 90, fichier);
 
  while (!feof(fichier)) {
    fputs(ligne, fichier1);
    fgets(ligne, 81, fichier);
  }
 
  fclose(fichier1);
  fclose(fichier);
 
  printf("\nLa copie est terminee.\n");
 
  return 0;
 }
