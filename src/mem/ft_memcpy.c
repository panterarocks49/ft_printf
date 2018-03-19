/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:15:15 by jbrown            #+#    #+#             */
/*   Updated: 2018/02/20 21:18:38 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*src;

	dst = (unsigned char *)d;
	src = (const unsigned char *)s;
	while (n--)
		*dst++ = *src++;
	return (d);
}
