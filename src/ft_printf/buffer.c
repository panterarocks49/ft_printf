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
