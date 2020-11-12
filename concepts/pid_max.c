#include "../shell.h"

int main(void)
{
	int fd;
	char *buffer;

	fd = open("/proc/sys/kernel/pid_max", O_RDONLY);
	read(fd, buffer, 1024);
	close(fd);
	printf("%s\n", buffer); 
	
}
