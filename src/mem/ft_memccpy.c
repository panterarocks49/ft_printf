/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 19:00:22 by jbrown            #+#    #+#             */
/*   Updated: 2018/02/20 21:17:43 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*src;
	unsigned char		ch;

	dst = (unsigned char *)d;
	src = (const unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		*dst++ = *src;
		if (*src++ == ch)
			return ((void *)dst);
	}
	return (NULL);
}
