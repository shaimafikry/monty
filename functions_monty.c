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
	stack_t *current = NULL;

	if (*head == NULL)
	{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
	}
	current = (*head);
	(*head) = current->next;
	if (current->next != NULL)
		current->next->prev = NULL;
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
	stack_t *first, *second;

	if (*head == NULL|| (*head)->next == NULL)
	{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
	first = (*head);
	second = (*head)->next;
	first->next = second->next;
	first->prev = second;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	(*head) = second;
}

/**
 * add_monty - removes the top element of the stack.
 * @head: the stack
 * @line_number: theline number
 * Return: no return
*/
void add_monty(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	int result;

	if (*head == NULL || (*head)->next == NULL)
	{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
	result = (*head)->n + (*head)->next->n;
	current = (*head);
	(*head) = current->next;
	(*head)->n = result;
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
void nop_monty(__attribute__((unused)) stack_t **head,
__attribute__((unused))  unsigned int line_number)
{

}
