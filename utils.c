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

/**
 * trimwhitespace - trim
 * @str: string
 *
 * Return: trimed str
 */
char *trimwhitespace(char *str)
{
	char *end;

	if (str == NULL)
		return (str);
	while (isspace((unsigned char)*str))
		str++;
	if (*str == 0)
		return (str);
	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
		end--;
	end[1] = '\0';
	return (str);
}
