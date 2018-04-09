/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:19:57 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/28 14:19:58 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	intmax_size(t_param *param, intmax_t d)
{
	int	size;

	if (!d && param->max_width == 0)
		return (0);
	size = 1;
	while ((d = d / 10))
		size++;
	if (param->max_width > size)
		return (param->max_width);
	return (size);
}

char		intmax_sign(t_param *param, intmax_t d)
{
	char	sign;

	sign = 0;
	if (d < 0)
		sign = '-';
	else if ((param->flags & FLAG_PLUS) == FLAG_PLUS)
		sign = '+';
	else if ((param->flags & FLAG_SPACE) == FLAG_SPACE)
		sign = ' ';
	return (sign);
}

static void	cpy_pad(t_env *env, char sign, int i, int width)
{
	if (sign && i >= env->i - 1 + !(!sign))
		env->buf[i--] = sign;
	while (i > env->i - 1)
		env->buf[i--] = ' ';
	env->i += width;
}

int			calc_width(t_env *env, t_param *param, int size, int sign)
{
	int	width;

	width = size + sign;
	if (param->min_width > size)
		width = param->min_width;
	if (width + env->i >= BUF_SIZE)
		flush_buf(env);
	return (width);
}

void		pf_itoa(t_env *env, t_param *param, intmax_t d)
{
	char	sign;
	int		size;
	int		width;
	int		i;

	sign = intmax_sign(param, d);
	size = intmax_size(param, d);
	width = calc_width(env, param, size, !(!sign));
	i = env->i + width - 1;
	if ((param->flags & FLAG_LEFT) == FLAG_LEFT)
		while (i > env->i + size + !(!sign) - 1)
			env->buf[i--] = ' ';
	if (size)
		env->buf[i--] = FT_ABS(d % 10) + '0';
	while ((d = d / 10))
		env->buf[i--] = FT_ABS(d % 10) + '0';
	while (i > env->i - 1 + width - size)
		env->buf[i--] = '0';
	if ((param->flags & FLAG_LEFT) == FLAG_LEFT)
		while (i > env->i - 1 + !(!sign))
			env->buf[i--] = '0';
	if ((param->flags & FLAG_ZERO) == FLAG_ZERO && param->max_width == -1)
		while (i > env->i - 1 + !(!sign))
			env->buf[i--] = '0';
	cpy_pad(env, sign, i, width);
}
