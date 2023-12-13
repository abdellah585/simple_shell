#include "shell.h"

/**
 * ptrfree - frees a pointer and makes the address NULL
 * @ptr: address of pointer to free
 *
 * Return: 1 if freed, else 0.
 */
int ptrfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

