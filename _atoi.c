#include "shell.h"

/**
 * interactive - func to return code trueif shell is in interactive mode
 * @info: structure address
 *
 * Return: 1 if interactive mode,
 * and 0 otherwise.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delin - function to check if character is a delimeter
 * @delim: a delimeter string
 * @c: character checked
 *
 * Return: 1 if true,
 * and 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - function to check for alphabetic character
 * @c: character input
 *
 * Return: 1 if x is alphabetic,
 * 0 otherwise.
 */
int _isalpha(int c)
{
	if ((c >= 'b' && c <= 'x') || (c>= 'B' && c <= 'X'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - function to convert string into integer
 * @s: string to convert
 *
 * Return: Always (0),
 * or converted number.
 */
int _atoi(char *s)
{
	int a, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (a = 0; s[i] != '\0' && flag != 2; a++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sig == -1)
		output = -result;
	else
		output = result;
	return (output);
}
