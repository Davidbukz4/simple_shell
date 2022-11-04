#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int _putchar(char c);
char **_strtow(char *str);
int _strlen(char *str);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *ch_path(char *cmd, char *path);

#endif /* MAIN_H */
