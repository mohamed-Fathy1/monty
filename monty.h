#ifndef MONTY_H
#define MONTY_H


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_BUFFER 5112024
#define UNUSED(x) (void)(x)

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct pub_s - opcode and its function
 * @fd: the opcode
 * @is_LIFO: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct pub_s
{
	FILE *fd;
	int is_LIFO;
} pub_t;

extern pub_t pub;

void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void addStack(stack_t **stack, unsigned int line_number);
void addQueue(stack_t **stack, unsigned int line_number);
void add_asQueue(stack_t **stack, unsigned int line_number, int value);
void add_asStack(stack_t **stack, unsigned int line_number, int value);
void print_error(int error, unsigned int line_number, char *opcode,
		stack_t *stack);
void print_error1(int error, unsigned int line_number, char *opcode,
		stack_t *stack);
int is_integer(char *str);
int is_empty(stack_t *ptr);
int is_ascii(int ascii);
size_t stack_len(const stack_t *h);
void free_dlistint(stack_t *head);

#endif
