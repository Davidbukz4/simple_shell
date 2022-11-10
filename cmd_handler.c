#include "main.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

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

int exe_cmd(char *buf, char **env)
{
	char **argv;
	int ret;

	argv = _strtow(buf, ' ');

	ret = gbin_func(argv, env);
	if (ret == 0)
		return (0);
	full_path(argv, env);
	ret = exe_syscmd(argv);
	return (ret);
}

void cmd_sep(char *buf, char **env)
{
	char **cmds;
	int i = 0;

	cmds = _strtow(buf, ';');
	while (cmds[i])
	{
		exe_cmd(cmds[i], env);
		i++;
	}
}
