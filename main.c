#include "monty.h"

/**
 * main - gérer une structure
 * @arg_c: 1er argument
 * @arg_v: valeur de l'argument
 * Return: Always 0
 */

int main(int arg_c, char **arg_v)
{
	int compte_lg = 0, index_fonct, i;
	FILE *ptr_fichier;
	size_t len;
	char *ligne = NULL, *instruction;
	stack_t *list_head = NULL;
	instruction_t tab_opcode_fonct[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint}, {"pop", f_pop},
		{"swap", f_swap}, {"add", f_add}, {"sub", f_sub}, {"div", f_div},
		{"mul", f_mul}, {"mod", f_mod}, {"nop", f_nop},	{"pchar", f_pchar},
		{"pstr", f_pstr}, {"rotl", f_rotl}, {"rotr", f_rotr}, {NULL, NULL}};

	if (arg_c != 2)
	fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	ptr_fichier = fopen(arg_v[1], "r"), erreur = 0;
	if (ptr_fichier == NULL)
	fprintf(stderr, "Error: Can't open file %s\n", arg_v[1]), exit(EXIT_FAILURE);

	while (getline(&ligne, &len, ptr_fichier) != -1)
	{
		compte_lg++, instruction = strtok(ligne, " \n");
		if (instruction != NULL)
		{
			index_fonct = -1;
			for (i = 0; tab_opcode_fonct[i].opcode != NULL; i++)
			{
				if (strcmp(instruction, tab_opcode_fonct[i].opcode) == 0)
				index_fonct = i, tab_opcode_fonct[index_fonct].f(&list_head, compte_lg);
			}
		if (index_fonct == -1 && instruction[0] != '#')
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", compte_lg, instruction);
			erreur = EXIT_FAILURE;
		}
		if (erreur == EXIT_FAILURE)
		break;
	}
}
free_stack(&list_head), free(ligne), fclose(ptr_fichier);
return (erreur);
}
