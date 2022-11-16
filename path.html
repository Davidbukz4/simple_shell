#include "main.h"
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>

/**
 * _strlen - counts length of string
 * @str: pointer to string
 * Return: length of string
 */
int _strlen(char *str)
{
	int x;

	for (x = 0; str[x]; x++)
		;
	return (x);
}

/**
 * _strncpy - copies n bytes of string to a destination
 * @dest: destination memory to copy string to
 * @src: source string
 * @n: number of bytes
 * Return: pointer to destination string
 */
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

/**
 * _strcat - concatenates source string to destination string
 * @dest: destination string
 * @src: source string
 * Return: pointer to destination string
 */
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

/**
 * full_path - get full path of a command
 * @argv: command
 * @env: env
 * Return: void
 */
void full_path(char **argv, char **env)
{
	int i = 0;
	char *path;

	while (env[i] != NULL)
	{
		path = ch_path(argv[0], env[i]);
		if (path)
			break;
		i++;
	}
	if (path)
	argv[0] = path;
}

/**
 * ch_path - checks path variable
 * @cmd: command argument
 * @path: environment variable
 * Return: full path to command argument
 */
char *ch_path(char *cmd, char *path)
{
	char **wd;
	char *full_path, *comp, *f_sl = "/";
	int wd_len, cmd_len, total_len, i = 0;
	struct stat sb;

	wd = _strtow(path, '=');
	wd = _strtow(wd[1], ':');

	cmd_len = _strlen(cmd);
	while (wd[i])
	{
		wd_len = _strlen(wd[i]);
		total_len = wd_len + cmd_len;
		full_path = malloc(sizeof(char) * total_len + 2);
		if (!full_path)
			return (NULL);

		_strncpy(full_path, wd[i], wd_len);
		_strcat(full_path, f_sl);
		comp = _strcat(full_path, cmd);
		if (stat(comp, &sb) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}
