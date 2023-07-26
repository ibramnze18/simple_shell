#include "shell.h"

/**
 * _myhistory - A func that displays history list items.
 * @info:  function parameter
 *  Return: 0 always
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - A func that converts alias to string
 * @info: function  parameter
 * @str:  string alias
 *
 * Return: Alaways 0 on success,  error 1.
 */
int unset_alias(info_t *info, char *str)
{
	char *ptr, strr;
	int ret;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);

	strr = *ptr;

	*ptr = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*pyr = strr;
	return (ret);
}

/**
 * set_alias - Converts alias code to string
 * @info: function paramter
 * @str: string alias
 *
 * Return: on success 0, on error 1
 */
int set_alias(info_t *info, char *str)
{
	char *ptr;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias -  Function prints an alias string
 * @node: alias node to be
 *
 * Return: Aways 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *s = NULL, *b = NULL;

	if (node)
	{
		s = _strchr(node->str, '=');
		for (b = node->str; b <= s; b++)
		_putchar(*b);
		_putchar('\'');
		_puts(s + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - function imitates the alias builtin func
 * @info: function parameter
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int k = 0;
	char *q = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (k = 1; info->argv[k]; k++)
	{
		q = _strchr(info->argv[k], '=');
		if (q)
			set_alias(info, info->argv[k]);
		else
			print_alias(node_starts_with(info->alias, info->argv[k], '='));
	}

	return (0);
}

