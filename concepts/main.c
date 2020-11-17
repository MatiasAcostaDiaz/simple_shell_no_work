#include "../shell.h"

int main(int argc, char *argv[])
{
	int i = 0, j = 0;
	char *av[] = {"-lah",NULL};
	char *envp[] = {NULL};
	
	if(execve(argv[1],av,envp) == -1)
		perror("Error");

	return 0;
}
