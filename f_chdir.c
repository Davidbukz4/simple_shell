#include "main.h"

int f_chdir(char **arg, char **env)
{
	char **wd;
	char *path, *f_sl = "/";
	int i = 0;

	while (env[i] != NULL)
	{
		wd = _strtow(env[i], '=');
		if (_strcmp(wd[0], "HOME") == 0)
		{
			path = wd[1];
			break;
		}
		i++;
	}

}
