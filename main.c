#include "monty.h"

/**
 * main - gérer une structure
 * @arg_c: 1er argument
 * @arg_v: valeur de l'argument
 * Return: Always 0
 */

int main(int arg_c, char **arg_v)
{
	int compte_ligne = 0, index_fonct, i;
	FILE *ptr_fichier;
	size_t len;
	char *ligne = NULL, *instruction;
	stack_t *list_head = NULL;
	instruction_t tab_opcode_fonct[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop}, {"swap", f_swap}, {"add", f_add},
		{"nop", f_nop}, {NULL, NULL}};

	if (arg_c != 2)
	fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	ptr_fichier = fopen(arg_v[1], "r");
	if (ptr_fichier == NULL)
	fprintf(stderr, "error: Can't open file %s\n", arg_v[1]), exit(EXIT_FAILURE);
	erreur = 0;
while (getline(&ligne, &len, ptr_fichier) != -1)
{
	compte_ligne++; /*compteur nb de lignes dans fichier (arg_v[1])*/
	instruction = strtok(ligne, " \t\n");
	if (instruction != NULL) /* si vide à Traiter*/
	{
		index_fonct = -1;
		for (i = 0; tab_opcode_fonct[i].opcode != NULL; i++)
		{
			if (strcmp(instruction, tab_opcode_fonct[i].opcode) == 0)
				index_fonct = i, tab_opcode_fonct[index_fonct].f(&list_head, compte_ligne);
		}
		if (index_fonct == -1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", compte_ligne, instruction);
			erreur = EXIT_FAILURE;
		}
		if (erreur == EXIT_FAILURE)
		break;
	}
}
free_stack(&list_head), free(ligne), fclose(ptr_fichier);
return (erreur);
}
