#include "monty.h"

/**
 * push - func
 * @stack: input
 * @line_number: input
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack = malloc(sizeof(stack_t));
	int value;
	char *tok_val = strtok(NULL, " \n");

	if (tok_val == NULL || !is_integer(tok_val))
		print_error(4, line_number, NULL);
	value = atoi(tok_val);

	if (new_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_stack->next = *stack;
	new_stack->prev = NULL;
	new_stack->n = value;
	*stack = new_stack;
}


/**
 * pall - func
 * @stack: input
 * @line_number: input
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	UNUSED(stack);
	UNUSED(line_number);
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

