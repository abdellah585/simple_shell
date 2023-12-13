#include "shell.h"

/**
 * strfree - frees a string of strings
 * @strstr: string of strings
 */
void strfree(char **strstr)
{
	char **a = strstr;

	if (!strstr)
		return;
	while (*strstr)
		free(*strstr++);
	free(a);
}

/**
 **_memset - fills memory with a constant byte
 *@memarea: the pointer to the memory area
 *@b: the byte to fill *memarea with
 *@n: the amount of bytes to be filled
 *Return: (memarea) a pointer to the memory area memarea
 */
char *_memset(char *memarea, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		memarea[i] = b;
	return (memarea);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous allocated block
 * @prev_size: byte size of previous block
 * @curr_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int prev_size, unsigned int curr_size)
{
	char *p;

	if (!ptr)
		return (malloc(curr_size));
	if (!curr_size)
		return (free(ptr), NULL);
	if (curr_size == prev_size)
		return (ptr);

	p = malloc(curr_size);
	if (!p)
		return (NULL);

	prev_size = prev_size < curr_size ? prev_size : curr_size;
	while (prev_size--)
		p[prev_size] = ((char *)ptr)[prev_size];
	free(ptr);
	return (p);
}

