#include "shell.h"

/**
 * exit_func - exit of the program and clean the memory
 * Return: nothing
 */

int exec_builtin(char **command, char *path, char *buffer, int *exit_status)
{
	int i = 0;
	op_t options[] = {
	{"exit", exit_func}, {"env", env_func}, {"cd", cd_func}, {NULL, NULL}
	};

	while (options[i].cmd != NULL)
	{
		if ((_strcmp(command[0], options[i].cmd)) == 0)
		{
			return(options[i].func(command, exit_status));
		}
		i++;
	}
	return (FALSE);
}

int exit_func(char **command, int *exit_status)
{
	if (command[1] == NULL)
		return (0);
	if (is_a_number(command[1]) == TRUE)
		*exit_status = string_to_int(command[1]);
	return (-2);
}

/**
 * env_func - print the enviroment variables
 * Return: nothing
 */

int env_func(char **command, int *exit_status)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		print_string(environ[i]);
		i++;
	}
	return (TRUE);
}

int cd_func(char **command, int *exit_status)
{
	char *home = NULL;

	if (command[1] == NULL)
	{
			home = obtain_home();
			if (chdir(home) == -1)
				perror("error");
			free(home);
	}
	
	else if (chdir(command[1]) == -1)
		perror("error");
	return (TRUE);
}
