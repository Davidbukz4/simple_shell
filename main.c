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
	char **argv;
	size_t x = 0, n = 8;
	pid_t child_pid;
	int status, i;
	struct stat sb;
	char *path;

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
		argv = _strtow(buf, ' ');

		if (strcmp(argv[0], "exit") == 0)
			gbin_func(argv[0]);

		i = 0;
		while (env[i] != NULL)
		{
			path = ch_path(argv[0], env[i]);
			if (path)
				break;
			i++;
		}
		if (path)
			argv[0] = path;
		if (stat(argv[0], &sb) == 0)
		{
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
					printf("ok\n");
					perror("Error");
				}
			}
			else
			{
				wait(&status);
			}
		}
		else
		{
			perror("Error");
		}

	}
	return (0);
}
