#include "shell.h"

char *find_path(void)
{
	int i = 0, j = 0;
	char buffer[5];

	if (buffer == NULL)
		perror("Unable to allocate");
	while (environ[i] != NULL)
	{
		for(j = 0; j < 4; j++)
		{
			buffer[j] = environ[i][j];
		}
		if (_strcmp(buffer, "PATH") == 0)
			return (full_path(environ[i]));
		i++;
	}
	return (NULL);
}

char *full_path(char *path)
{
	char *copy;
	int i, j;

	copy = (char *)malloc(sizeof(char) * _strlen(path));
	for (i = 5, j = 0; path[i] != '\0'; i++, j++)
		copy[j] = path[i];
	return (copy);
}

char *split_path(char *path, char *arg)
{
	int position = 0, buffsize = 64;
	char **tokens, *token;

	tokens = malloc(buffsize * sizeof(char *));
	if (tokens == NULL)
	{	
		perror("Unable to allocate\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		tokens[position++] = token;
		if (position >= buffsize)
		{
			buffsize += 64;
			tokens = realloc(tokens,  buffsize * sizeof(char *));
			if (tokens == NULL)
			{
				perror("Unable to allocate\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, ":");
	}
	tokens[position] = NULL;
	return (tokens);
}

int *search_in_path(char *path, char *arg)
{
	
}
