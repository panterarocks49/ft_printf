/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:32:06 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/28 14:32:08 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	uintmax_size(t_param *param, uintmax_t u, int base)
{
	int	size;

	if (!u && param->max_width == 0)
		return (0);
	size = 1;
	while ((u = u / base))
		size++;
	if (param->max_width > size)
		return (param->max_width);
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

static int	uintmax_prefix(t_param *param, uintmax_t u)
{
	int sign;

	sign = 0;
	if ((param->flags & FLAG_HASH) == FLAG_HASH)
	{
		if ((u && (param->conv == 'o' || param->conv == 'O')) ||
			(param->max_width == 0 && !u &&
				(param->conv == 'o' || param->conv == 'O')))
			sign = 1;
		else if (param->conv == 'p')
			sign = 2;
		else if (u && (param->conv == 'x' || param->conv == 'X'
			|| param->conv == 'b' || param->conv == 'B'))
			sign = 2;
	}
	return (sign);
}

static void	cpy_sign_pad(t_env *env, t_param *param, int i, int sign)
{
	if ((param->flags & FLAG_ZERO) == FLAG_ZERO
		|| ((param->flags & FLAG_LEFT) == FLAG_LEFT))
		while (i > env->i - 1 + sign)
			env->buf[i--] = '0';
	if ((param->flags & FLAG_HASH) == FLAG_HASH
		&& i >= env->i - 1 + sign && sign)
	{
		if (param->conv == 'x' || param->conv == 'p')
			env->buf[i--] = 'x';
		else if (param->conv == 'X')
			env->buf[i--] = 'X';
		else if (param->conv == 'b')
			env->buf[i--] = 'b';
		else if (param->conv == 'B')
			env->buf[i--] = 'B';
		if (ft_strchr("oOxXpbB", param->conv))
			env->buf[i--] = '0';
	}
	while (i > env->i - 1)
		env->buf[i--] = ' ';
}

void		pf_uitoa_base(t_env *env, t_param *param, uintmax_t u, int base)
{
	char	*cbase;
	int		sign;
	int		size;
	int		width;
	int		i;

	sign = uintmax_prefix(param, u);
	size = uintmax_size(param, u, base);
	width = size + sign;
	if (param->min_width > width)
		width = param->min_width;
	if (width + env->i >= BUF_SIZE)
		flush_buf(env);
	i = env->i + width - 1;
	if ((param->flags & FLAG_LEFT) == FLAG_LEFT)
		while (i > env->i + size + sign - 1)
			env->buf[i--] = ' ';
	if (size && (cbase = ubase_str(param)))
		env->buf[i--] = cbase[FT_ABS(u % base)];
	while ((u = u / base))
		env->buf[i--] = cbase[FT_ABS(u % base)];
	while (i > env->i - 1 + width - size)
		env->buf[i--] = '0';
	cpy_sign_pad(env, param, i, sign);
	env->i += width;
}
