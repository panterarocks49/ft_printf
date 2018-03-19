/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:33:48 by jbrown            #+#    #+#             */
/*   Updated: 2018/02/23 14:25:54 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_places(int n)
{
	int places;

	places = 0;
	if (n <= 0)
		places++;
	while (n != 0)
	{
		n = n / 10;
		places++;
	}
	return (places);
}

char		*ft_itoa(int n)
{
	char	*result;
	int		places;
	int		mod;
	int		i;

	places = count_places(n);
	if (!(result = ft_strnew(places)))
		return (NULL);
	if (n == 0)
		result[0] = '0';
	else if (n < 0)
		result[0] = '-';
	i = 0;
	while (n != 0)
	{
		mod = n % 10;
		n = n / 10;
		if (FT_ABS(mod) >= 10)
			result[places - 1 - i++] = (FT_ABS(mod) - 10 + 'A');
		else
			result[places - 1 - i++] = (FT_ABS(mod) + '0');
	}
	return (result);
}
