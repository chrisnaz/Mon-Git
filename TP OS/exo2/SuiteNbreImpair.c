#include <stdio.h>
#include <stdlib.h>

int main (int agrc, char *argc[]){
	int n, i, x;
	printf("Entrez votre nombre : ");
	scanf("%d", &n);
	
	int s = 0;
	/*i = 0; 
	while (i <= n){
		x = 2%i - 1;
		s = s + x;
		i++;
	}*/
	for (i = 0; i <= n; ++i){
		if (x % 2 == 1){
			x = 2*i + 1;
			s = s + x;
		}
		/*printf("%d",x);
		s = s + x;*/
	} 
	printf("\n");
	printf("%d\n",s);
	return 0;
}
