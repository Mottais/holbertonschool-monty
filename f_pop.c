#include "monty.h"

/**
 * f_pop - retire le premier noeud
 * @list_head: pointeur tête de pile
 * @num_ligne: numero de ligne de fichier .m
 */

void f_pop(stack_t **list_head, unsigned int num_ligne)
{
	stack_t *node_to_pop = *list_head;

	if (*list_head == NULL)
	{
	fprintf(stderr, "L%d: can't pop an empty stack\n", num_ligne);
	erreur = EXIT_FAILURE;
	return;
	}

	*list_head = (*list_head)->next;
	free(node_to_pop);
	if (*list_head != NULL)
	(*list_head)->prev = NULL;
}
