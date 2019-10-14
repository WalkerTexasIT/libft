/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bminner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:37:15 by bminner           #+#    #+#             */
/*   Updated: 2019/10/11 13:37:17 by bminner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*dest;
	size_t	x;

	x = 0;
	if (nitems == 0 || size == 0)
		return (0);
	dest = malloc(size * nitems);
	while (x <= nitems)
	{
		((char *)dest)[x] = 0;
		x++;
	}
	return (dest);
}
