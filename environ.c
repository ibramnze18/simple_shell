#include "shell.h"

/**
 * _myenv -  Function that prints the current environment
 * @info:  Function argument
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - Function that gets the environ variable
 * @info: function argument
 * @name: Name of env
 *
 * Return: Aways 0
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *q;

	while (node)
	{
		q = starts_with(node->str, name);
		if (q && *q)
			return (q);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv -  Function taht Initializes a new env var/modify existing one
 * @info: function argument
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv -  Function that deletes an env var
 * @info: function argument.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int j;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= info->argc; j++)
		_unsetenv(info, info->argv[j]);

	return (0);
}

/**
 * populate_env_list - Function that creates a new node
 * @info: function argument
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t num;

	for (num = 0; environ[num]; num++)
		add_node_end(&node, environ[num], 0);
	info->env = node;
	return (0);
}
