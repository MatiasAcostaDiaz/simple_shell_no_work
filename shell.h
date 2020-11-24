#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define GETSTATUS 101
#define GETPID 100
#define TRUE 1
#define FALSE 0
#define BUFFSIZE 1024
extern char **environ;
int _strlen(char *s);
char *read_command(void);
char **split_command(char *);
int exc_argument(char **, char *, char *, int);
int _strcmp(char *s1, char *s2);
void print_string(char *);
int exit_func(char **, int *);
int env_func(char **, int *);
void sig_handler(int);
char *find_path(void);
char *full_path(char *);
char *_strcat(char *dest, char *src);
int search_in_path(char *path, char *command);
char *split_path(char *command);
int is_builtin(char *);
int exec_builtin(char **, char *, char *, int *);
char *is_not_atty(void);
void clean_memory(char **, char *, char *, int);
int cd_func(char **, int *);
char *obtain_home(void);
int is_a_number(char *);
int string_to_int(char *);
int is_echo(char **);
char *get_pid(char *);
char *get_status(char *);
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
	int (*func)(char **, int *);
} op_t;
#endif
