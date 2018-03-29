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
/*
static int	longint_size(long int x, int base)
{
	int size;

	size = 1;
	while ((x = x / base))
}

static void pf_int_str(t_env *env, long int x)
{
	if (x)
		env->i[]
}*/

void		pf_ftoa_base(t_env *env, t_param *param, long double f, int base)
{
	long double	fpart;
	long int	ipart;

	ipart = (long int)f;
	fpart = f - ipart - base + param->conv;
	//pf_int_str(env, ipart);
	cpy_char(env, '.');
	//pf_int_str(env, (long int)(fpart * 10 * 10 * 10 * 10 * 10 * 10));
}
