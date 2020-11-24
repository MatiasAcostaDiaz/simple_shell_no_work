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
	int position = 0, buffsize = TOKEN_BUFFSIZE, echo_flag = FALSE;
	char **tokens, *token, *procid, *status;

	tokens = malloc(buffsize * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Unable to allocate\n");
		exit(EXIT_FAILURE);
	}
	while (buffer[0] ==  32)
	{
		if (buffer[0] == '\0')
			return (NULL);
		buffer++;
	}
	if (is_echo(token) == TRUE)
		echo_flag = TRUE;
	token = strtok(buffer, TOKEN_DELIM);
	while (token != NULL && token[0] != '#')
	{
		if (echo_flag == TRUE && position >= 1)
		{
			if (is_var_rep(token) == GETPID)
			{
				tokens[position++] = 
			}
			else if (is_var_rep(token) == GETSTATUS)
			{
				tokens[position++] = get_status(token);
			}
		}
		else
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
 * @command: the command with parameters
 * @path: the path of the command
 * @buffer: the string of the command with the parameters
 * @tty: flag if is tty or nota			
 * Return: 1 or 0 if the command fail or is succesfull
 */

int exc_argument(char **command, char *path, char *buffer, int tty)
{
	pid_t pid;
	int status, error = 0;

	pid = fork();
	if (pid < 0)
		perror("Error");
	if (pid == 0)
	{
		if (execve(command[0], command, environ) == -1 && execve(path, command, environ) == -1)
		{
			if (command[0][0] == '/' && command[0][1] == '\0')
			{
				print_string("-hsh: /: is a directory\n");
				exit(126);
			}
			else if (command[0][0] == '.' && command[0][1] == '\0')
			{
				print_string("-hsh: .: filename argument required\n.: usage: . filename [arguments]");
				exit(2);
			}
			else
			{
				print_string(command[0]);
				print_string(": command not found\n");
				exit(127);
			}
		}
	}
	else
	{
		wait(&status);
	}
	if (tty == TRUE)
		return (0);
	clean_memory(command, path, buffer, FALSE);
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


