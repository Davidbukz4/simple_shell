#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t _getline(char **buffer, size_t *size)
{
	size_t cnt = 0;
	char *c, *tmp;
	int i, rd, ch = 120, st = 120;

	if (buffer == NULL)
		return (-1);
	
	c = malloc(sizeof(char) * ch);

	rd = read(STDIN_FILENO, c, ch);
	while (rd == ch)
	{
		tmp = c;
		ch = ch + st;
		c = malloc(sizeof(char) * ch);
		for (i = 0; i < rd; i++)
			c[i] = tmp[i];
		free(tmp);
		rd += read(STDIN_FILENO, (c + rd), st);
	}
	if(rd != 0)
	{
		if (rd > (int) *size || *buffer == NULL)
		{
			*buffer = malloc(sizeof(char) * rd);
			*size = ch;
		}
		for (i = 0; i < rd; i++)
		{
			if(c[i] == '\n' || !c[i])
			{
				(*buffer)[cnt] = 0;
				return (cnt);
			}
	        	(*buffer)[cnt++] = c[i];
		}
	}
        (*buffer[cnt]) = 0;
	return (cnt);
}
