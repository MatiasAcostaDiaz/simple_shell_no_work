#include "shell.h"

/**
 * _strlen - count the leng of s
 * @s: pointer received
 * Return: the lenght of the character received
 */

int _strlen(char *s)
{

int i = 0;

while (*(s + i) != 0)
	i++;
return (i);
}

/**
 * _strcmp - compair 2 strings
 * @s1: the first string
 * @s2: second string
 * Return: a number
 */

int _strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2)  && (*s1 != '\0'))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
