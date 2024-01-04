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
				{"nop", nop_monty},
				{NULL, NULL}
				};
while (monty_func[i].opcode != NULL)
{
	if (strcmp(command, monty_func[i].opcode) == 0)
	{
		monty_func[i].f(&(*head), number);
		return;
	}
	i++;
	
}
fprintf(stderr, "L%d: unknown instruction %s\n", number, command);
exit(EXIT_FAILURE);
}
