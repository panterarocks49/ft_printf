/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 20:04:29 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/18 20:04:47 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		set_env(t_env *env, va_list *args)
{
	ft_bzero(env->buf, BUF_SIZE);
	env->i = 0;
	env->bytes = 0;
	env->args = args;
}

static int		ft_printf_va(const char *format, va_list *args)
{
	t_env	env;
	t_param	param;

	set_env(&env, args);
	while (*format)
	{
		if (env.i == BUF_SIZE)
			flush_buf(&env);
		if (*format == '%')
		{
			format++;
			if (parse_arg(&format, &param))
				handle_arg(&env, &param);
		}
		else
			env.buf[env.i++] = *format++;
	}
	flush_buf(&env);
	return (env.bytes);
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	int		bytes;

	bytes = 0;
	if (format)
	{
		va_start(args, format);
		bytes = ft_printf_va(format, &args);
		va_end(args);
	}
	return (bytes);
}
