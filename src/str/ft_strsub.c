/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:00:17 by jbrown            #+#    #+#             */
/*   Updated: 2018/02/21 22:30:00 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	str = ft_strnew(len);
	i = 0;
	while (s && str && *(s + start + i) && i < len)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	if (str)
		*(str + i) = '\0';
	return (str);
}
