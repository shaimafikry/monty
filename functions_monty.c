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
int i;
if (value == NULL)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
for (i = 0; value[i]; i++)
{

	if (i == 0 && value[i] == '-')
		continue;
	if (!isdigit(value[i]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

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
if (*stack == NULL)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* pop_monty - removes the top element of the stack.
 * @stack: the stack
 * @line_number: theline number
 * Return: no return
*/
void pop_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
	}

	current = (*stack);
	(*stack) = current->next;
	if (current->next != NULL)
		current->next->prev = NULL;
	free(current);
}
/**
 * nop_monty - do nothing
 * @stack: linked list start
 * @line_number: line number
 * Return: no return
*/
void nop_monty(__attribute__((unused)) stack_t **stack,
__attribute__((unused))  unsigned int line_number)
{

}
