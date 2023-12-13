#include "shell.h"

/**
 * **strsplit2 - splits a string into words
 * @inputstr: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, else NULL
 */
char **strsplit2(char *inputstr, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (inputstr == NULL || inputstr[0] == 0)
		return (NULL);
	for (i = 0; inputstr[i] != '\0'; i++)
		if ((inputstr[i] != d && inputstr[i + 1] == d) ||
		    (inputstr[i] != d && !inputstr[i + 1]) || inputstr[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (inputstr[i] == d && inputstr[i] != d)
			i++;
		k = 0;
		while (inputstr[i + k] != d && inputstr[i + k] && inputstr[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = inputstr[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strsplit - splits a string into words. Repeat delimiters are ignored
 * @inputstr: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, else NULL
 */

char **strsplit(char *inputstr, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (inputstr == NULL || inputstr[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; inputstr[i] != '\0'; i++)
		if (!is_delimeter(inputstr[i], d)
			&& (is_delimeter(inputstr[i + 1], d) || !inputstr[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delimeter(inputstr[i], d))
			i++;
		k = 0;
		while (!is_delimeter(inputstr[i + k], d) && inputstr[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = inputstr[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

