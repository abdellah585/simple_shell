#include "shell.h"

/**
 **_strncat - concatenates two strings
 *@str1: the first string
 *@str2: the second string
 *@n: the amount of bytes to be used at most
 *Return: the concatenated string
 */
char *_strncat(char *str1, char *str2, int n)
{
	int i, j;
	char *s = str1;

	i = 0;
	j = 0;
	while (str1[i] != '\0')
		i++;
	while (str2[j] != '\0' && j < n)
	{
		str1[i] = str2[j];
		i++;
		j++;
	}
	if (j < n)
		str1[i] = '\0';
	return (s);
}

/**
 **_strncpy - copies a string
 *@str1: the string to be copied to
 *@str2: the source string
 *@n: the amount of chars to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *str1, char *str2, int n)
{
	int i, j;
	char *s = str1;

	i = 0;
	while (str2[i] != '\0' && i < n - 1)
	{
		str1[i] = str2[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			str1[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@str: the string to be parsed
 *@c: the char to look for
 *Return: (str) a pointer to the memory area str
 */
char *_strchr(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}

