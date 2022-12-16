#include "monty.h"

/**
 * free_stack - function that frees a stack_t list
 * @head: stack_t list head
 *
 * Return: void.
 */
void free_stack(sstack_t *head)
{
	while (head)
	{
		free(head);
		head = head->next;
	}
}
