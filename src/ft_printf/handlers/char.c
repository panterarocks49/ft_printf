/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:46:58 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/24 14:46:59 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_wchar(t_env *env, t_param *param, wint_t wt)
{
	char	pad;
	int		i;

	i = 1;
	pad = ' ';
	if ((param->flags & FLAG_ZERO) == FLAG_ZERO)
		pad = '0';
	if ((param->flags & FLAG_LEFT) == FLAG_LEFT)
		cpy_wchar(env, wt);
	else
	{
		while (i++ < param->min_width)
			cpy_char(env, pad);
		cpy_wchar(env, wt);
	}
	while (i++ < param->min_width)
		cpy_char(env, ' ');
}

static void	print_char(t_env *env, t_param *param, int c)
{
	char	pad;
	int		i;

	i = 1;
	pad = ' ';
	if ((param->flags & FLAG_ZERO) == FLAG_ZERO)
		pad = '0';
	if ((param->flags & FLAG_LEFT) == FLAG_LEFT)
		cpy_char(env, c);
	else
	{
		while (i++ < param->min_width)
			cpy_char(env, pad);
		cpy_char(env, c);
	}
	while (i++ < param->min_width)
		cpy_char(env, ' ');
}

void		handle_char(t_env *env, t_param *param)
{
	wint_t	wt;
	int		c;

	if (param->conv == 'C' || (param->flags & LTH_L) == LTH_L)
	{
		wt = va_arg(*env->args, wint_t);
		print_wchar(env, param, wt);
	}
	else
	{
		c = va_arg(*env->args, int);
		print_char(env, param, c);
	}
}
