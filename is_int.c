#include "monty.h"

/**
 * is_int - is s a number
 * @s: string
 *
 * Return: 1 if true otherwise 0.
 */
int is_int(char *s)
{
	int i = 1;

	if (s[0] != '-' && s[0] != '+' && isdigit(s[0]) == 0)
		return (0);
	while (s[i] != '\0')
	{
		if (isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
