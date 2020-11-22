#include "shell.h"

int is_var_replacement(char **command)
{
	if (_strcmp(command[0], "echo") == 0)
	{
		if(command[1][0] == '$')
		{
			if (command[1][1] == '$')
				return (GETPID);
			if (command[1][1] == '?')
				return(O_EX_STAT);
		}
	}
	return(0);
}
