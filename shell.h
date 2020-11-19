#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define TRUE 1
#define FALSE 0
#define BUFFSIZE 1024
extern char **environ;
int _strlen(char *s);
char *read_command(void);
char **split_command(char *);
int exc_argument(char **, char *, int);
int _strcmp(char *s1, char *s2);
void print_string(char *);
int exit_func(void);
int env_func(void);
void sig_handler(int);
char *find_path(void);
char *full_path(char *);
char *_strcat(char *dest, char *src);
int search_in_path(char *path, char *command);
char *split_path(char *command);
int is_builtin(char *);
int exec_builtin(char *);
char *is_not_atty(void);
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
	int (*func)();
} op_t;
#endif
