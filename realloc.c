#include "shell.h"

/**
 * _memset - Fills memory with bytes
 * @s: memory pointer
 * @b:  byte to fill str with
 * @n: number of bytes
 * Return: Always 0 on success
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int l;

	for (l = 0; l < n; l++)
		s[l] = b;
	return (s);
}

/**
 * ffree - Free trings
 * @pp: strings duouble ptr
 */
void ffree(char **pp)
{
	char **ptr = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(ptr);
}

/**
 * _realloc - Reallocated block of memory
 * @ptr: pointer
 * @old_size: old block size
 * @new_size: New block size
 * Return: 0 on success
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

