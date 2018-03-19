/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:55:53 by jbrown            #+#    #+#             */
/*   Updated: 2018/02/24 15:19:36 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**dest;
	char	*word_ptr;
	int		i;

	if (!s)
		return (NULL);
	if (!(dest = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!(dest[i] = ft_strnew(ft_wordlen(s, c))))
				return (ft_tabledel(dest, i));
			word_ptr = dest[i++];
			while (*s != c && *s)
				*word_ptr++ = *s++;
		}
		else
			s++;
	}
	dest[i] = NULL;
	return (dest);
}
