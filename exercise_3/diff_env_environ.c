#include <stdio.h>

extern char **environ;
/**
 * main -  the address of env (the third parameter of the main function) and 'environ' (the global variable)
 *
 * Return: Always 0.
 */
int main(int argc, char **argv, char **env)
{
	printf("Address of env: %p\n", (void*)env);
	printf("Address of environ: %p\n", (void*)environ);
	return (0);
}
