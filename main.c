#include <stdio.h>/*for printf*/
#include <stdlib.h>/*for free*/ 
#include <unistd.h>/*for ssize_t*/
#include <string.h>/*for strtok*/

extern int erreur;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void f_push(stack_t **list_head, unsigned int num_ligne)
{

        (void)list_head;
        (void)num_ligne;
        char *valeur_string = strtok(NULL, " \t\n");
	int valeur_num = atoi(valeur_string);

        printf("valeur_string : %s\n",valeur_string);
	printf("valeur_num : %d\n", valeur_num);
        printf("f_push à traiter\n");
}


void f_pall(stack_t **list_head, unsigned int num_ligne)
{
        
        (void)list_head;
        (void)num_ligne;
        printf("f_pall à traiter\n");
}


void f_pint(stack_t **list_head, unsigned int num_ligne)
{
        (void)list_head;
        (void)num_ligne;
        printf("f_nop à traiter\n");

}


void f_pop(stack_t **list_head, unsigned int num_ligne)
{
        (void)list_head;
        (void)num_ligne;
        printf("f_pop à traiter\n");

}


void f_swap(stack_t **list_head, unsigned int num_ligne)
{
        (void)list_head;
        (void)num_ligne;
        printf("f_nop à traiter\n");
}


void f_add(stack_t **list_head, unsigned int num_ligne)
{
        (void)list_head;
        (void)num_ligne;
        printf("f_add à traiter\n");

}


void f_nop(stack_t **list_head, unsigned int num_ligne)
{
        (void)list_head;
        (void)num_ligne;
        printf("f_nop à traiter\n");

}

void free_stack(stack_t **list_head)
{
        stack_t *next_node;

        while (*list_head != NULL)
        {
                next_node = (*list_head)->next;
                free(*list_head);
                *list_head = next_node;
        }
}

int main(int arg_c, char **arg_v)
{
        int compte_ligne = 0, index_fonct, mode = 0, i;
        FILE *ptr_fichier;
        size_t len;
        char *ligne = NULL, *instruction;
        stack_t *list_head = NULL;
        instruction_t tab_opcode_fonct[] = {
                {"push", f_push},
                {"pall", f_pall},
                {"pint", f_pint},
                {"pop", f_pop},
                {"swap", f_swap},
                {"add", f_add},
                {"nop", f_nop},
                {NULL, NULL}};

        if (arg_c != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
        ptr_fichier = fopen(arg_v[1], "r");
        if (ptr_fichier == NULL)
        {
                fprintf(stderr, "error: Can't open file %s\n", arg_v[1]);
                exit(EXIT_FAILURE);
        }
        erreur = 0;
        while (getline(&ligne, &len, ptr_fichier) != -1) 
        {
                compte_ligne++; /*compteur nb de lignes dans fichier (arg_v[1])*/
                instruction = strtok(ligne, " \t\n");
/*                if (instruction == NULL)  si vide à Traiter*/
                        
                index_fonct = -1;
                for (i = 0; tab_opcode_fonct[i].opcode != NULL; i++)
                {
                        if (strcmp(instruction, tab_opcode_fonct[i].opcode) == 0)
                        {
                                index_fonct = i;
                                tab_opcode_fonct[index_fonct].f(&list_head, compte_ligne);
                        }
                }

                if (index_fonct == -1)
                {
                        fprintf(stderr, "L%d: unknown instruction %s\n", compte_ligne, instruction);
                        return (-1);
                }


        }
        free_stack(&list_head);
        free(ligne);
        fclose(ptr_fichier);
        if (erreur == 1 || index_fonct == -1)
                exit(EXIT_FAILURE);
        return (0);
}
