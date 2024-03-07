#include "monty.h"
/**
 * push_monty - to add values to stack
 * @head: the stack
 * @value: the value
 * @line_number: theline number
 * Return: no return
*/
void push_monty(stack_t **head, char *value,  unsigned int line_number)
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
add_node_first(&(*head), atoi(value));
}

/**
 * pall_monty - to print the stack value
 * @head: the stack
 * @line_number: theline number
 * Return: no return
*/
void pall_monty(stack_t **head,
__attribute__((unused)) unsigned int line_number)
{
stack_t *current;
if (head == NULL)
	return;

current = *head;

while (current != NULL)
{
	printf("%d\n", current->n);
	current = current->next;
}
}
/**
* pint_monty - to print the first stack value
 * @head: the stack
 * @line_number: theline number
 * Return: no return
*/
void pint_monty(stack_t **head, unsigned int line_number)
{
if (*head == NULL)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
* pop_monty - removes the top element of the stack.
 * @head: the stack
 * @line_number: theline number
 * Return: no return
*/
void pop_monty(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	if (*head == NULL)
	{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
	}
	current = (*head);
	(*head) = current->next;
	if (current->next != NULL)
		current->next->prev = NULL;
	current = (*head);
	free(current);
}

/**
 * swap_monty - removes the top element of the stack.
 * @head: the stack
 * @line_number: theline number
 * Return: no return
*/
void swap_monty(stack_t **head, unsigned int line_number)
{

	if (*head == NULL|| (*head)->next == NULL)
	{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

}

/**
 * add_monty - removes the top element of the stack.
 * @head: the stack
 * @line_number: theline number
 * Return: no return
*/
void add_monty(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

}


/**
 * nop_monty - do nothing
 * @stack: linked list start
 * @line_number: line number
 * Return: no return
*/
void nop_monty(__attribute__((unused)) stack_t **head,
__attribute__((unused))  unsigned int line_number)
{

}
