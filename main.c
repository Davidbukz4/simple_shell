#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * main - a simple shell program
 * Return: 1 or 0;
 */

int main(void)
{
	char *buf = NULL;
	char **argv;
	size_t x = 0, n = 8;
	pid_t child_pid;
	int status;

	while (1)
	{
		_putchar('$');
		_putchar(' ');
		_putchar(-1);

		x = getline(&buf, &n, stdin);
		if ((buf)[x - 1] == '\n')
			(buf)[x - 1] = '\0';
		argv = _strtow(buf);

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
