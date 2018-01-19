#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>

#define INITIAL_STATE  0
#define COMMAND_STATE  1
#define SPACE_STATE    2
#define ARGUMENT_STATE 3
#define FINAL_STATE    4

#define TRUE 1
#define FALSE 0

/*
 * count contient le nombre d'arguments
 * args continet la liste des arguments
 */
struct args {
  int count;
  char * args[100];
};

/* prototypes de fonctions */
void read_arguments(struct args * argument);
void free_arguments(struct args * argument);
