#include "main.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

/**
 * main - a simple shell program
 * Return: 1 or 0;
 */

int main(int ac, char **av, char **env)
{
	char *buf = NULL;
	size_t x = 0, n = 8;

	if (ac || av)
	{
	}

	while (1)
	{
		_putchar('$');
		_putchar(' ');
		_putchar(-1);

		x = getline(&buf, &n, stdin);
		if ((buf)[x - 1] == '\n')
			(buf)[x - 1] = '\0';
		cmd_sep(buf, env);
	}
	return (0);
}
