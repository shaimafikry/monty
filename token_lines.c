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
/**
* printf("this is command 1 after tokenizations %s\n", command[0]);
* printf("this is command 2 after tokenizations %s\n", command[1]);
* printf("this is command 3 after tokenizations %s\n", command[2]);
*/

}
