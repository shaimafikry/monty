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
/* to use at get line function*/
char *orders, *command[1024];/* for tokenization*/
size_t size = 0;
unsigned int  line_number = 1; /*to hold line numbers*/
FILE *monty_file;
char *file_name = argv[1];
stack_t **list;

list = malloc(sizeof(stack_t *));
if (list == NULL)
	fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
*list = NULL;
if (argc != 2)
	fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

monty_file = fopen(file_name, "r");
if (!monty_file)
	fprintf(stderr, "Error: Can't open file %s\n", file_name), exit(EXIT_FAILURE);

while (1)
{
	if ((getline(&orders, &size, monty_file) == -1))
		break;
	orders[strlen(orders)] = '\0';/*to make it a seperate line*/
	if (orders[0] == '\0' || orders[0] == '\n')
	{
		line_number++;
		continue; }
	else
	{
		line_token(orders, command);
		if (command[0] == NULL)
		{
			line_number++;
			continue; }
		filter_input(&(*list), command, line_number), line_number++; } }
free(orders);
free(command);
free(list);
fclose(monty_file);
return (0); }
