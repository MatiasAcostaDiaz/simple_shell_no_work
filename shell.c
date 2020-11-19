#include "shell.h"

/**
 * main - entry point
 * Return: 1 or 0 if is succesfull or failed
 */

int main(void)
{
	char *buffer, **command;
	int status;
	size_t buffsize = BUFFSIZE;

	command = malloc(buffsize * sizeof(char));
	if (signal(SIGINT, sig_handler))
		print_prompt();
	do {
		print_prompt();
		buffer = read_command();
		command  = split_command(buffer);
		status = exc_argument(command);
		}
	while (status);
}

/**
 * sig_handler - catch the ctrl + c
 * @sign: the number of the signal
 */

void sig_handler(int sign)
{
	write(1, "\n", 1);
	print_prompt();
}

/**
 * print_prompt - print the prompt
 */

void print_prompt(void)
{
	write(1, "$ ", 2);
}
