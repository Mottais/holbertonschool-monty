#include "monty.h"

/**
 * f_add - additionne puis enlève les deux 1ers éléments de la pile
 * @list_head: pointeur tête de pile
 * @num_ligne: numero de ligne de fichier .m
 */

void f_add(stack_t **list_head, unsigned int num_ligne)
{
	/* si pile vide ou pile avec 1 seule élément */
	if (*list_head == NULL || (*list_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num_ligne);
		erreur = EXIT_FAILURE;
		return;
	}
	/* ajoute la valeur du 2ieme élément au premier */
	(*list_head)->next->n += (*list_head)->n;

	/* réaffect l'addresse du 2ieme élément au 1er */
	(*list_head) = (*list_head)->next;

	/* supp le 2ieme éléent de la pile */
	free((*list_head)->prev);
}
