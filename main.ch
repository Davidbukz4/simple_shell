#include "main.h"

/**
 * execution - executes commands entered by users
 *@cp: command
 *@cmd:vector array of pointers to commands
 * Return: 0
 */

void execution(char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;
	int i;

	child_pid = fork();
	if (child_pid < 0)
		perror(cmd[0]);
	if (child_pid == 0)
	{
		execve(cmd[0], cmd, env);
		perror(cmd[0]);
		for (i = 0; cmd[i]; i++)
			free(cmd[i]);
		free(cmd);
		exit(98);
	}
	else
		wait(&status);
}

/**
 * main - carries out the read, execute then print output loop
 * @ac: argument count
 * @av: argument vector
 * @envp: environment vector
 *
 * Return: 0
 */

int main(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **command = NULL;
	int i;

	while (1)
	{
		prompt();
		linesize = getline(&line, &bufsize, stdin);
		if (linesize < 0)
			break;
		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		command = _strtow(line, ' ');
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		execution(command);
		for (i = 0; command[i]; i++)
			free(command[i]);
		free(command);
		free(line);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	return (0);
}
