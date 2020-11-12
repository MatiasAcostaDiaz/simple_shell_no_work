#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int pid;
	pid = fork();
	printf("FORK: %d\nPID: %d\nPPID: %d\n",pid,getpid(),getppid());

	return (0);
}
