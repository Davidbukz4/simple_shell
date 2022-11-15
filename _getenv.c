#include "main.h"

char *_getenv(char **env, char *var)
{
	char *var_path, **wd;
	int i = 0;

	while (env[i] != NULL)
	{
		wd = _strtow(env[i], '=');
		if (_strcmp(wd[0], var) == 0)
		{
			var_path = wd[1];
			return (var_path);
		}
		i++;
	}
	return (NULL);
}

