#include "monty.h"

/**
 * f_swap - permute les deux premiers éléments de la pile
 * @list_head: pointeur tête de pile
 * @num_ligne: numero de ligne de fichier .m
 */

void f_swap(stack_t **list_head, unsigned int num_ligne)
{
	int sauve_valeur;

	if (*list_head == NULL || (*list_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", num_ligne);
		erreur = EXIT_FAILURE;
		return;
	}
	sauve_valeur = (*list_head)->n;
	(*list_head)->n = (*list_head)->next->n;
	(*list_head)->next->n = sauve_valeur;
}
