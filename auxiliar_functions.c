#include "shell.h"

int is_a_number(char *buffer)
{
	int i = 0, count = 0;

	if (buffer == NULL)
		return (FALSE);
	count = _strlen(buffer);
	for (i = 0; i < count; i++)
	{
		if (buffer[i] >= 48 && buffer[i] <= 57)
			continue;
		else
			break;
	}
	if (i != count)
		return(FALSE);
	else
		return (TRUE);
}

int string_to_int(char *buffer)
{
	return(98);
}
