#include "main.h"


int gbin_func(char **arg, char **env)
{
	int j, cont;
	builtin_cmd b_cmd[] = {
		{"exit", f_exit},
		{"env", f_printenv},
		{NULL, NULL}
	};

	for (j = 0; b_cmd[j].cmd != NULL; j++)
	{
		if (_strcmp(arg[0], b_cmd[j].cmd) == 0)
		{
			cont = b_cmd[j].func(arg, env);
			if (cont == 0)
				return (0);
		}
	}
	return (-1);
}
