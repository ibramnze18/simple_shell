#include "shell.h"

/**
 * bfree - frees memory
 * @ptr: pointer
 * Return:  1 On Success, 0 on err
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

