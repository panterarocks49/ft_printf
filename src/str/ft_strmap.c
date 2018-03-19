/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:05:07 by jbrown            #+#    #+#             */
/*   Updated: 2018/02/24 13:57:08 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (NULL);
	str = ft_strnew(ft_strlen(s));
	i = 0;
	if (str && f)
	{
		while (*(s + i))
		{
			*(str + i) = f(*(s + i));
			i++;
		}
	}
	return (str);
}
