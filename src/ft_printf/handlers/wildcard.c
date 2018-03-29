/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:10:20 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/28 19:10:24 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_max_wld(t_env *env, t_param *param)
{
	if ((param->flags & MAX_WIDTH_WLD) == MAX_WIDTH_WLD)
		param->max_width = va_arg(*env->args, int);
}

void	handle_min_wld(t_env *env, t_param *param)
{
	int min_width;

	if ((param->flags & MIN_WIDTH_WLD) == MIN_WIDTH_WLD)
	{
		min_width = va_arg(*env->args, int);
		param->min_width = FT_ABS(min_width);
		if (min_width < 0)
			param->flags = param->flags | FLAG_LEFT;
	}
}
