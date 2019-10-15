/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:32:59 by bminner           #+#    #+#             */
/*   Updated: 2019/10/14 16:33:00 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void			ft_len(int n, size_t *len, int *s)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*s = 1;
	while (-9 > n / *s)
	{
		*s *= 10;
		*len += 1;
	}
}

char				*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	char	*dest;
	int		s;

	ft_len(n, &len, &s);
	if ((dest = (char*)malloc(sizeof(*dest) * (len + 1))))
	{
		i = 0;
		if (n < 0)
		{
			dest[i] = '-';
			i++;
		}
		if (n > 0)
			n = -n;
		while (s >= 1)
		{
			dest[i++] = -(n / s % 10) + 48;
			s /= 10;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (0);
}
