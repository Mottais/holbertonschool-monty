#include "monty.h"
/**
 * f_rotr - fait pivoter la pile vers le bas.
 * @list_head: pointeur tête de pile
 * @line_number: numero de ligne de fichier .m
 */
void f_rotr(stack_t **list_head, unsigned int line_number)
{
	stack_t *current = *list_head;

	(void)line_number;

	if (current == NULL)
		return;
	if (current->next == NULL)
		return;

	while (current->next != NULL)
		current = current->next;

	current->prev->next = NULL;
	current->next = *list_head;
	current->prev = NULL;
	*list_head = current;
}
