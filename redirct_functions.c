#include "monty.h"
/**
 * filter_input -  to take input and compare it
 * @command: line of order
 * @head: stack
 * @line_number: line number
 * Return: no return
*/
void filter_input(stack_t **head, char *command[2], unsigned int line_number)
{
	if (strcmp(command[0], "push") == 0)
	{
		push_monty(&(*head), command[1], line_number);
	}
	else
	{
		exe_monty(command[0], &(*head), line_number);

	}
}
