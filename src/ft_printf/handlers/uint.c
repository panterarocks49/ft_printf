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

// doesnt acc for # yet
static int	uintmax_size(t_param *param, uintmax_t u, int base)
{
	int	size;

	size = 0;
	if (param->max_width != 0 || u)
		size++;
	if ((param->flags & FLAG_HASH) == FLAG_HASH && u)
	{
		if (param->conv == 'o')
			size++;
		else if (param->conv == 'x' || param->conv == 'X')
			size += 2;
	}
	while ((u = u / base))
		size++;
	return (size);
}

static char	*ubase_str(t_param *param)
{
	static char	*lower_base = "0123456789abcdef";
	static char	*upper_base = "0123456789ABCDEF";

	if (param->conv == 'X')
		return (upper_base);
	return (lower_base);
}

static void	pf_uitoa_base(t_env *env, t_param *param, uintmax_t u, int base)
{
	char	*cbase;
	int		sign;
	int		size;
	int		width;
	int		i;

	cbase = ubase_str(param);
	size = uintmax_size(param, u, base);
	width = size;
	if (param->min_width > size)
		width = param->min_width;
	if (width + env->i >= BUF_SIZE)
		flush_buf(env);
	i = env->i + width - 1;
	if ((param->flags & FLAG_LEFT) == FLAG_LEFT)
		while (i > env->i + size - 1)
			env->buf[i--] = ' ';
	if (param->max_width != 0 || u)
		env->buf[i--] = cbase[FT_ABS(u % base)];
	while ((u = u / base))
	{
		env->buf[i--] = cbase[FT_ABS(u % base)];
	}
	sign = i - (width - size) - env->i + 1;
	if ((param->flags & FLAG_ZERO) == FLAG_ZERO)
		while (i > env->i - 1 + sign)
			env->buf[i--] = '0';
	if ((param->flags & FLAG_HASH) == FLAG_HASH && i >= env->i - 1 + sign)
	{
		if (param->conv == 'x' || param->conv == 'X')
			env->buf[i--] = param->conv;
		if (param->conv == 'o' || param->conv == 'x' || param->conv == 'X')
			env->buf[i--] = '0';
	}
	while (i > env->i - 1)
		env->buf[i--] = ' ';
	env->i += width;
}



void		handle_uint(t_env *env, t_param *param)
{
	uintmax_t u;

	if ((param->flags & LTH_HH) == LTH_HH && param->conv != 'U')
		u = (uintmax_t)((unsigned char)va_arg(*env->args, int));
	else if ((param->flags & LTH_H) == LTH_H && param->conv != 'U')
		u = (uintmax_t)((unsigned short)va_arg(*env->args, int));
	else if ((param->flags & LTH_L) == LTH_L || param->conv == 'U')
		u = (uintmax_t)va_arg(*env->args, unsigned long);
	else if ((param->flags & LTH_LL) == LTH_LL)
		u = (uintmax_t)va_arg(*env->args, unsigned long long);
	else if ((param->flags & LTH_J) == LTH_J)
		u = va_arg(*env->args, uintmax_t);
	else
		u = (uintmax_t)va_arg(*env->args, unsigned int);
	if (param->conv == 'u' || param->conv == 'U')
		pf_uitoa_base(env, param, u, 10);
	else if (param->conv == 'o' || param->conv == 'O')
		pf_uitoa_base(env, param, u, 8);
	else if (param->conv == 'x' || param->conv == 'X')
		pf_uitoa_base(env, param, u, 16);
}











