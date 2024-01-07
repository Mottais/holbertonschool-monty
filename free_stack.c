#include "monty.h"

/**
 * free_stack - ôte la pile de la mémoire
 * @list_head: pointeur tête de pile
 */

void free_stack(stack_t **list_head)
{
	stack_t *next_node;
printf("free_stack\n");
	while (*list_head != NULL)
	{
		next_node = (*list_head)->next;
		free(*list_head);
		*list_head = next_node;
	}
}
