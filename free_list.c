#include "monty.h"
/**
 * free_list - free ths list
 * @head: stck head
 * Return: no return
 */

void free_list(stack_t **head)
{
	stack_t *current = NULL, *next = NULL;

	if (*head == NULL)
		return;
	current = (*head);
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(next);
	free(head);
}
