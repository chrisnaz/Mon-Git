#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listChaine.h"

void viderTampan(){
	int c;
	while ((c = getchar ()) != '\n' && c != EOF);
}

void affichageMenu(){
	printf ("\tMenu\n"
		"1 - Ajouter un élément au début du dictionnaire\n"
		"2 - Ajouter un élément à la fin du dictionnaire\n"
		"3 - Supprimer le premier élément du dictionnaire\n"
		"4 - Supprimer le dernier élément du dictionnaire\n"
		"5 - Afficher le dictionnaire\n"
		"6 - Rechercher un mot dans le dictionnaire\n" //Pas réussi à le faire
		"7 - Ajouter un mot dans emplacement précis\n" //Pas réussi à le faire encore
		"8 - Quitter\n");
}

void choixFonction (int c){
	liste elem_un ;
	char mot [20];
	char definition [2000];
	int i;
	switch (c) {
		case 1 : 
			/*if (elem_un == NULL){
				printf("Aucun dictionnaire en memoire\n");
				break;
			}*/
			printf ("Entrer le mot : ");
			scanf ("%s", mot);
			printf ("Entrer la définition du mot : ");
			scanf ("%s", definition);
			elem_un = addElemAtBegining (elem_un, mot, definition);
			//showList (elem_un);
			printf ("\n");
			break;

		case 2 :
			if (elem_un == NULL){
				printf("Aucun dictionnaire en memoire\n");
				break;
			}
			printf ("Entrer le mot : ");
			scanf ("%s", mot);
			printf ("Entrer la définition du mot : ");
			scanf ("%s", definition);
			elem_un = addElemAtEnd (elem_un, mot, definition);
			break;

		case 3 :
			if (elem_un == NULL){
				printf("Aucun dictionnaire en memoire\n");
				break;
			}
			elem_un = deleteHead (elem_un);
			break;

		case 4 :
			if (elem_un == NULL){
				printf("Aucun dictionnaire en memoire\n");
				break;
			}
			elem_un = deleteTail (elem_un);
			break;
		
		case 5 : 
			if (elem_un == NULL){
				printf("Aucun dictionnaire en memoire\n");
				break;
			}
			showList (elem_un);
			break;

		case 6 :
			if (elem_un == NULL){
				printf("Aucun dictionnaire en memoire\n");
				break;
			}
			printf ("Entrer le mot à rechercher : ");
			scanf ("%s", mot);
			elem_un = searhElement (elem_un, mot);
			break;

		case 7 :
			if (elem_un == NULL){
				printf("Aucun dictionnaire en memoire\n");
				break;
			}
			printf ("Entrer le mot : ");
			scanf ("%s", mot);
			printf ("Entrer la définition du mot : ");
			scanf ("%s", definition);
			printf ("Entrer son emplacement : ");
			scanf ("%d", &i);
			elem_un = addElemWithIndex (elem_un, mot, definition, i);
			showList (elem_un);
			printf ("\n");
			break;

		case 8 : 
			exit(EXIT_SUCCESS);
			break;
		
		default : 
			printf ("Aucun choix n'est correspond. \n");
			break;
	}
}

int main(int argc, char ** argv){
	liste elem_un;
	while (1) {
		affichageMenu();
		int c;
		scanf("%d", &c);
		//viderTampan();
		choixFonction(c);
	}
	return 0;
}
	
	/*liste elem_un = NULL ;
	liste elem_deux = NULL;
	//char 
	
	{
		elem_un = addElemAtBegining (elem_un, "Parent", "One of two persons from whom one is immediately biologically descended, a mother or father.");
		elem_un = addElemAtEnd (elem_un, "Child", "A person who has not yet reached adulthood, whether natural (puberty), cultural (initiation).");
		elem_un = addElemAtEnd (elem_un, "Piece", "A part of a larger whole, usually in such a from that it is able to be separated from other parts.");
		elem_un = addElemAtEnd (elem_un, "Cake", "A rich, sweet dessert fodd, typically made of flour, sugar and agges and baked in a oven, and often covered in icing.");
		elem_un = addElemAtEnd (elem_un, "Food", "Any substance that can be consumed by living organisms, especially by eating, in order to sustain life.");
		elem_un = addElemAtEnd (elem_un, "Yes", "A word used to show agreement or acceptance.");
		elem_un = addElemAtEnd (elem_un, "Christian", "An individual who seeks to live his or her life according to the principes and values taught by Jesus-Christ.");
		
		elem_un = addElemAtBegining (elem_un, "Thank", "(Obsolete) An expression of appreciation; a thought.");
		elem_un = addElemWithIndex (elem_un, "Mafemme", "est une bonne personne pour moi", 3);
			
		//elem_un = deleteHead (elem_un);
		//elem_un = deleteTail (elem_un);
		//showList (elem_un);
		//printf("\n");
		//printf("L'élément cherché est : \n");
		//elem_deux = searhElement (elem_un, "Food");
		//elem_deux = addElemAtBegining (elem_deux, "Food", "sdlfsdkjf");
		//showList (elem_deux);
		
	
	return 0;
}*/
