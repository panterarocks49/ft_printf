/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 17:53:57 by jbrown            #+#    #+#             */
/*   Updated: 2018/02/20 21:33:34 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *d, int c, size_t n)
{
	unsigned char	*dst;

	dst = (unsigned char *)d;
	while (n--)
		*dst++ = (unsigned char)c;
	return (d);
}
