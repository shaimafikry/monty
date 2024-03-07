#include "monty.h"
/**
 * add_node_first -  add node at the top of the stack
 * @head: pointer to the head of the stack
 * @num: value to added
 * Return: no return
*/
void add_node_first(stack_t **head, int num)
{
stack_t *new_node = NULL;

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
	free_list(&(*head));
	fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
}
new_node->n = num;
new_node->next = *head;
new_node->prev = NULL;
if ((*head) != NULL)
(*head)->prev = new_node;
*head = new_node;
}
