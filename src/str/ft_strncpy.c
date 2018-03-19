/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 22:31:17 by jbrown            #+#    #+#             */
/*   Updated: 2018/02/20 22:43:45 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char *d;

	d = dest;
	while (len > 0 && *src)
	{
		*d++ = *src++;
		--len;
	}
	while (len > 0)
	{
		*d++ = '\0';
		--len;
	}
	return (dest);
}
