#include <stdio.h>
#include <stdlib.h>

/*int length (const char**& array){
	return sizeof (array)/sizeof(char*);
}*/

int main (int argv, char **argc){
	char CHI[2000];
	
	printf("Entrez la chaine de caractère (max 100 caractères) : ");
	scanf("%s",CHI);

	printf("Voici la chaine entrer : %s\n", CHI);
	printf("Et sa taille vaut : %d\n",sizeof(CHI));
	return 0;
}
