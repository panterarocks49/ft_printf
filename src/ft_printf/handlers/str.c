/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:52:09 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/24 14:52:10 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	cpy_str(t_env *env, t_param *param, char *str)
{
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(str);
	if (param->max_width > -1 && param->max_width < length)
		length = param->max_width;
	if ((param->flags & FLAG_LEFT) != FLAG_LEFT)
	{
		while (i++ < param->min_width - length)
			cpy_char(env, ' ');
		i = 0;
	}
	while (i < length)
	{
		cpy_char(env, str[i++]);
	}
	if ((param->flags & FLAG_LEFT) == FLAG_LEFT)
	{
		while (i++ < param->min_width)
			cpy_char(env, ' ');
	}
}

void		handle_str(t_env *env, t_param *param)
{
	char	*str;

	if (param->conv == 'S' || (param->flags & LTH_L) == LTH_L)
		;
	else
	{
		str = va_arg(*env->args, char *);
		cpy_str(env, param, str);
	}
}
