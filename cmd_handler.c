#include "main.h"

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
			perror(argv[0]);
			return (-1);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror(argv[0]);
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
		perror(argv[0]);
		return (-1);
	}
	return (0);
}

/**
 * exe_cmd - function to execute command
 * @buf: buffer
 * @env: environment variable
 * Return: 0 if successful, -1 otherwise
 */
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

/**
 * or_sep - | separator
 * @buf: buffer
 * @env: environment variables
 * Return: 0 for successful execution, -1 otherwise
 */
int or_sep(char *buf, char **env)
{
	char **cmds;
	int i = 0, cnt = -1;

	cmds = _strtow(buf, '|');
	while (cnt != 0 && cmds[i])
	{
		cnt = exe_cmd(cmds[i], env);
		i++;
	}
	return (cnt);
}

/**
 * and_sep - & separator
 * @buf: buffer
 * @env: environment variable
 * Return: 0 for succesful execution, -1 otherwise
 */
int and_sep(char *buf, char **env)
{
	char **cmds;
	int i = 0, cnt = 0;

	cmds = _strtow(buf, '&');
	while (cnt == 0 && cmds[i])
	{
		cnt = or_sep(cmds[i], env);
		i++;
	}
	return (cnt);
}

/**
 * cmd_sep - command separator using semicolon
 * @buf: buffer
 * @env: environment variable
 * Return: 0 for successful execution, -1 otherwise
 */
void cmd_sep(char *buf, char **env)
{
	char **cmds;
	int i = 0;

	if (buf[0] == '#')
		return;
	cmds = _strtow(buf, '#');
	cmds = _strtow(cmds[0], ';');
	while (cmds[i])
	{
		and_sep(cmds[i], env);
		i++;
	}
}
