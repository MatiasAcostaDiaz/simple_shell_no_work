#include "shell.h"

int main(void)
{
	char *buffer, **command;
	int status;
	size_t buffsize = BUFFSIZE;

	command = malloc(buffsize * sizeof(char));
	do {
		write(1, "$ ", 2);
		buffer = read_command();
		command  = split_command(buffer);
		status = exc_argument(command);
		}
	while (status);
}
