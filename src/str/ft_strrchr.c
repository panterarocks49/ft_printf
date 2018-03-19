/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 22:49:18 by jbrown            #+#    #+#             */
/*   Updated: 2018/02/20 23:08:33 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last_match;

	last_match = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_match = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (last_match);
}
