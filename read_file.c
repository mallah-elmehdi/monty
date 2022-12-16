#include "monty.h"

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
	char *line_2 = NULL;
	char *instruction = NULL;
	ssize_t read;
	size_t len = 0;
	int lineInt = 1;

	while ((read = getline(&line_2, &len, fp)) != -1)
	{
		line = trimwhitespace(line_2);
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = 0;
		if (strlen(line) > 0)
		{
			instruction = strtok(line, " ");
			if (instruction && strcmp(instruction, "push") == 0)
				push_node_stack(fp, lineInt, stack_head);
			else if (instruction && strcmp(instruction, "pall") == 0)
				pall_stack(*stack_head);
			else
			{
				dprintf(2, "L%d: unknown instruction %s\n", lineInt, instruction);
				fclose(fp);
				free_stack(*stack_head);
				exit(EXIT_FAILURE);
			}
		}
		lineInt++;
	}
	if (line_2)
		free(line_2);
}
