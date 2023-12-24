#include "monty.h"
/**
 * main - entry
 * excuting and intrepreting monty file
 * @argc: count
 * @argv: file names
 * Return: 0 in success
*/

int main(int argc, char *argv[])
{
char *orders; /*to store from getline*/
char  *command[2];/* for tokenization*/
size_t size = 0;
unsigned int  line_number = 1;
int get_return;/*to hold return value of getline*/
FILE *monty_file;
char *file_name = argv[1];
stack_t **list;

list = malloc(sizeof(stack_t *));
if (list == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
*list = NULL;
/*handling errors*/
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}
monty_file = fopen(file_name, "r");
if (!monty_file)
{
fprintf(stderr, "Error: Can't open file %s\n", file_name);
exit(EXIT_FAILURE);
}
/*program*/
while (1)
{
get_return = getline(&orders, &size, monty_file);
if (get_return == -1)
{
	free(orders);
	break;
}
orders[strlen(orders)] = '\0';
if (orders[0] == '\0' || orders[0] == '\n')
{
	free(orders);
	continue;
}
else
{
	line_token(orders, command);
	line_number++;
	if (strcmp(command[0], "push") == 0)
	{
		push_monty(&(*list), command[1], line_number);
	}
	else
	{
		exe_monty(command[0], &(*list), line_number);

	}
}
}
fclose(monty_file);

return (0);

}
