#include "monty.h"

/**
 * add_dnodeint - function that adds a new node at the beginning
 * @head: dlistint_t list head
 * @n: data
 *
 * Return: the address of the new element, or NULL if it failed.
 */
sstack_t *add_dnodeint(sstack_t **head, const int n)
{
	sstack_t *new = malloc(sizeof(sstack_t));

	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
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

/**
 * push - function that push to stack
 * @lineInt: line number
 * @stack_head: stack head
 *
 * Return: void.
 */
void push(int lineInt, sstack_t **stack_head)
{
	char *value = NULL;

	value = strtok(NULL, " ");
	if (value == NULL || atoi(value) < 0)
	{
		dprintf(2, "L%d: usage: push integer\n", lineInt);
		exit(EXIT_FAILURE);
	}
	add_dnodeint(stack_head, atoi(value));
}

/**
 * pall - function that print a stack
 * @stack_head: stack head
 *
 * Return: void.
 */
void pall(sstack_t *stack_head)
{
	while (stack_head)
	{
		printf("%d\n", stack_head->n);
		stack_head = stack_head->next;
	}
}

/**
 * read_file - function that read the monty file
 * @stack_head: stack head
 * @fp: file
 *
 * Return: void.
 */
void read_file(FILE *fp, sstack_t **stack_head)
{
	char *line = NULL;
	char *instruction = NULL;
	ssize_t read;
	size_t len = 0;
	int lineInt = 1;

	while ((read = getline(&line, &len, fp)) != -1)
	{
		line[strlen(line) - 1] = 0;
		instruction = strtok(line, " ");
		if (strcmp(instruction, "push") == 0)
			push(lineInt, stack_head);
		else if (strcmp(instruction, "pall") == 0)
			pall(*stack_head);
		else
		{
			dprintf(2, "L%d: unknown instruction %s\n", lineInt, instruction);
			exit(EXIT_FAILURE);
		}
		lineInt++;
	}
	if (line)
		free(line);
}

/**
 * main - main entry
 * @ac: arg length
 * @av: arg array
 *
 * Return: 0 or 1
 */
int main(int ac, char const **av)
{
	FILE *fp;
	sstack_t *stack_head = NULL;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	read_file(fp, &stack_head);
	fclose(fp);
	return (0);
}
