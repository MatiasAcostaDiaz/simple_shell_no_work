#include "shell.h"

/**
 * main - entry point
 * Return: 1 or 0 if is succesfull or failed
 */

int main(void)
{
	char *buffer, **command, *path;
	int status = 1;
	size_t buffsize = BUFFSIZE;

	command = malloc(buffsize * sizeof(char));
	signal(SIGINT, sig_handler);
	while (status)
	{
			write(STDIN_FILENO, "$ ", 2);
			buffer = read_command();
		//	if (buffer[0] == -1)
		//		break;
			command  = split_command(buffer);
			if (_strcmp(command[1], "builtin") != 0)
			{
				path = split_path(command[0]);
				status = exc_argument(command, path);
			}
			
			else
			{
				status = exec_builtin(command[0]);
				if (status != 0)
					break;
			} 
		}
	free(path);
	free(command);
	free(buffer);
	return (0);
}

/**
 * sig_handler - catch the ctrl + c
 * @sign: the number of the signal
 */

void sig_handler(int sig)
{
	(void)sig;
	signal(SIGINT, sig_handler);
	write(STDIN_FILENO, "\n$ ", 3);
}
