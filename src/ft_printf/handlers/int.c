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

static int	intmax_size(t_param *param, intmax_t d)
{
	int	size;

	size = 0;
	if (param->max_width != 0 || d)
		size++;
	if (d && (d < 0 || (param->flags & FLAG_SPACE) == FLAG_SPACE
		|| (param->flags & FLAG_PLUS) == FLAG_PLUS))
		size++;
	while ((d = d / 10))
		size++;
	return (size);
}

static char	intmax_sign(t_param *param, intmax_t d)
{
	char	sign;

	sign = 0;
	if (d < 0)
		sign = '-';
	else if (d && (param->flags & FLAG_PLUS) == FLAG_PLUS)
		sign = '+';
	else if (d && (param->flags & FLAG_SPACE) == FLAG_SPACE)
		sign = ' ';
	return (sign);
}

static void	pf_itoa(t_env *env, t_param *param, intmax_t d)
{
	char	sign;
	int		size;
	int		width;
	int 	i;

	sign = intmax_sign(param, d);
	size = intmax_size(param, d);
	width = size;
	if (param->min_width > size)
		width = param->min_width;
	if (width + env->i >= BUF_SIZE)
		flush_buf(env);
	i = env->i + width - 1;
	if ((param->flags & FLAG_LEFT) == FLAG_LEFT)
		while (i > env->i + size - 1)
			env->buf[i--] = ' ';
	if (param->max_width != 0 || d)
		env->buf[i--] = FT_ABS(d % 10) + '0';
	while ((d = d / 10))
		env->buf[i--] = FT_ABS(d % 10) + '0';
	if ((param->flags & FLAG_ZERO) == FLAG_ZERO)
		while (i > env->i - 1 + !(!sign))
			env->buf[i--] = '0';
	if (sign && i >= env->i - 1 + !(!sign))
		env->buf[i--] = sign;
	while (i > env->i - 1)
		env->buf[i--] = ' ';
	env->i += width;
}

void		handle_int(t_env *env, t_param *param)
{
	intmax_t d;

	if (param->conv == 'D')
		d = (intmax_t)va_arg(*env->args, long long);
	else if ((param->flags & LTH_HH) == LTH_HH)
		d = (intmax_t)va_arg(*env->args, int);
	else if ((param->flags & LTH_H) == LTH_H)
		d = (intmax_t)va_arg(*env->args, int);
	else if ((param->flags & LTH_L) == LTH_L)
		d = (intmax_t)va_arg(*env->args, long);
	else if ((param->flags & LTH_LL) == LTH_LL)
		d = (intmax_t)va_arg(*env->args, long long);
	else if ((param->flags & LTH_J) == LTH_J)
		d = va_arg(*env->args, intmax_t);
	else
		d = (intmax_t)va_arg(*env->args, int);
	pf_itoa(env, param, d);
}
