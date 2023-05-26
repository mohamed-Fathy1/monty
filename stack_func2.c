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




/**
 * pchar - func
 * @stack: input
 * @line_number: input
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int ascii = 0;

	if (is_empty(*stack))
		print_error(6, line_number, "pchar", *stack);

	ascii = (*stack)->n;
	if (!is_ascii(ascii))
		print_error(10, line_number, NULL, *stack);
	putchar(ascii);
	putchar('\n');
}



/**
 * pstr - func
 * @stack: input
 * @line_number: input
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	int ascii = 0;
	stack_t *ptr = *stack;

	UNUSED(line_number);

	if (!is_empty(*stack))
		ascii = (*stack)->n;

	while (ptr && ascii && is_ascii(ascii))
	{
		putchar(ascii);
		ptr = ptr->next;
		if (ptr)
			ascii = ptr->n;
	}
	putchar('\n');
}



/**
 * rotl - func
 * @stack: input
 * @line_number: input
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	int tmp;
	stack_t *copy;

	UNUSED(line_number);

	if (stack && *stack)
	{
		tmp = (*stack)->n;

		for (copy = *stack; copy->next; copy = copy->next)
			copy->n = copy->next->n;
		copy->n = tmp;
	}
}


/**
 * rotr - func
 * @stack: input
 * @line_number: input
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	int next, current;
	stack_t *copy;

	UNUSED(line_number);

	if (stack && *stack)
	{
		copy = *stack;
		next = copy->n;

		while (copy->next)
		{
			current = next;
			next = copy->next->n;
			copy->next->n = current;
			copy = copy->next;
		}
		(*stack)->n = next;
	}
}

