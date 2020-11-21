#include "shell.h"

#define TOKEN_BUFFSIZE 64
#define TOKEN_DELIM " \t\r\n\a"

/**
 * read_command - read the command enter
 * Return: the command
 */

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
				exit(0);
			}
			perror("An error ocurred");
		}
	return (buffer);
}

/**
 * split_command - split the command with the differents arguments
 * @buffer: the command
 * Return: an array with the command and parameters
 */

char **split_command(char *buffer)
{
	int position = 0, buffsize = TOKEN_BUFFSIZE, i;
	char **tokens, *token;

	tokens = malloc(buffsize * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Unable to allocate\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, TOKEN_DELIM);
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
	tokens[position] = NULL;
	return (tokens);
}

/**
 * exc_argument - excecute a command
 * @args: the command with parameters
 * Return: 1 or 0 if the command fail or is succesfull
 */

int exc_argument(char **args, char *path, char *buffer, int tty)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
		perror("Error");
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{}
		if (execve(path, args, environ) == -1)
		{
			perror("Error");
		}
		else
		{
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
	if (tty == TRUE)
		return (0);
	clean_memory(args, path, buffer, FALSE);
	return (1);
}

/**
 * is_builtin - function that compare if the command is a builtin command
 * @token: the command
 * Return: True(1) or false(0)
 */

int is_builtin(char *token)
{
	int i = 0;
	op_t options[] = {
	{"exit", exit_func}, {"env", env_func}, {"cd", cd_func}, {NULL, NULL}
	};

	while (options[i].cmd != NULL)
	{
		if ((_strcmp(token, options[i].cmd)) == 0)
		{
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}


