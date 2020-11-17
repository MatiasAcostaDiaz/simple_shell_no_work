#include "shell.h"

char *find_path(void)
{
	int i = 0, j = 0;
	char buffer[5];

	if (buffer == NULL)
		perror("Unable to allocate");
	while (environ[i] != NULL)
	{
		for (j = 0; j < 4; j++)
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

char *split_path(char *command)
{
	char *token, *path, *fpath;

	path = find_path();
	fpath = malloc((_strlen(path) + _strlen(command) + 2) *sizeof(char));
	if (fpath == NULL)
		perror("Unable to allocate\n");
	token = strtok(path, ":");
	fpath = strcat(token, "/");
	fpath = strcat(token, command);
	printf("the token is %s\n", fpath);
	//search_in_path(token, command);
	while (token != NULL)
	{
		token = strtok(NULL, ":");
		if (token != NULL)
		{
			fpath = strcat(token, "/");
			fpath = strcat(token, command);
		}
			//search_in_path(token, command);
			printf("the token is %s\n",token);
	}
	return (NULL);
}
