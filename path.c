#include "shell.h"

/**
 * dup_characters - duplicates characters
 * @pathstr: the PATH string
 * @i1: starting index
 * @i2: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_characters(char *pathstr, int i1, int i2)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = i1; i < i2; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * is_cmd - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, else 0
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmdf: the cmd to find
 *
 * Return: full path of cmd if found else NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmdf)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmdf) > 2) && start_str(cmdf, "./"))
	{
		if (is_cmd(info, cmdf))
			return (cmdf);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_characters(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmdf);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmdf);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

