#include "main.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

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
	struct stat sb;

	while (1)
	{
		_putchar('$');
		_putchar(' ');
		_putchar(-1);

		x = getline(&buf, &n, stdin);
		if ((buf)[x - 1] == '\n')
			(buf)[x - 1] = '\0';
		argv = _strtow(buf);

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
			printf("not working\n");
			perror("Error");
		}

	}
	return (0);
}
