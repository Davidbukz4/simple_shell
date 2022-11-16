#include "main.h"

/**
 * execution - executes commands entered by users
 *@cp: command
 *@cmd:vector array of pointers to commands
 * Return: 0
 */

void execution(char *cp, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cp);
	if (child_pid == 0)
	{
		execve(cmd[0], cmd, env);
		perror(cp);
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

int main(int ac, char **av, char *envp[])
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **command = NULL;
	(void)envp, (void)av;
	if (ac < 1)
		return (-1);
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
		execution(av[0], command);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
