#ifndef _EXISTE_DEJA_
#define _EXISTE_DEJA_

#include <stdio.h>/*for printf*/
#include <stdlib.h>/*for free*/
#include <unistd.h>/*for ssize_t*/
#include <string.h>/*for strtok*/


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

int erreur;

void f_push(stack_t **list_head, unsigned int num_ligne);
void f_pall(stack_t **list_head, unsigned int num_ligne);
void f_pint(stack_t **list_head, unsigned int num_ligne);
void f_pop(stack_t **list_head, unsigned int num_ligne);
void f_swap(stack_t **list_head, unsigned int num_ligne);
void f_add(stack_t **list_head, unsigned int num_ligne);
void f_nop(stack_t **list_head, unsigned int num_ligne);
void f_sub(stack_t **list_head, unsigned int num_ligne);
void free_stack(stack_t **list_head);


#endif
