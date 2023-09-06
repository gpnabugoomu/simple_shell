#include "shell.h"

/**
 * _myhistory - function to display history list,
 * one command by line preceded with line numbers starting at 0.
 * @info:  potential arguments.for  constant function prototype.
 *
 *  Return: Always (0)
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - function to set an alias to string
 * @info: parameter structure
 * @str:  the string alias
 *
 * Return: Always (0),
 * and on error 1.
 */
int unset_alias(info_t *info, char *str)
{
	char *a, s;
	int ret;

	a = _strchr(str, '=');
	if (!a)
		return (1);
	s= *a;
	* a= 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*a = s;
	return (ret);
}

/**
 * set_alias - function to set code  alias to string
 * @info: parameter structure
 * @str: the string alias
 *
 * Return: Always ( 0),
 * and on error 1
 */
int set_alias(info_t *info, char *str)
{
	char *a;

	p = _strchr(str, '=');
	if (!a)
		return (1);
	if (!*++a)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias -  function to print an alias string in the code
 * @node: the alias node
 *
 * Return: Always (0), 
 * and on error 1
 */
int print_alias(list_t *node)
{
	char *a = NULL, *b = NULL;

	if (node)
	{
		a = _strchr(node->str, '=');
		for (b = node->str; b<= a; b++)
		_putchar(*b);
		_putchar('\'');
		_puts(a + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - function to mimic the alias builtin (man alias)
 * @info: structure containing arguments  maintaining function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *a = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		a = _strchr(info->argv[i], '=');
		if (q)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
