/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:18:05 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/25 13:18:07 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_int(t_env *env, t_param *param)
{
	intmax_t d;

	if (param->conv == 'D')
		d = (intmax_t)va_arg(*env->args, long long);
	else if ((param->flags & LTH_HH) == LTH_HH)
		d = (intmax_t)((char)va_arg(*env->args, int));
	else if ((param->flags & LTH_H) == LTH_H)
		d = (intmax_t)((short)va_arg(*env->args, int));
	else if ((param->flags & LTH_L) == LTH_L)
		d = (intmax_t)va_arg(*env->args, long);
	else if ((param->flags & LTH_LL) == LTH_LL)
		d = (intmax_t)va_arg(*env->args, long long);
	else if ((param->flags & LTH_J) == LTH_J)
		d = va_arg(*env->args, intmax_t);
	else if ((param->flags & LTH_Z) == LTH_Z)
		d = (intmax_t)((ssize_t)va_arg(*env->args, intmax_t));
	else
		d = (intmax_t)va_arg(*env->args, int);
	pf_itoa(env, param, d);
}
