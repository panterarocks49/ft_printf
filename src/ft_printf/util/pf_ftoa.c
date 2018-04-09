/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:31:41 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/28 18:31:43 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_f_size(t_param *param, long double f)
{
	long int	ipart;
	int			size;

	ipart = (long int)f;
	size = 1;
	while ((ipart = ipart / 10))
		size++;
	if (param->max_width == 0)
		return (size);
	else if (param->max_width > 0)
		return (size + 1 + param->max_width);
	return (size + 1 + 6);
}

static	int	ft_intlen(int n, int base)
{
	int len;

	len = 1;
	while ((n = n / base))
		len++;
	return (len);
}

static void	print_float(t_env *env, t_param *param, int *i, long double f)
{
	long int	fpart;
	long int	ipart;
	int			sign;
	int			prec;

	if ((sign = 1) == 1 && f < 0)
		sign = -1;
	if ((prec = 6) == 6 && param->max_width > -1)
		prec = param->max_width;
	ipart = (long int)f;
	fpart = ft_pow(10, prec + 1) * FT_ABS(f - (long double)ipart);
	if (fpart % 10 > 4)
		fpart++;
	if (ft_intlen((fpart = fpart / 10), 10) > prec)
		ipart += sign;
	while (prec-- > 0)
	{
		env->buf[(*i)--] = fpart % 10 + '0';
		fpart = fpart / 10;
	}
	if (param->max_width != 0)
		env->buf[(*i)--] = '.';
	env->buf[(*i)--] = FT_ABS(ipart % 10) + '0';
	while ((ipart = ipart / 10))
		env->buf[(*i)--] = FT_ABS(ipart % 10) + '0';
}

void		pf_ftoa(t_env *env, t_param *param, long double f)
{
	char		sign;
	int			i;
	int			size;
	int			width;

	size = pf_f_size(param, f);
	sign = intmax_sign(param, (intmax_t)f);
	width = calc_width(env, param, size, !(!sign));
	i = env->i + width - 1;
	if ((param->flags & FLAG_LEFT) == FLAG_LEFT)
		while (i > env->i + size + !(!sign) - 1)
			env->buf[i--] = ' ';
	print_float(env, param, &i, f);
	if ((param->flags & FLAG_LEFT) == FLAG_LEFT)
		while (i > env->i - 1 + !(!sign))
			env->buf[i--] = '0';
	if ((param->flags & FLAG_ZERO) == FLAG_ZERO && param->max_width == -1)
		while (i > env->i - 1 + !(!sign))
			env->buf[i--] = '0';
	if (sign && i >= env->i - 1 + !(!sign))
		env->buf[i--] = sign;
	while (i > env->i - 1)
		env->buf[i--] = ' ';
	env->i += width;
}
