#include "shell.h"

/**
 * _strlen -  string length
 * @s: string length to assertain
 * Return: length of string
 */
int _strlen(char *s)
{
	int l = 0;

	if (!s)
		return (0);

	while (*s++)
		l++;
	return (l);
}

/**
 * _strcmp - comparison of two strangs.
 * @s1: first strang
 * @s2: second string
 * Return: Always 0
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts beggings by haystack
 * @haystack: string to be search
 * @needle: substring to find
 * Return: next char address
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - adds two strings
 * @dest: destination buff
 * @src: source buff
 * Return: destination pointer  buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

