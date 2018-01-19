/*
 * Cette fonction lit caractère par caractère elle passe un état à l'autre
 * en fonction de caractère entré. Elle prend en entrée une structure args
 * et à la fin, la structure contient le nombre d'arguments et la liste
 * d'arguments.
 *
 * Notre commande est de la forme suivante:
 * 
 *  commande [list_arguments]
 * 
 *  où
 *  . commande est une suite des alpha numérique: [a-zA-Z0-9]* 
 *  . arguments est une suite de alpha numérique plus '-' et '_' [a-zA-Z0-9-_]* 
 *    séparés par un ou plusieurs espaces ou \t.
 *
 * 0) Le programme commence par initialiser l'état à "INTIAL_STATE" (état initial):
 *
 * 1) il passe à un état "COMMAND_STATE" s'il détecte un caractère (alpha numérique),
 *    il reste dans cet état s'il détecte toujours des caractères valids.
 *
 * 2) s'il détecte un espace, on suavegarde la commande (stockéd dans une
 *    variable tmp), et on passe à un état "SPACE STATE", et il reste
 *    toujours dans cet état s'il rencontre toujours des epaces.
 *
 * 3) s'il détecte un caractère non espace, il passe à un état "ARGUMENT_STATE"
 *    et continue à enregistre autres caractères non espace; s'il rencontre
 *    un caractère espace, on sait que on a un argument, alors on sauvegarde
 *    notre option, et on passe à l'étape 2 ("SPACE STATE").
 *
 * 4) Finalement, lorsqu'il rencontre un caractère EOF ou '\n' (fin de ligne).
 *    Le programme doit faire un petit ménage, on sauvegarde
 *    la commande ou la dernière option lue s'il on état à l'état "COMMAND_STATE"
 *    ou l'état "ARGUMENT_STATE" avant de passer à l'état final "FINAL_STATE".
 *
 *                  [a-z0-9]*        espace(s)           [a-z0-9-_]*
                    +------+         +------+             +------+
        [a-z0-9]    |      |  espace |      | [a-z0-9-_]  |      |
-->(0)--------------`->(1)-'---------`->(2)-'-------------`->(3)-'
    |                   |              /  Î                   |\
    |          [EOF,\n] |   [EOF,\n]  /   |       espace      | \
    |                   |            /    +-------------------+  \
    |                   `           /                            |
    +----------------->((4))<------+          [EOF,\n]           |
          [EOF,\n]          `------------------------------------+
 
 *
 *
 */

#include "header.h"

void read_arguments(struct args * argument) {
  int c;
  int state = INITIAL_STATE;
  char tmp[255];
  int i = 0, j = 0;

  // init
  (*argument).count = 0;

  while (state != FINAL_STATE) {
    c = getchar();
    if ((state == INITIAL_STATE) && isalnum(c)) {
      i = 0;
      tmp[i++] = (char) c;
      (*argument).count++;
      state = COMMAND_STATE;
      continue;
    }

    if ((state == COMMAND_STATE) && (isalnum(c) || ispunct(c))) {
      tmp[i++] = c; 
      continue;
    }

    if ((state == COMMAND_STATE) && isblank(c)) {
      tmp[i] = '\0';
      (*argument).args[j] = (char *) malloc(i + 1);
      strcpy((*argument).args[j], tmp);
      j = j + 1;
      state = SPACE_STATE;
      continue;
    }

    if ((state == SPACE_STATE) && (isalnum(c) || ispunct(c))) {
      (*argument).count++;
      i = 0;
      tmp[i++] = c;
      state = ARGUMENT_STATE;
      continue;
    }

    if ((state == ARGUMENT_STATE) && (isalnum(c) || ispunct(c))) {
      tmp[i++] = c;
      continue;
    }

    if ((state == ARGUMENT_STATE) && isblank(c)) {
      tmp[i] = '\0';
      (*argument).args[j] = (char *) malloc(i + 1);
      strcpy((*argument).args[j], tmp);
      j = j + 1;
      state = SPACE_STATE;
      continue;
    }
  
    if ((c == EOF) || (c == '\n')) {
      if ((state == COMMAND_STATE) || (state == ARGUMENT_STATE)) {
        tmp[i] = '\0';
        (*argument).args[j] = (char *) malloc(i + 1);
        strcpy((*argument).args[j], tmp);
        j = j + 1;
      }

      (*argument).args[j] = NULL;
      state = FINAL_STATE;
    }
  }
}
