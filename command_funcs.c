#include "shell.h"

int have_a_comma(char *buffer)
{
		

}

int is_echo(char *token)
{
	char copy[5];
	int i = 0;

	for(i = 0; i < 4; i++)
		copy[i] = command[0][i];
	printf("la copy es %s", copy);
	if (_strcmp(copy, "echo") == 0)
	{
		return (TRUE);
	}
	return (FALSE);
}

int is_var_rep(char *token)
{
	int i = 0;

	for (i = 0; token[i] != '\0'; i++)
	{
		if (token[i] == '$')
		{
			if (token[i + 1] != '\0' && token[i + 1] == '$')
				return (GETPID);
			else if (token[i + 1] != '\0' && token[i + 1] == '?')
				return (GETSTATUS);
		}
	}
	return (FALSE);
}
