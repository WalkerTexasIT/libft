/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:01:48 by bminner           #+#    #+#             */
/*   Updated: 2019/10/08 14:01:50 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	int		i;
	char	*dest;

	x = 0;
	dest = 0;
	if (needle[x] == '\0')
		return ((char *)haystack);
	while (haystack[x] != '\0' && x < len)
	{
		if (haystack[x] == needle[0])
		{
			dest = (char *)haystack + x;
			i = 0;
			while (haystack[x + i] == needle[i] && x + i < len)
			{
				if (needle[i + 1] == '\0')
					return (dest);
				i++;
			}
			dest = 0;
		}
		x++;
	}
	return (0);
}
