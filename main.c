#include "main.h"

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
	char **argv = NULL;
	size_t x = 0, n = 8;
	int status;
	pid_t child_pid;

	(void)env, (void)av;
	if (ac < 1)
		return (-1);
	while (1)
	{
		_putchar('$');
		_putchar(' ');
		_putchar(-1);
		x = getline(&buf, &n, stdin);
		if ((int) x == -1)
			break;
		if ((buf)[x - 1] == '\n')
			(buf)[x - 1] = '\0';
		argv = _strtow(buf, ' ');
		if (argv == NULL || *argv == NULL || **argv == '\0')
			continue;
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(av[0]);
			return (-1);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				perror(av[0]);
		}
		else
			wait(&status);
		free(argv);
	}
	free(buf);
	return (0);
}
