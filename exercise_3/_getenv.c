#include <stdio.h>

extern char **environ;
/**
 * _getenv - searches for an environment variable by name.
 * @name: name of variable we search for.
 * Return: pointer to the value part of the environment variable.
 */
char *_getenv(const char *name)
{
	unsigned int i = 0;
	char **env = environ, *env_ptr, *name_ptr;

	while (*env != NULL)
	{
		env_ptr = *env;
		name_ptr = (char *)name;
		while (*env_ptr != '\0' && *name_ptr != '\0' && *env_ptr == *name_ptr)
		{
			if (*env_ptr == '=')
				break;
			env_ptr++;
			name_ptr++;
		}
		if (*env_ptr == '=')
			if (*name_ptr == '\0')
				return (env_ptr + 1);
		env++;
	}
	return (NULL);
}
/**
 * main - print the value of the environment variable we get it in arguments.
 * @argc: number of args
 * @argv: args contain name of an enviroment variable we need to get its value.
 *
 * Return: 0 (success) -1 if arguments not equal 2
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("take 1 argument\n");
		return (-1);
	}
	printf("%s\n", _getenv(argv[1]));
	return (0);
}
