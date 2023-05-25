#include "monty.h"



/**
 * mod - func
 * @stack: input
 * @line_number: input
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (is_empty(*stack) || stack_len(*stack) < 2)
		print_error(8, line_number, "mod", *stack);

	if ((*stack)->n == 0)
		print_error(9, line_number, NULL, *stack);
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}




