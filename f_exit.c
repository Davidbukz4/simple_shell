#include "main.h"

int f_exit(char **arg)
{
	int i = 0;

	while (arg[i])
	{
		if (arg[0] && !arg[1])
			exit(0);
		i++;
	}
	return (0);
}

