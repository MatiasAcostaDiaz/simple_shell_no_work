#include "shell.h"

void exit_func(void)
{
	//exit(0);
	char *buffer = malloc(sizeof(char) * 1024);

	buffer = split_path("ls");
}

void env_func(void)
{
	int i;

	while (environ[i] != NULL)
	{
		print_string(environ[i]);
		write(1, "\n", 1);
		i++;
	}
}
