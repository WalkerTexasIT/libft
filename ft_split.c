#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int		pos_word(char *s, char c, unsigned int order)
{
	int				is_word;
	unsigned int	n;
	unsigned int	pos;

	is_word = 0;
	n = 0;
	pos = 0;
	while (s[pos] != '\0')
	{
		if (is_word == 0 && s[pos] != c)
		{
			n++;
			if (n == order + 1)
				break ;
			is_word = 1;
		}
		else if (is_word == 1 && s[pos] == c)
			is_word = 0;
		pos++;
	}
	return (pos);
}

static int		count_words(char *s, char c)
{
	int				i;
	unsigned int	n;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			n++;
		i++;
	}
	return (n);
}

static char		*assign_word(char *s, char c)
{
	unsigned int	i;
	unsigned int	len;
	char			*dest;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	dest = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
		dest[i++] = *s++;
	dest[i] = '\0';
	return (dest);
}

char			**ft_split(char const *s, char c)
{
	unsigned int	n;
	unsigned int	i;
	char			**dest;
	char			*ptr;

	if (!s)
		return (0);
	ptr = (char*)s;
	n = count_words(ptr, c);
	if (!(dest = (char**)malloc(sizeof(char*) * (n + 1))))
		return (0);
	i = 0;
	while (i < n)
	{
		dest[i] = assign_word(ptr + pos_word(ptr, c, i), c);
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/*int		main(void)
{
	char **dest;
	int n;

	n = 0;
	dest = ft_split("salut suit sur su", 's');
	while (dest[n][0] != 0)
	{
		printf("%s\n", dest[n]);
		n++;
	}
	return (0);
}*/