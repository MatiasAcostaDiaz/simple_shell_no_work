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
	char *token = NULL, *fpath, *path;
	struct stat fileStat;

	path = find_path();
	token = strtok(path, ":");

	fpath = malloc(sizeof(char) * BUFFSIZE);
	if (fpath == NULL)
		return (NULL);
	while (token != NULL)
	{
		fpath[0] = '\0';
		fpath = strcat(fpath, token);
		fpath = strcat(fpath, "/");
		fpath = strcat(fpath, command);
		printf("COMMAND 0 : %s and path: %s\n", command, fpath);
		if (stat(fpath, &fileStat) == 0)
		{
			printf("se encontro en el path:%s\n", fpath);
			return (fpath);
		}
		token = strtok(NULL, ":");
	}
	return (NULL);
}
