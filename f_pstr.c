#include "monty.h"

/**
 * f_pstr - imprime la valeur au format caractere chaque élémnents de la pile
 * @list_head: pointeur tête de pile
 * @line_number: numero de ligne de fichier .m
 *
 */
void f_pstr(stack_t **list_head, unsigned int line_number)
{
	stack_t *current = *list_head;

	(void)line_number;

	while (current != NULL && current->n > 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}
	putchar(10);
}
