/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:46:51 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/28 15:46:53 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_float(t_env *env, t_param *param)
{
	long double f;

	if ((param->flags & LTH_CAPL) == LTH_CAPL)
		f = va_arg(*env->args, long double);
	else
		f = (long double)va_arg(*env->args, double);
	if (param->conv == 'f' || param->conv == 'F')
		pf_ftoa(env, param, f);
}
