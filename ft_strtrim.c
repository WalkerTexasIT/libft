/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:49:57 by bminner           #+#    #+#             */
/*   Updated: 2019/10/14 10:50:00 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

size_t		ft_strlen(const char *src)
{
	int n;

	n = 0;
	while (src[n] != '\0')
		n++;
	return (n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	x;
	int				n;

	n = 0;
	x = ft_strlen(s) - start;
	if (len < x)
		dest = malloc(x);
	else if (len > x)
		dest = malloc(len);
	else
		return (0);
	while (s[start] != '\0' && len > (unsigned long)n)
	{
		dest[n] = s[start];
		n++;
		start++;
	}
	return (dest);
}

size_t		fin(char const *s1, char const *set)
{
	size_t		n;
	int			j;

	n = ft_strlen(s1) - 1;
	while (n > 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[n] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			return (n);
		n--;
	}
	return (0);
}

size_t		debut(char const *s1, char const *set)
{
	size_t		n;
	int			j;

	n = 0;
	while (s1[n] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[n] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			return (n);
		n++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char		*dest;
	size_t		i;

	i = ft_strlen(s1) - 1 - debut(s1, set) - fin(s1, set);
	dest = ft_substr(s1, (unsigned int)debut(s1, set), i);

	return (dest);
}

int			main(void)
{
	char s1[] = "  \n  \t  lorem \n ipsum \t dolor \n sit \t amet  \t \n ";
	char set[] = " \n\t";

	printf("test");
	fflush(stdout);
	printf("%s", ft_strtrim(s1, set));
	return (0);
}