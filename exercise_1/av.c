#include <stdio.h>

/**
 * main - prints all the arguments, without using ac.
 *
 * Return: Always 0.
 */
int main(int ac, char **argv)
{
	while (*argv != NULL)
		printf("%s\n", *argv++);
	return (0);
}
