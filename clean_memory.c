#include "shell.h"

int clean_memory(char **command, char *path, char *buffer)
{
	free(command);
	free(path);
	free(buffer);
}
