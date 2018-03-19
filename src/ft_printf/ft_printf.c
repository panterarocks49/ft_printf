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

static int	ft_printfva(const char *format, va_list args)
{
	int len;

	ft_putendl(format);
	len = va_arg(args, int);
	ft_putnbr(len);
	ft_putchar('\n');
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	
	if (format)
	{
		va_start(args, format);
		ft_printfva(format, args);
		va_end(args);
	}
	return (len);
}