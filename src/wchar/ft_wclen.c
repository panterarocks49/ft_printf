/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wclen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:51:53 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/27 20:51:55 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wclen(wint_t wt)
{
	if (wt <= 0x007F)
		return (1);
	else if (wt <= 0x07FF)
		return (2);
	else if (wt <= 0xFFFF)
		return (3);
	else if (wt <= 0x10FFFF)
		return (4);
	return (0);
}
