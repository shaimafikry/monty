#include "monty.h"
/**
 * line_token - tokenize the lines
 * @lines: lines to be token
 * @command: array to take input
 * Return: no return
*/
void line_token(char *lines, char *command[3])
{
char *token;
int i = 0;

token = strtok(lines, " \t\n");
while (token != NULL)
{
	/*printf("%s this is token \n", token);*/
	command[i] = token;
	token = strtok(NULL, " \t\n");
	i++;

}
/*printf("this is command all after tokenizations %s\n", *command);*/
command[i] = NULL;
}
