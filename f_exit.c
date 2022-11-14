#include "main.h"

int f_exit(char **arg)
{
	int i, z;
	z = 0;

	if (arg[0] && arg[1])
	{
		for (i = 0; arg[1][i]; i++)
		{
			if (arg[1][i] < '0' || arg[1][i] > '9')
				exit (z);
		}
		z = _atoi(arg[1]);
		exit(z);
	}
	if (arg[0])
		exit(0);
	return (-1);
}

