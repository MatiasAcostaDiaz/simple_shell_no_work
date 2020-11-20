#include "shell.h"

int clean_memory(char **command, char *path, char *buffer)
{
	free(command);
	if (path != NULL)
		free(path);
	free(buffer);
}
