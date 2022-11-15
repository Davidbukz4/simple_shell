#include "main.h"

int f_chdir(char **arg, char **env)
{
	char **wd;
	char *path, *f_sl = "/", cwd[PATH_MAX];
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
	_strcat(path, f_sl);
	if (arg[0] && arg[1])
	{
		path = getcwd(cwd, PATH_MAX);
		_strcat(path, f_sl);
		_strcat(path, arg[1]);
		if (chdir(path) == 0)
			return (0);
		else
		{
			perror(path);
			return (0);
		}
	}
	if (chdir(path) == 0)
		return (0);

	return (-1);
}
