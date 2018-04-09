/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:08:48 by jbrown            #+#    #+#             */
/*   Updated: 2018/04/07 13:08:50 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_int_ptr(t_env *env, t_param *param)
{
	size_t	len;

	len = env->bytes + env->i;
	if ((param->flags & LTH_HH) == LTH_HH)
		*va_arg(*env->args, signed char *) = (signed char)len;
	else if ((param->flags & LTH_H) == LTH_H)
		*va_arg(*env->args, short *) = (short)len;
	else if ((param->flags & LTH_L) == LTH_L)
		*va_arg(*env->args, long *) = (long)len;
	else if ((param->flags & LTH_LL) == LTH_LL)
		*va_arg(*env->args, long long *) = (long long)len;
	else if ((param->flags & LTH_J) == LTH_J)
		*va_arg(*env->args, intmax_t *) = (intmax_t)len;
	else if ((param->flags & LTH_Z) == LTH_Z)
		*va_arg(*env->args, ssize_t *) = (ssize_t)len;
	else
		*va_arg(*env->args, int *) = (int)len;
}
