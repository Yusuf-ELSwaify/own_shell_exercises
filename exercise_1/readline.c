#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints "$ ", wait for the user to enter a command, prints it on the next line.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line;
	size_t bufsize = 1024;

	printf("$ ");
	while (getline(&line, &bufsize, stdin) != -1)
	{
		printf("%s", line);
		printf("$ ");
	}
	return (0);
}
