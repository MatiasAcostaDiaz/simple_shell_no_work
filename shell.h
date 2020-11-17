#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define TRUE 1
#define FALSE 0
#define BUFFSIZE 1024
extern char **environ;
int _strlen(char *s);
char *read_command(void);
char **split_command(char *);
int exc_argument(char **);
int _strcmp(char *s1, char *s2);
void print_string(char *);
void exit_func(void);
void env_func(void);
char *find_path(void);
char *full_path(char *);
char *_strcat(char *dest, char *src)
char *search_in_path(char *path, char *command);
/**
 * struct op - Short description
 * @cmd: the name of the command
 * @func: pointer to func
 *
 * Description: Longer description
 */
typedef struct op
{
	char *cmd;
	void (*func)();
} op_t;
#endif
