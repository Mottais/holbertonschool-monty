#include "monty.h"

/**
 * f_sub - soustrait l'élément supérieur du 2e de la pile
 * @list_head: pointeur tête de pile
 * @num_ligne: numero de ligne de fichier .m
 */

void f_sub(stack_t **list_head, unsigned int num_ligne)
{
	/* si pile vide ou pile avec 1 seule élément */
	if (*list_head == NULL || (*list_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num_ligne);
		erreur = EXIT_FAILURE;
		return;
	}
        /* soustrait la valeur du 1er au 2e */
	(*list_head)->next->n -= (*list_head)->n;

	(*list_head) = (*list_head)->next;

	free((*list_head)->prev);
}
