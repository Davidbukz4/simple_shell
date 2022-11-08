#include "main.h"

int f_printenv(char **arg, char **env)
{
	int i;

	if (arg[0])
	{
		for (i = 0; env[i]; i++)
		{
			printf("%s\n", env[i]);
		}
		return (0);
	}
	return (0);
}
