#include "monty.h"

/**
 * f_div - divise 2ieme element par le 1er puis suppr 1er élément de la pile
 * @list_head: pointeur tête de pile
 * @num_ligne: numero de ligne de fichier .m
 */

void f_div(stack_t **list_head, unsigned int num_ligne)
{
	/* si pile vide ou pile avec 1 seule élément */
	if (*list_head == NULL || (*list_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", num_ligne);
		erreur = EXIT_FAILURE;
		return;
	}

	if ((*list_head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num_ligne);
		erreur = EXIT_FAILURE;
		return;
	}

	/* ajoute la valeur du 1er élément au 2ieme */
	(*list_head)->next->n += (*list_head)->n;

	/* le 2ieme element devient la tête de pile */
	(*list_head) = (*list_head)->next;

	/* supp le 1er élément de la pile */
	free((*list_head)->prev);

}
