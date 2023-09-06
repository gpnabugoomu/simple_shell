#include "shell.h"

/**
 * bfree - function to free pointer and NULL the address
 * @ptr: pointer address
 *
 * Return: if freed 1,
 * and 0 otherwise
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
