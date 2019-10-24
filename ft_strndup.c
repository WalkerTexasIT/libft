#include "libft.h"
#include <stdlib.h>

char		*ft_strndup(const char *s, size_t n)
{
	char		*dest;

	if (!(dest = malloc(sizeof(char) * (n + 1))))
		return (0);
	dest = ft_strncpy(dest, s, n);
	dest[n] = 0;
	return (&*dest);
}
