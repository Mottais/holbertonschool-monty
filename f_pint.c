#include "monty.h"

/**
 * f_pint - imprime le premier noeud
 * @list_head: pointeur tête de pile
 * @num_ligne: numero de ligne de fichier .m
 */

void f_pint(stack_t **list_head, unsigned int num_ligne)
{
	(void)num_ligne;

	if (*list_head == NULL)
	{
	fprintf(stderr, "L%u: can't pint, stack empty\n", num_ligne);
	erreur = EXIT_FAILURE;
	return;
	}
	printf("%d\n", (*list_head)->n);
}
