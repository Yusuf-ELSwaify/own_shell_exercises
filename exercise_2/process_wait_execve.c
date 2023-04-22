#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/**
 * main - executes the command ls -l /tmp in 5 different child processes.
 * Each child should be created by the same process (the father).
 * (Wait for a child to exit before creating a new child).
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status, i = 0;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	while (i < 5)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
				exit(0);
			}
		}
		else
		{
			wait(&status);
			printf("Oh, it's all better now\n");
		}
		i++;
	}
	return (0);
}
