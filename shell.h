#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define TRUE 1
#define BUFFSIZE 1024
int _strlen(char *s);
char *read_command(void);
char **split_command(char *);
int exc_argument(char **);
#endif
