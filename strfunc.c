#include "shell.h"

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @str1: the first strang
 * @str2: the second strang
 *
 * Return: negative if str1 < str2, positive if str1 > str2, zero if equal
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * _strlen - returns the length of a string
 * @str: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (*str++)
		i++;
	return (i);
}

/**
 * start_str - checks if str1 starts with str2
 * @str1: string to search
 * @str2: the substring to find
 *
 * Return: address of next char of str1 or NULL
 */
char *start_str(const char *str1, const char *str2)
{
	while (*str2)
		if (*str2++ != *str1++)
			return (NULL);
	return ((char *)str1);
}

/**
 * _strcat - concatenates two strings
 * @str1: the str1ination buffer
 * @str2: the source buffer
 *
 * Return: pointer to str1ination buffer
 */
char *_strcat(char *str1, char *str2)
{
	char *ret = str1;

	while (*str1)
		str1++;
	while (*str2)
		*str1++ = *str2++;
	*str1 = *str2;
	return (ret);
}

