#include "shell.h"

/**
 * exit_func - exit of the program and clean the memory
 * Return: nothing
 */

int exec_builtin(char *command)
{
	int i = 0;
	op_t options[] = {
	{"exit", exit_func}, {"env", env_func}, {NULL, NULL}
	};

	while (options[i].cmd != NULL)
	{
		if ((_strcmp(command, options[i].cmd)) == 0)
		{
			options[i].func();
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int exit_func(void)
{
	return (1);
}

/**
 * env_func - print the enviroment variables
 * Return: nothing
 */

int env_func(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		print_string(environ[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
