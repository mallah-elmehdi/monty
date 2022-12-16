#include "monty.h"

/**
 * monty - function that print a stack
 * @stack_head: stack head
 * @fp: file
 *
 * Return: void.
 */
void monty(FILE *fp, sstack_t **stack_head)
{
	read_file(fp, stack_head);
	fclose(fp);
	free_stack(*stack_head);
}
