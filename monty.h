#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
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

void line_token(char *lines, char *command[1024]);
void filter_input(stack_t **head, char *command[3], unsigned int line_number);
void add_node_first(stack_t **head, int);
void exe_monty(char *, stack_t **, unsigned int);
void push_monty(stack_t **head, char *, unsigned int);
void pall_monty(stack_t **head, unsigned int);
void pint_monty(stack_t **head, unsigned int);
void pop_monty(stack_t **head, unsigned int line_number);
void swap_monty(stack_t **head, unsigned int line_number);
void add_monty(stack_t **head, unsigned int line_number);
void nop_monty(stack_t **head, unsigned int line_number);
void free_list(stack_t **head);
#endif
