/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:46:58 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/24 14:46:59 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_char(t_env *env, t_param *param)
{
	int		c;

	if (param->conv == 'C' || (param->flags & LTH_L) == LTH_L)
		;
	else
	{
		c = va_arg(*env->args, int);
		cpy_char(env, c);
	}
}
