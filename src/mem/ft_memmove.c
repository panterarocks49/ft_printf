/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 19:36:16 by jbrown            #+#    #+#             */
/*   Updated: 2018/02/20 21:25:28 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*src;

	dst = (unsigned char *)d;
	src = (const unsigned char *)s;
	if (dst < src)
		ft_memcpy(dst, src, n);
	else
	{
		dst = dst + n - 1;
		src = src + n - 1;
		while (n--)
			*dst-- = *src--;
	}
	return (d);
}
