#include "monty.h"

/**
 * add_node_stack - function that adds a new node at the beginning
 * @head: sstack_t list head
 * @n: data
 *
 * Return: the address of the new element, or NULL if it failed.
 */
sstack_t *add_node_stack(sstack_t **head, const int n)
{
	sstack_t *new = malloc(sizeof(sstack_t));

	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
	new->n = n;
	if (*head == NULL)
		new->next = NULL;
	else
	{
		new->next = *head;
		(*head)->prev = new;
	}
	*head = new;
	return (new);
}
