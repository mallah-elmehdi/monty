#include "monty.h"

/**
 * pop_stack - function that print a stack
 * @stack_head: stack head
 *
 * Return: void.
 */
void pop_stack(FILE *fp, int lineInt, sstack_t **stack_head)
{
	if (*stack_head == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", lineInt);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(stack_head, 0);
}
