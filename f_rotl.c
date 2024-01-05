#include "monty.h"
/**
 * f_rotl - fait pivoter la pile vers le haut.
 * @list_head: pointeur tête de pile
 * @line_number: numero de ligne de fichier .m
 */
void f_rotl(stack_t **list_head, unsigned int line_number)
{
	stack_t *current = *list_head;
	int sauv_head_n;

	(void)line_number;

	if (current == NULL)
		return;
	if (current->next == NULL)
		return;


	sauv_head_n = current->n;

	while (current->next != NULL)
	{
		current->n = current->next->n;
		current = current->next;
	}

	current->n = sauv_head_n;
}
