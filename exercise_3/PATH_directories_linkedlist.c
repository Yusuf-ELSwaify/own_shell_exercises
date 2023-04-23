#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern char **environ;

typedef struct directory_node
{
	char *dir;
	struct directory_node *next;
} dir_n;

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
 * path_directories_to_linkedlist - add directories in PATH to linkedlist
 * @head: address to the head pointer of the linkedlist
 */
void path_directories_to_linkedlist(dir_n **head)
{
	char *path = _getenv("PATH");

	if (path == NULL)
	{
		printf("PATH environment variable not set\n");
		return;
	}
	char *dir = strtok(path, ":");

	while (dir != NULL)
	{
		dir_n *temp_node = malloc(sizeof(dir_n));

		if (temp_node == NULL)
		{
			exit(98);
		}
		temp_node->dir = strdup(dir);
		temp_node->next = *head;
		*head = temp_node;
		dir = strtok(NULL, ":");
	}
}
/**
 * print_linked_list - print directories linkedlist
 *
 */
void print_linked_list(dir_n *head)
{
	dir_n *current = head;

	while (current != NULL)
	{
		printf("%s\n", current->dir);
		current = current->next;
	}
}
/**
 * main - Entery point
 * Return: 0 (always)
 */
int main(void)
{
	dir_n *head = NULL;

	path_directories_to_linkedlist(&head);
	print_linked_list(head);
	return (0);
}
