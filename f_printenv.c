#include "main.h"

int f_printenv(char **arg, char **env)
{
	int i, j;

	if (arg[0] && !arg[1])
	{
		for (i = 0; env[i]; i++)
		{
			for (j = 0; j <= _strlen(env[i]); j++)
			{
				_putchar(env[i][j]);
			}
			_putchar('\n');
		}
		return (0);
	}
	return (-1);
}
