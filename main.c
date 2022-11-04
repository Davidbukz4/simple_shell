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
	char *argv[2];
	size_t x = 0, n = 8;

	while (1)
	{
		_putchar('$');
		_putchar(' ');
		_putchar(-1);

		x = getline(&buf, &n, stdin);
		if ((buf)[x - 1] == '\n')
			(buf)[x - 1] = '\0';
		argv[0] = strtok(buf, " ");
		argv[1] = NULL;
		printf("You entered: %s and %s", argv[0], argv[1]);
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
	return (0);
}
