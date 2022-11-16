#include "main.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

/**
 * main - a simple shell program
 * @ac: argument count
 * @av: array of command line argument
 * @env: environment variable
 * Return: 1 or 0;
 */

int main(int ac, char **av, char **env)
{
	char *buf = NULL;
	size_t x = 0, n = 8;

	if (ac >= 2)
	{
		if (execve(av[1], av, env) == -1)
		{
			perror("Error:");
			exit(-1);
		}
		return (0);
	}

	while (1)
	{
		_putchar('$');
		_putchar(' ');
		_putchar(-1);

		x = getline(&buf, &n, stdin);
		if ((int) x == -1)
			exit(0);
		if ((buf)[x - 1] == '\n')
			(buf)[x - 1] = '\0';
		if (buf[0] == '\0')
			continue;
		cmd_sep(buf, env);
	}
	return (0);
}
