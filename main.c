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
	size_t n = 0;

	while (1)
	{
		_putchar('$');
		_putchar(' ');
		_putchar(-1);

		getline(&buf, &n, stdin);
		argv = strtow(buf);
		printf("You entered: %s and %s", argv[0], argv[1]);
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
	return (0);
}
