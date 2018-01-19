#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

char *cleanupString(char *s) {
	char *c;
	char *newString=(char *) malloc ((strlen(s)+1)*sizeof(char));
	char *p=newString;

	short inspace=0;
	c=s;
	while (*c!=0) {
		// replace control characters with space
		if (*c<32)
		  *c=' ';
  if (isspace(*c)) {
		// compact sequences of spaces
			if (!inspace) {
	      *p=' ';
				p++;
				c++;
				inspace=1;
			} else {
				c++;
			}
		} else {
			*p=*c;
			p++;
			c++;
			inspace=0;
		}
	}
	// remove any trailing space
	p--;
	while (isspace(*p)) {
		p--;
	}
	p++;
	*p='\0';
	return(newString);
}

char **parseString(char *s) {
	char *p;
	// compte combien d'éléments dans s
	int i=0;
	int n=0;
	p = (char *) malloc (strlen(s)*sizeof(char));
	// avec strsep
	strcpy(p,s);
	char *q;
	char *o=p;
	while ((q=strsep(&p," ")) != NULL) {
		i++;
	}
	n=i;
	char **args=(char **) malloc((n+1)*sizeof(char *)); // le dernier élément doit être un pointeur nULL
	args[n]=NULL;

  // avec strtok
	p=o;
	strcpy(p,s);
  char *commande = strtok(p," ");
	args[0]=commande;
	char *argument;
	i=1;
	while ((argument=strtok(NULL," ")) != NULL) {
		args[i++]=argument;
	}
  for (i=0;i<n;i++) {
		printf("%d %x %x %s\n",i,(unsigned int) &args[i],(unsigned int) args[i],args[i]);
	}

  return(args);
}


int main(int argc, char**argv){
	char *commande=(char *) malloc (100*sizeof(char));
	char **arguments;
	int pid;
	int stat;

	printf("monshell:~$ ");
	fflush(stdout);
	fgets (commande, 100, stdin);
	commande=cleanupString(commande);

	while (strcmp(commande,"quit")) {
		arguments=parseString(commande);
		pid=fork();
		if (pid < 0) {
			perror("erreur dans le fork: ");
		} else if (pid == 0) {
			if (execvp(arguments[0],arguments)) {
				perror("erreur execvp: ");
				exit(-1);
			}
		} else {
			wait(&stat);
			printf("monshell:~$ ");
			fflush(stdout);
			fgets (commande, 100, stdin);
			commande=cleanupString(commande);
		}
	}
}
