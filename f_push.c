#include "monty.h"

/**
 * f_push - pousse un élément sur la pile
 * @list_head: pointeur tête de pile
 * @num_ligne: numero de ligne de fichier .m
 */
void f_push(stack_t **list_head, unsigned int num_ligne)
{
	(void)list_head;
	(void)num_ligne;
	char *valeur_string = strtok(NULL, " \t\n");
	int valeur_num = atoi(valeur_string);

	printf("valeur_string : %s\n", valeur_string);
	printf("valeur_num : %d\n", valeur_num);
	printf("f_push à traiter\n");
}
