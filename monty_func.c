#include "monty.h"
/**
 * push_monty - to add values to stack
 * @stack: the stack
 * @value: the value
 * @line_number: theline number
 * Return: no return
*/
void push_monty(stack_t **stack, char *value,  unsigned int line_number)
{
/*handling errors*/
if (value == NULL || (isdigit(atoi(value))))
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
add_node_first(&(*stack), atoi(value));
}

/**
 * pall_monty - to print the stack value
 * @stack: the stack
 * @line_number: theline number
 * Return: no return
*/
void pall_monty(stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
stack_t *current;
if (stack == NULL)
	return;

current = *stack;

while (current != NULL)
{
	printf("%d\n", current->n);
	current = current->next;
}
}
/**
* pint_monty - to print the first stack value
 * @stack: the stack
 * @line_number: theline number
 * Return: no return
*/
void pint_monty(stack_t **stack, unsigned int line_number)
{
if (stack == NULL)
{
	fprintf(stderr, "L%d: can't pint, stack empty", line_number);
	exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * 
*/
void nop_monty(__attribute__((unused)) stack_t **stack,__attribute__((unused))  unsigned int line_number)
{

	return;
}
