#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

typedef struct builtin_cmd
{
	char *cmd;
	void (*func)();
} builtin_cmd;


int _putchar(char c);
char **_strtow(char *str, char delim);
int _strlen(char *str);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *ch_path(char *cmd, char *path);
void gbin_func(char *arg);
void f_exit();

#endif /* MAIN_H */
