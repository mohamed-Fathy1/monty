#include "monty.h"

/**
 * print_error - func
 * @error: input
 * @line_number: input
 * @opcode: input
 * @stack: input
 */
void print_error(int error, unsigned int line_number, char *opcode,
		stack_t *stack)
{
	free_dlistint(stack);
	switch (error)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", opcode);
			break;
		case 3:
			fprintf(stderr, "L%d: Unknown instruction %s\n", line_number, opcode);
			break;
		case 4:
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			break;
		case 5:
			fprintf(stderr, "Error: malloc failed\n");
			break;
	}
	exit(EXIT_FAILURE);
}
