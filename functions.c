#include "shell.h"

#define TOKEN_BUFFSIZE 64
#define TOKEN_DELIM " \t\r\n\a"

static volatile int keep_running = 1;



char *read_command(void)
{
	char *buffer;
	size_t buffsize = BUFFSIZE;
	int c;

	buffer = (char *)malloc(buffsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(EXIT_FAILURE);
	}
	c = getline(&buffer, &buffsize, stdin);
		if (c == -1)
		{
			if (c == EOF)
			{
				write(1, "\n", 1);
				free(buffer);
				exit(EXIT_SUCCESS);
			}
			perror("An error ocurred");
		}
	return (buffer);
}

char **split_command(char *buffer)
{
	int position = 0, buffsize = TOKEN_BUFFSIZE;
	char **tokens, *token;

	tokens = malloc(buffsize * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Unable to allocate\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, TOKEN_DELIM);
	if (is_builtin(token) == FALSE)
	{
		while (token != NULL)
		{
			tokens[position++] = token;
			if (position >= buffsize)
			{
				buffsize += TOKEN_BUFFSIZE;
				tokens = realloc(tokens,  buffsize * sizeof(char *));
				if (tokens == NULL)
				{
					perror("Unable to allocate\n");
					exit(EXIT_FAILURE);
				}
			}
		token = strtok(NULL, TOKEN_DELIM);
		}
	}
	tokens[position] = NULL;
	return (tokens);
}

int exc_argument(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("error");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0)
	{
		perror("error");
	} else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}

int is_builtin(char *token)
{
	int i = 0;
	op_t options[] = {
	{"exit", exit_func}, {"env", env_func}, {NULL, NULL}
	};

	while (options[i].cmd != NULL)
	{
		if ((_strcmp(token, options[i].cmd)) == 0)
		{
			options[i].func();
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
