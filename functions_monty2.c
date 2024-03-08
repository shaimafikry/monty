#include "monty.h"

/**
 * add_monty - removes the top element of the stack.
 * @head: the stack
 * @line_number: theline number
 * Return: no return
*/
void add_monty(stack_t **head, unsigned int line_number)
{
	stack_t *current = NULL;
	int result = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
	free_list(&(*head));
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
 * @head: linked list start
 * @line_number: line number
 * Return: no return
*/
void nop_monty(__attribute__((unused)) stack_t **head,
__attribute__((unused))  unsigned int line_number)
{

}
