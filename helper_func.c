#include "monty.h"

/**
 * is_integer - function
 * @str: input
 * Return: int
 */
int is_integer(char *str)
{
	int i = str[0] == '-' ? 1 : 0;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}



/**
 * is_empty - function
 * @ptr: input
 * Return: int
 */
int is_empty(stack_t *ptr)
{
	return (ptr == NULL);
}
