#include "shell.h"

/**
 * main - entry point
 * Return: 1 or 0 if is succesfull or failed
 */

int main(void)
{
	char *buffer, **command, *path;
	int status;
	size_t buffsize = BUFFSIZE;

	command = malloc(buffsize * sizeof(char));
	signal(SIGINT, sig_handler);
	do {
		write(STDIN_FILENO, "$ ", 2);
		buffer = read_command();
		command  = split_command(buffer);
		path = split_path(command[0]);
		status = exc_argument(command, path);
		}
	while (status);
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
