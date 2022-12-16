#include "monty.h"

/**
 * pall_stack - function that print a stack
 * @stack_head: stack head
 *
 * Return: void.
 */
void pall_stack(sstack_t *stack_head)
{
	while (stack_head)
	{
		printf("%d\n", stack_head->n);
		stack_head = stack_head->next;
	}
}
