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
