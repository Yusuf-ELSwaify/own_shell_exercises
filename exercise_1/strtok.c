#include <stdio.h>
#include <string.h>
/**
 * main - splits a string and returns an array of each word of the string.
 *
 * Return: Always 0.
 */
#define DELIMITER " \n\t"
int main(void)
{
	char *line = NULL, *token, i = 0;
	char *tokens[20];
	size_t bufsize = 1024;

	if (getline(&line, &bufsize, stdin) == -1)
		return (-1);
	token = strtok(line, DELIMITER);
	if (!token)
		return (0);
	while (token)
	{
		tokens[i++] = token;
		token = strtok(NULL, DELIMITER);
	}
	while (i--)
		printf("%s\n", tokens[i]);
	return (0);
}
