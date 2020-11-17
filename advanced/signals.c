#include "../shell.h"
#include<signal.h> 
  
void handle_sigint(int sig) 
{ 
    printf("Caught signal %d\n", sig); 
} 
  

int main() 
{ 
	int i = 0;
	printf("test"); 
   while(1)
{
		printf("jj");
		sleep(1);
	} 
    return 0; 
} 
