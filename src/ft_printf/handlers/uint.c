/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:18:12 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/25 13:18:13 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_uint(t_env *env, t_param *param)
{
	uintmax_t u;

	if ((param->flags & LTH_L) == LTH_L || param->conv == 'U' ||
		param->conv == 'O')
		u = (uintmax_t)va_arg(*env->args, unsigned long);
	else if ((param->flags & LTH_HH) == LTH_HH)
		u = (uintmax_t)((unsigned char)va_arg(*env->args, int));
	else if ((param->flags & LTH_H) == LTH_H)
		u = (uintmax_t)((unsigned short)va_arg(*env->args, int));
	else if ((param->flags & LTH_LL) == LTH_LL)
		u = (uintmax_t)va_arg(*env->args, unsigned long long);
	else if ((param->flags & LTH_J) == LTH_J)
		u = va_arg(*env->args, uintmax_t);
	else if ((param->flags & LTH_Z) == LTH_Z)
		u = (intmax_t)((size_t)va_arg(*env->args, intmax_t));
	else
		u = (uintmax_t)va_arg(*env->args, unsigned int);
	if (param->conv == 'u' || param->conv == 'U')
		pf_uitoa_base(env, param, u, 10);
	else if (param->conv == 'o' || param->conv == 'O')
		pf_uitoa_base(env, param, u, 8);
	else if (param->conv == 'x' || param->conv == 'X')
		pf_uitoa_base(env, param, u, 16);
	else if (param->conv == 'b' || param->conv == 'B')
		pf_uitoa_base(env, param, u, 2);
}
