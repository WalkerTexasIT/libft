#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void			unmall(char **dest, int line)
{
	while (line >= 0)
	{
		free(dest[line]);
		line--;
	}
	free(dest);
}

char	*ft_mall(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	int				n;

	n = 0;
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s[start] != '\0' && len > (unsigned long)n)
	{
		dest[n] = s[start];
		n++;
		start++;
	}
	dest[n] = '\0';
	return (dest);
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

int				linelong(char const *s, char c, int h)
{
	int n;

	n = 0;
	if (s[h] == c)
		return (0);
	while (s[h] != '\0' && s[h] != c)
	{
		printf("%d, %d\n", n, h);
		n++;
		h++;
	}
	return (n);
}

char			**ft_split(char const *s, char c)
{
	char	**dest;
	int		line;
	int		h;
	int		i;

	if (!(dest = (char**)malloc(sizeof(char*) * (count(s, c) + 1))))
		return (0);
	line = 0;
	h = 0;
	while (s[h] != '\0')
	{
		i = linelong(s, c, h);
		if (i > 0)
		{
			if (ft_mall(s, (unsigned int)h, (size_t)i))
			{
				unmall(dest, line);
				return (0);
			}
			dest[line] = ft_mall(s, (unsigned int)h, (size_t)i);
		}
		h = h + i + 1;
		dest[line] = 0;
	}
	return (dest);
}

/*int				main(void)
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
}*/
