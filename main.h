#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>

extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

struct flags
{
	bool interactive;
} flags;

void prompt(void);
char **_strtow(char *str, char delim);

#endif /* MAIN_H */
