#include "shell.h"

/**
 * _altenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _altenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _altgetenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_altgetenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = start_str(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _altunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _altunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputinputstr("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_funsetenv(info, info->argv[i]);

	return (0);
}

/**
 * _altsetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _altsetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputinputstr("Incorrect number of arguements\n");
		return (1);
	}
	if (_fsetenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * pop_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int pop_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

