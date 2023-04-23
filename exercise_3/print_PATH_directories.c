#include <stdio.h>
#include <string.h>

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
 * print_path_directories - print every directory in the PATH
 *
 */
void print_path_directories()
{
	char *path = _getenv("PATH"), *directory;
	if (path == NULL)
	{
		printf("PATH environment variable not set\n");
		return;
	}
	directory = strtok(path, ":");
	while (directory)
	{
		printf("%s\n", directory);
		directory = strtok(NULL, ":");
	}
}
/**
 * main - Entery point 
 * Return: 0 (always)
 */
int main(void)
{
	print_path_directories();
	return (0);
}
