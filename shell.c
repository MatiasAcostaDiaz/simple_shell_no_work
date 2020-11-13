#include "shell.h"

int read_command(char cmd[], char *par[])
{
	char *line;
	int count = 0, i = 0, j = 0;
	char *arr[100], *token;
	size_t buffsize = BUFFSIZE;
	char *first;

	line = malloc(sizeof(char) * buffsize);
	getline(&line,&buffsize,stdin);
	/*token = strtok(line, " \n");
	while (token != NULL)
	{
		arr[i++] = strdup(token);
		token = strtok(NULL, " \n");
	}
	strcpy (cmd, arr[0]);
	for (j = 0; j < i; j++)
		par[j] = arr[j];
	par[i] = NULL;*/
	first = strtok(line, " ");
	for (i = 0; first[i] != '\0'; i++)
		cmd[i] = first[i];
	printf("%s", first);
	par[0] = (char *)0;
}

int main(void)
{
	char cmd[100], command[100], *parameters[20];
	char *envp[] = { (char *) "PATH=/bin", (char *)0 };
	char print[] = "$ ";
	int res = 0;

	while (TRUE)
	{
		write(1, print, 2); /* print the prompt */
		res = read_command(command, parameters);
		if (fork() == 0)
		{
			strcpy(cmd, "/bin");
			strcat(cmd, "/ls");
			execve(cmd, command, envp);
		}
		else
		{
			wait(NULL);
		}
		
	}
}
