#include "monty.h"

/**
 * f_mul - multiplie 2e élément avec 1er puis supp 1er élément de la pile
 * @list_head: pointeur tête de pile
 * @num_ligne: numero de ligne de fichier .m
 */

void f_mul(stack_t **list_head, unsigned int num_ligne)
{
	/* si pile vide ou pile avec 1 seule élément */
	if (*list_head == NULL || (*list_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", num_ligne);
		erreur = EXIT_FAILURE;
		return;
	}
	/* multiplie la valeur du 1er élément au 2ieme */
	(*list_head)->next->n *= (*list_head)->n;

	/* le 2ieme element devient la tête de pile */
	(*list_head) = (*list_head)->next;

	/* supp le 1er élément de la pile */
	free((*list_head)->prev);

}
