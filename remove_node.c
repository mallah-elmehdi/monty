#include "monty.h"

/**
 * delete_dnodeint_at_index - function that deletes the node at index
 * @head: sstack_t list head
 * @index: index
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(sstack_t **head, unsigned int index)
{
	sstack_t *temp = *head;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		if ((*head)->next)
			(*head)->next->prev = (*head)->prev;
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	while (temp && index)
	{
		temp = temp->next;
		index--;
	}
	if (index)
		return (-1);
	if (temp->prev)
		temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);
	return (1);
}
