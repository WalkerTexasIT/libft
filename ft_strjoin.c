#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		n;
	int		i;

	if (ft_strlen(s1) >= 0 && ft_strlen(s2) >= 0)
		dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	else
		return (0);
	n = 0;
	i = 0;
	while (s1[n] != '\0')
	{
		dest[n] = s1[n];
		n++;
	}
	while (s2[i] != '\0')
	{
		dest[n + i] = s2[i];
		i++;
	}
	dest[n + i] = '\0';
	return (dest);
}
