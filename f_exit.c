#include "main.h"

/**
 * f_exit - function to handle exit command, and with exit status
 * @arg: command argument
 * Return: -1 for unsuccessful execution
 */

int f_exit(char **arg)
{
	int i, num_str;

	num_str = 0;
	if (arg[0] && arg[1])
	{
		for (i = 0; arg[1][i]; i++)
		{
			if (arg[1][i] < '0' || arg[1][i] > '9')
				exit(num_str);
		}
		num_str = _atoi(arg[1]);
		exit(num_str);
	}
	if (arg[0])
		exit(0);
	return (-1);
}

