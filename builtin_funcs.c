#include "shell.h"

/**
 * exit_func - exit of the program and clean the memory
 * Return: nothing
 */
void exit_func(void)
{
	exit(0);
}

/**
 * env_func - print the enviroment variables
 * Return: nothing
 */

void env_func(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		print_string(environ[i]);
		write(1, "\n", 1);
		i++;
	}
}
