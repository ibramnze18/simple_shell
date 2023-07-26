#include "shell.h"

/**
 * _eputs - Function prints string input
 * @str: function argument(string to print)
 *
 * Return: Aways 0
 */
void _eputs(char *str)
{
	int count = 0;

	if (!str)
		return;
	while (str[count] != '\0')
	{
		_eputchar(str[count]);
		count++;
	}
}

/**
 * _eputchar - Function that writes character c to STD_ERR
 * @c: Character to be printed
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set.
 */
int _eputchar(char c)
{
	static int q;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || q >= WRITE_BUF_SIZE)
	{
		write(2, buf, q);
		q = 0;
	}
	if (c != BUF_FLUSH)
		buf[q++] = c;
	return (1);
}

/**
 * _putfd - Function that writes the char c to given file descriptor
 * @c: Character to be printed
 * @fd: filedescriptor
 *
 * Return: On success 1, error, -1 is returned, and errno is set
 */
int _putfd(char c, int fd)
{
	static int count;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || count >= WRITE_BUF_SIZE)
	{
		write(fd, buf, count);
		count = 0;
	}
	if (c != BUF_FLUSH)
		buf[count++] = c;
	return (1);
}

/**
 * _putsfd - Function that prints input string
 * @str: String to be printed
 * @fd: filedescriptor
 *
 * Return: Number of chars.
 */
int _putsfd(char *str, int fd)
{
	int p = 0;

	if (!str)
		return (0);
	while (*str)
	{
		p += _putfd(*str++, fd);
	}
	return (p);
}

