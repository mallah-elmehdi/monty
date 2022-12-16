#include "monty.h"

/**
 * push_node_stack - function that push to stack
 * @lineInt: line number
 * @stack_head: stack head
 * @fp: file
 *
 * Return: void.
 */
void push_node_stack(FILE *fp, int lineInt, sstack_t **stack_head)
{
	char *value = NULL;

	value = trimwhitespace(strtok(NULL, "\n"));
	if (value == NULL || is_int(value) == 0)
	{
		dprintf(2, "L%d: usage: push integer\n", lineInt);
		fclose(fp);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	add_node_stack(stack_head, atoi(value));
}
