#include "main.h"

/**
 * f_chdir - function to change directory
 * @arg: command argument
 * @env: environment variables
 * Return: 0 to display command prompt whether successful execution or not
 */

int f_chdir(char **arg, char **env)
{
	char *path, *f_sl = "/", cwd[PATH_MAX];

	path = _getenv(env, "HOME");
	_strcat(path, f_sl);
	if (arg[0] && arg[1])
	{
		if (arg[1][0] == '~' && !arg[1][1])
			;
		else if (arg[1][0] == '-' && !arg[1][1])
		{
			path = _getenv(env, "OLDPWD");
		}
		else
		{
			path = getcwd(cwd, PATH_MAX);
			_strcat(path, f_sl);
			_strcat(path, arg[1]);
		}
	}
	if (access(path, F_OK | R_OK) == 0)
	{
		if (chdir(path) == 0)
			return (0);
		perror(path);
		return (0);
	}
	else
	{
		printf("Na to do setenv function ohh, nawa\n");
		return (0);
	}
	return (0);
}
