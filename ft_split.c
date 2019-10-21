#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void			unmalloc(char **dest, char line)
{
	while (line >= 0)
	{
		free(dest[line]);
		line--;
	}
	free(dest);
}

int				count(char const *s, char c)
{
	int		n;
	int		dest;

	n = 0;
	dest = 0;
	while (*s != '\0')
	{
		if (*s != c && n == 0)
		{
			dest++;
			n = 1;
		}
		else if (n == 1 && *s == c)
			n = 0;
		s++;
	}
	return (dest);
}

int				linelong(char const *s, char c)
{
	int n;

	n = 0;
	if (*s == c)
		return (-1);
	while (*s != '\0' && *s != c)
		n++;
	return (n);
}

char			**ft_split(char const *s, char c)
{
	char	**dest;
	int		line;
	int		h;

	if (!(dest = (char**)malloc(sizeof(char*) * (count(s, c) + 1)))
		return (0);
	line = 0;
	while (*s != '\0')
	{
		h = linelong(&s, c);
		if (h >= 0)
		{
			if (!(dest[line] = (char*)malloc(sizeof(char) * (h + 1)))
				unmalloc(dest, line);
			*dest[line] = *s;
			h--;
			dest[line]++;
			s++;
		}
		//refaire a partir du while car pas assez de place
	}
	return (dest);
}

int				main(void)
{
	char	**dest;
	int		n;

	n = 0;
	dest = ft_split("salut suit sur su", 's');
	while (dest[n][0] != 0)
	{
		printf("%s\n", dest[n]);
		n++;
	}
	return (0);
}
