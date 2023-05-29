#include "monty.h"


/**
 * addStack - func
 * @stack: input
 * @line_number: input
 */
void addStack(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	UNUSED(stack);
	pub.is_LIFO = 1;
}


/**
 * addQueue - func
 * @stack: input
 * @line_number: input
 */
void addQueue(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	UNUSED(stack);
	pub.is_LIFO = 0;
}



/**
 * add_asStack - func
 * @stack: input
 * @line_number: input
 * @value: input
 */
void add_asStack(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *new_stack = malloc(sizeof(stack_t));

	if (new_stack == NULL)
		print_error(5, line_number, NULL, *stack);

	new_stack->next = *stack;
	new_stack->prev = NULL;
	new_stack->n = value;
	if (*stack)
		(*stack)->prev = new_stack;
	*stack = new_stack;
}


/**
 * add_asQueue - func
 * @stack: input
 * @line_number: input
 * @value: input
 */
void add_asQueue(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *tmp = *stack;
	stack_t *new_stack = malloc(sizeof(stack_t));

	if (new_stack == NULL)
		print_error(5, line_number, NULL, *stack);

	while (tmp && tmp->next)
		tmp = tmp->next;

	new_stack->n = value;
	new_stack->next = NULL;

	if (tmp)
	{
		tmp->next = new_stack;
		new_stack->prev = tmp;
	}
	else
	{
		*stack = new_stack;
		new_stack->prev = NULL;
	}
}



