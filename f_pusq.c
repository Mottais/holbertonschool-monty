#include "monty.h"

/**
 * f_pusq - pousse un élément en bas de la pile
 * @list_head: pointeur tête de pile
 * @num_ligne: numero de ligne de fichier .m
 */

void f_pusq(stack_t **list_head, unsigned int num_ligne)
{
	char *value_str = strtok(NULL, " \n");
	unsigned int i;
	stack_t *new_element, *current = *list_head;

	if (value_str == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", num_ligne);
		erreur = EXIT_FAILURE;
		return;
	}
	for (i = 0; i < strlen(value_str); i++)
		if ((value_str[i] < '0' || value_str[i] > '9') && value_str[i] != '-'
		&& value_str[i] != '+')
		{
			fprintf(stderr, "L%d: usage: push integer\n", num_ligne);
			erreur = EXIT_FAILURE;
			return;
		}
	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		erreur = EXIT_FAILURE;
		return;
	}
	new_element->n = atoi(value_str);
	new_element->next = NULL;
	if (current != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		new_element->prev = current;
		current->next = new_element;
	}
	else
	{
		*list_head = new_element;
		new_element->prev = NULL;
	}
}
