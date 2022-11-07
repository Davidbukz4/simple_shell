#include "main.h"


void gbin_func(char *arg)
{
	int j;
	builtin_cmd b_cmd[] = {{"exit", f_exit}, 
		{NULL, NULL}
	};

	for (j = 0; b_cmd[j].cmd != NULL; j++)
	{
		if (strcmp(arg, b_cmd[j].cmd) == 0)
		{
			b_cmd[j].func();
		}
	}
}
