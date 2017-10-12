#include <stdio.h>
#include <stdlib.h>

int main (int agrc, char *argc[]){
	int a = 0, b = 0;
	printf("Entrez le premier nombre : ");
	scanf ("%d", &a);
	printf("Entrez le deuxième nombre : ");
	scanf ("%d", &b);
	
	int r = 0;
	while (b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	printf("Le PGCD est de %d\n", a);
	return 0;
}
