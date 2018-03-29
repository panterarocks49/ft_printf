/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:44:58 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/24 14:44:59 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cpy_wchar(t_env *env, wint_t wt)
{
	if (wt <= 0x007F)
		cpy_char(env, wt);
	else if (wt <= 0x07FF)
	{
		cpy_char(env, (wt >> 6) | 0xC0);
		cpy_char(env, (wt & 0x3F) | 0x80);
	}
	else if (wt <= 0xFFFF)
	{
		cpy_char(env, (wt >> 12) | 0xE0);
		cpy_char(env, ((wt >> 6) & 0x3F) | 0x80);
		cpy_char(env, (wt & 0x3F) | 0x80);
	}
	else if (wt <= 0x10FFFF)
	{
		cpy_char(env, (wt >> 18) | 0xF0);
		cpy_char(env, ((wt >> 12) & 0x3F) | 0x80);
		cpy_char(env, ((wt >> 6) & 0x3F) | 0x80);
		cpy_char(env, (wt & 0x3F) | 0x80);
	}
}

void	cpy_char(t_env *env, int c)
{
	if (env->i >= BUF_SIZE)
		flush_buf(env);
	env->buf[env->i++] = (char)c;
}

void	flush_buf(t_env *env)
{
	env->bytes += write(1, env->buf, env->i);
	env->i = 0;
}
