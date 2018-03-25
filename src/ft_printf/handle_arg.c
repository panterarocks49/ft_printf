/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:54:28 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/23 19:54:43 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	intmax_size(t_param *param, intmax_t d)
{
	int	size;

	size = 1;
	if (d < 0 || (param->flags & FLAG_SPACE) == FLAG_SPACE
		|| (param->flags & FLAG_PLUS) == FLAG_PLUS)
		size++;
	while ((d = d / 10))
		size++;
	return (size);
}


static void	pf_itoa(t_env *env, t_param *param, intmax_t d)
{
	int neg;
	int	width;
	int i;

	if (!(neg = 0) && d < 0)
		neg = 1;
	width = intmax_size(param, d);
	if (param->min_width > width)
		width = param->min_width;
	if (width + env->i >= BUF_SIZE)
		flush_buf(env);
	i = env->i + width - 1;
	while ((param->flags & FLAG_LEFT) == FLAG_LEFT && i > env->i + width - 1)
	{
		env->buf[i--] = ' ';
	}
	if (!d)
		env->buf[i--] = '0';
	while (d)
	{
		env->buf[i--] = FT_ABS(d % 10) + '0';
		d = d / 10;
	}
	if (neg)
		env->buf[i--] = '-';
	else if ((param->flags & FLAG_PLUS) == FLAG_PLUS)
		env->buf[i--] = '+';
	else if ((param->flags & FLAG_SPACE) == FLAG_SPACE)
		env->buf[i--] = ' ';
	while (i > env->i - 1)
	{
		if ((param->flags & FLAG_ZERO) == FLAG_ZERO)
			env->buf[i--] = '0';
		else
			env->buf[i--] = ' ';
	}
	env->i += width;
}

// doesnt acc for # yet
static int	uintmax_size(t_param *param, uintmax_t d)
{
	int	size;

	size = 1;
	if ((param->flags & FLAG_SPACE) == FLAG_SPACE
		|| (param->flags & FLAG_PLUS) == FLAG_PLUS)
		size++;
	while ((d = d / 10))
		size++;
	return (size);
}


static void	pf_uitoa_base(t_env *env, t_param *param, uintmax_t u)
{
	int	size;

	size = uintmax_size(param, u);
	if (size + env->i >= BUF_SIZE)
		flush_buf(env);
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

void		handle_uint(t_env *env, t_param *param)
{
	uintmax_t u;

	if ((param->flags & LTH_HH) == LTH_HH)
		u = (uintmax_t)((unsigned char)va_arg(*env->args, int));
	else if ((param->flags & LTH_H) == LTH_H)
		u = (uintmax_t)((unsigned short)va_arg(*env->args, int));
	else if ((param->flags & LTH_L) == LTH_L)
		u = (uintmax_t)va_arg(*env->args, unsigned long);
	else if ((param->flags & LTH_LL) == LTH_LL)
		u = (uintmax_t)va_arg(*env->args, unsigned long long);
	else if ((param->flags & LTH_J) == LTH_J)
		u = va_arg(*env->args, uintmax_t);
	else
		u = (uintmax_t)va_arg(*env->args, unsigned int);
	pf_uitoa_base(env, param, u);
}

void	handle_arg(t_env *env, t_param *param)
{
	int						i;
	static const t_handler	handlers[15] = {
		{.conv = '%', .handler = handle_perc},
		{.conv = 's', .handler = &handle_str},
		{.conv = 'S', .handler = &handle_str},
		{.conv = 'p', .handler = &handle_ptr},
		{.conv = 'd', .handler = &handle_int},
		{.conv = 'D', .handler = &handle_int},
		{.conv = 'i', .handler = &handle_int},
		{.conv = 'o', .handler = &handle_uint},
		//{.conv = 'O', .handler = &handle_uint},
		{.conv = 'u', .handler = &handle_uint},
		//{.conv = 'U', .handler = &handle_uint},
		{.conv = 'x', .handler = &handle_uint},
		//{.conv = 'X', .handler = &handle_uint},
		{.conv = 'c', .handler = &handle_char},
		{.conv = 'C', .handler = &handle_char}};

	i = -1;
	while (++i < 15)
	{
		if (handlers[i].conv == param->conv)
			handlers[i].handler(env, param);
	}
}