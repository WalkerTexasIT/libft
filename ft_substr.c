/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:51:39 by bminner           #+#    #+#             */
/*   Updated: 2019/10/11 15:51:40 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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
