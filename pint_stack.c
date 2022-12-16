#include "monty.h"

/**
 * pint_stack - function that print a stack
 * @stack_head: stack head
 *
 * Return: void.
 */
void pint_stack(FILE *fp, int lineInt, sstack_t *stack_head)
{
    if (stack_head == NULL)
    {
        dprintf(2, "L%d: can't pint, stack empty\n", lineInt);
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", stack_head->n);
}
