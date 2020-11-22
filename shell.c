#include "shell.h"

/**
 * main - entry point
 * Return: 1 or 0 if is succesfull or failed
 */

int main(void)
{
	char *buffer = NULL, **command = NULL, *path = NULL;
	int status = 1;
	int fd = 0, tty = FALSE, stat = 0;
	int *exit_status = &stat;

	signal(SIGINT, sig_handler);
/*	if (isatty(fd) == FALSE)
		tty = TRUE; */
	while (status)
	{
			if (isatty(fd) == TRUE)
			write(STDIN_FILENO, "$ ", 2);
			buffer = read_command();
			if (buffer == NULL || buffer[0] == '\n')
			{
				if (buffer[0] == '\n')
					free(buffer);
				continue;
			}
			command = split_command(buffer);
			if (command[0] == NULL)
				continue;
			if (is_builtin(command[0]) == FALSE)
			{
				path = split_path(command[0]);
				status = exc_argument(command, path, buffer, tty);
			}
			else
			{
				status = exec_builtin(command, path, buffer, exit_status);
				clean_memory(command, path, buffer, TRUE);
				if (status == -2)
					break;
			}
	}
	return (stat);
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
