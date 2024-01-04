#include "monty.h"

/**
 * f_pall - imprime tous les éléments de la pile
 * @list_head: pointeur tête de pile
 * @num_ligne: numero de ligne de fichier .m
 */

void f_pall(stack_t **list_head, unsigned int num_ligne)
{
	stack_t *current = *list_head;
	(void)num_ligne;

	if (list_head == NULL)
	{
		erreur = EXIT_FAILURE;
		return;
	}

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
