/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:43:23 by jbrown            #+#    #+#             */
/*   Updated: 2018/02/24 13:58:46 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char const	*s_end;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (!*s)
		return (ft_strnew(0));
	s_end = s + (unsigned int)ft_strlen(s) - 1;
	while (*s_end == ' ' || *s_end == '\n' || *s_end == '\t')
		s_end--;
	return (ft_strsub(s, 0, (size_t)(s_end - s + 1)));
}
