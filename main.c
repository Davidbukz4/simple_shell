#include "main.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

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
 * exe_syscmd - execute a system command
 * @argv: command
 * Return: int
 */

int exe_syscmd(char **argv)
{
	pid_t child_pid;
	int status;
	struct stat sb;

	if (stat(argv[0], &sb) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (-1);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error");
				return (-1);
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
		return (-1);
	}
	return (0);
}

/**
 * main - a simple shell program
 * Return: 1 or 0;
 */

int main(int ac, char **av, char **env)
{
	char *buf = NULL;
	char **argv;
	size_t x = 0, n = 8;
	int cont;

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

		cont = gbin_func(argv, env);
		if (cont == 0)
			continue;
		full_path(argv, env);
		exe_syscmd(argv);
	}
	return (0);
}
