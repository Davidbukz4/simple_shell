#include "main.h"

int f_exit(char **arg)
{

	if (arg[0])
		exit(0);
	return (-1);
}

