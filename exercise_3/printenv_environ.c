#include <stdio.h>

extern char **environ;
/**
 * main - prints the environment arguments using 'environ' global variable
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned int i = 0;
	char **env = environ;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
