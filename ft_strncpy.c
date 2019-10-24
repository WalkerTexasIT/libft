#include "libft.h"

char	*ft_strncpy(char *dest, const char *s, size_t n)
{
	size_t i;

	i = 0;
	while (s[i] != 0 && i < n)
	{
		dest[i] = s[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}