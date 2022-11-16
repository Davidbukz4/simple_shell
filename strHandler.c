#include "main.h"

char **_strtow(char *str, char delim)
{
	char *w;
	char **s;
	int i = 0, j = 0, k, words = 0, len = 0;

	if (str == NULL || *str == '\0')
		return (NULL);
	while (str[i])
	{
		if (str[i] == delim && str[i - 1] && str[i - 1] != delim)
			words++;
		i++;
	}
	if (str[i] == '\0' && str[i - 1] && str[i - 1] != delim)
		words++;
	if (words == 0)
		return (NULL);
	s = (char **) malloc(sizeof(char *) *  (words + 1));
	if (s == NULL)
		return (NULL);
	words = 0, len = i;
	for (i = 0; i <= len; i++)
	{
		if ((str[i] == delim && str[i - 1] && str[i - 1] != delim)
			|| (str[i] == '\0' && str[i - 1] && str[i - 1] != delim))
		{
			w = (char *) malloc(sizeof(char) * (j + 1));
			if (w == NULL)
				return (NULL);
			s[words] = w;
			words++;
			for (k = 0; k < j; k++)
				w[k] = str[i -  j + k];
			w[k] = '\0';
			j = 0;
		}
		else if (str[i] != delim)
			j++;
	}
	s[words] = NULL;
	return (s);
}
