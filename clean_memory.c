#include "shell.h"

int clean_memory(char **command, char *path, char *buffer, int flag)
{
	free(command);
	if (flag == FALSE)
		free(path);
	free(buffer);
}
