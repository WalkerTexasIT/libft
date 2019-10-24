#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static int			count(char const *s, char c)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue;
		}
		n++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
}

static char			**unmall(char **dest, int i)
{
	while (i >= 0)
	{
		ft_bzero((void*)dest[i], ft_strlen(dest[i]));
		free(dest[i]);
		i--;
	}
	free(dest);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		n;
	char		**dest;

	i = 0;
	if (s == 0)
		return (0);
	if (!(dest = (char**)malloc(sizeof(char*) * (count(s, c) + 1))))
		return (0);
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue;
		}
		n = 0;
		while (s[n] && s[n] != c)
			n++;
		if ((dest[i++] = ft_strndup(s, n)) == NULL)
			return (unmall(dest, i));
		s += n;
	}
	dest[i] = 0;
	return (dest);
}