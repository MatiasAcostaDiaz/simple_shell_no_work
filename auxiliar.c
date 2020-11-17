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

void print_string(char *string)
{
	int i = 0, count = 0;
	char *buffer;

	count = _strlen(string);
	buffer = (char *)malloc(sizeof(char) * count);
	while (i < count)
	{
		buffer[i] = string[i];
		i++;
	}
	write(1, buffer, count);
}

/**
 * _strcat - function that append the contain in src in the buffer of dest
 * @dest: the destination to append
 * @src: the text to copy
 * Return: a char pointer
 */

char *_strcat(char *dest, char *src)
{
	int len = 0, i = 0;
	char *cdest, *csrc;

	cdest = dest;
	csrc = src;
	while (*(cdest + len) != 0)
		len++;
	while (*(csrc + i) != 0)
	{
		cdest[len + i] = csrc[i];
		i++;
	}
	cdest[len + i + 1] = '\0';
	return (cdest);
}
