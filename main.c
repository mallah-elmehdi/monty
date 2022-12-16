#include "monty.h"

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
	monty(fp, &stack_head);
	return (0);
}
