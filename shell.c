#include "shell.h"

static volatile int keep_running = 1;


void sig_handler(int sign)
{
	keep_running = 0;
	write(1,"\n",1);
	print_prompt();
}

int main(void)
{
	char *buffer, **command;
	int status;
	size_t buffsize = BUFFSIZE;

	command = malloc(buffsize * sizeof(char));
	signal(SIGINT, sig_handler);
	do {
		if (keep_running = 1)
		{
			print_prompt();
			keep_running = 0;
		}
		buffer = read_command();
		command  = split_command(buffer);
		status = exc_argument(command);
		}
	while (status);
}

void print_prompt(void)
{
	write(1, "$ ", 2);
}
