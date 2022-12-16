#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
} sstack_t;

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
	void (*f)(sstack_t **stack, unsigned int line_number);
} instruction_t;


sstack_t *add_node_stack(sstack_t **head, const int n);
void free_stack(sstack_t *head);
void pall_stack(sstack_t *stack_head);
void push_node_stack(FILE *fp, int lineInt, sstack_t **stack_head);
void read_file(FILE *fp, sstack_t **stack_head);
void monty(FILE *fp, sstack_t **stack_head);
int is_int(char *s);
char *trimwhitespace(char *str);
void pint_stack(FILE *fp, int lineInt, sstack_t *stack_head);
void pop_stack(FILE *fp, int lineInt, sstack_t **stack_head);
int delete_dnodeint_at_index(sstack_t **head, unsigned int index);

#endif
