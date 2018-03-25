/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:58:37 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/24 14:58:39 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_perc(t_env *env, t_param *param)
{
	int	i;

	i = 0;
	if ((param->flags & FLAG_LEFT) != FLAG_LEFT)
		while (i++ < param->min_width - 1)
			cpy_char(env, ' ');
	cpy_char(env, '%');
	if ((param->flags & FLAG_LEFT) == FLAG_LEFT)
		while (i++ < param->min_width - 1)
			cpy_char(env, ' ');
}
