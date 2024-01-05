#include "monty.h"

/**
 * f_pchar - imprime la valeur format caractere du 1er élémnent de la pile
 * @stack: pointer to the stack
 * @line_number: line number of the instruction
 *
 * Description: print the value at the top of the stack as a char
 * Return: NOTHING
 */
void f_pchar(stack_t **list_head, unsigned int num_ligne)
{
	if (*list_head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", num_ligne);
		erreur = EXIT_FAILURE;
		return;
	}
	if ((*list_head)->n < 0 || (*list_head)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", num_ligne);
		erreur = EXIT_FAILURE;
		return;
	}

	putchar((*list_head)->n);
	putchar(10);
}
