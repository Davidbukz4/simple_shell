#include "main.h"

int _strlen(char *str)
{
	int x;

	for (x = 0; str[x]; x++)
		;
	return (x);
}

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;
	int j;

	while (src[i] != '\0')
		i++;
	for (j = 0; j < n; j++)
	{
		if (j > i)
			dest[j] = '\0';
		else
			dest[j] = src[j];
	}

	return (dest);
}

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = j = 0;
	for (i = 0; dest[i]; i++)
		;
	for (j = 0; src[j]; j++, i++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}

char *ch_path(char *cmd, char *path)
{
	char *full_path, *wd, *comp, *f_sl = "/";
	int wd_len, cmd_len;

	wd = strtok(path, "=");
	wd = strtok(NULL, ":");

	cmd_len = _strlen(cmd);
	while (wd)
	{
		wd_len = _strlen(wd);
		total_len = wd_len + cmd_len;
		full_path = malloc(sizeof(char) * total_len + 2);
		if (!full_path)
			return (NULL);

		_strncpy(full_path, wd, wd_len);
		_strcat(full_path, f_sl);
		comp = _strcat(full_path, cmd);
		if (stat(comp, &sb) == 0)
			return (full_path);
		free(full_path);
		wd =strtok(NULL, ":");
	}
	return (NULL);
}