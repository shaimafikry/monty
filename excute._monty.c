#include "monty.h"

/**
 * exe_monty -  function to be excuted
 * @head: pointer to the head of the stack
 * @number: line number
 * @command: func name
 * Return: no return
*/

void exe_monty(char *command, stack_t **head, unsigned int number)
{
/*handling errors*/
int i = 0;
instruction_t monty_func[] = {
				{"pall", pall_monty},
				{"pint", pint_monty},
				{NULL, NULL}
				};
if (head == NULL)
{
fprintf(stderr, "list is not found\n");
return;
}

while (monty_func[i].opcode != NULL)
{
if (strcmp(command, monty_func[i].opcode) == 0)
{
monty_func[i].f(&(*head), number);
}
i++;
}

}
