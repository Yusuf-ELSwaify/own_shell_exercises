#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
char **tokenize(char *line, char *delimeter)
{
	char **tokens, *token;
	int i = 0;

	if (line == NULL)
		return (NULL);
	tokens = malloc(64 * sizeof(*tokens));
	if (tokens == NULL)
		return (NULL);
	token = strtok(line, delimeter);
	while (token && i < 63)
	{
		tokens[i] = token;
		token = strtok(NULL, delimeter);
		++i;
	}
	tokens[i] = NULL;
	return (tokens);
}
char *concat_path(char *dest, char *src)
{
	int dest_len = strlen(dest);
	int src_len = strlen(src);
	char *result = malloc(dest_len + src_len + 2);
	if (!result)
		return (NULL);
	strcpy(result, dest);
	strcat(result, "/");
	strcat(result, src);
	return (result);
}

char *_which(char *filename)
{
	unsigned int i = 0;
	char **tokens, *path, *command;
	struct stat st;
	
	if (stat(filename, &st) == 0)
		return (filename);
	path = getenv("PATH");
	tokens = tokenize(path, ":");
	while (tokens[i])
	{
		command = concat_path(tokens[i], filename);
		if (stat(command, &st) == 0)
			return (command);
		i++;
	}
}
/**
 * main - looks for files in the PATH directories if exist print its path.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	char *command = _which(av[1]);
	if (command != NULL)
		printf("%s\n", command);
	return (0);
}
