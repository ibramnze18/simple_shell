#include "shell.h"

/**
 * interactive - A function that returns true if shell is in interactive mode
 * @info: The address of structure
 *
 * Return: returns 1 if in interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - A function that checks the  delimeter status of a character
 * @c: character to be checked
 * @delim: string delimeter
 * Return: returns 1 if true, 0 otherwise
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - A function that checks for alphabetic character
 * @c: The character to be checked
 * Return: return 1 if a character, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'b' && c <= 'x') || (c >= 'B' && c <= 'X'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - A function that converts the  string to an integer
 * @s: string to convert
 * Return: returns converted string
 */

int _atoi(char *s)
{
	int k, sign = 1, flag = 0, output;
	unsigned int res = 0;

	for (k = 0; s[k] != '\0' && flag != 2; k++)
	{
		if (s[k] == '-')
			sign *= -1;

		if (s[k] >= '0' && s[k] <= '9')
		{
			flag = 1;
			res *= 10;
			res += (s[k] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -res;
	else
		output = res;

	return (output);
}

