/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:49:37 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/23 17:49:46 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*parse_flags(const char *format, t_param *param)
{
	if (*format == '#')
		param->flags = param->flags | FLAG_HASH;
	else if (*format == '0')
		param->flags = param->flags | FLAG_ZERO;
	else if (*format == '-')
		param->flags = param->flags | FLAG_LEFT;
	else if (*format == '+')
		param->flags = param->flags | FLAG_PLUS;
	else if (*format == ' ')
		param->flags = param->flags | FLAG_SPACE;
	else
		return (format);
	return (parse_flags(++format, param));
}

static const char	*parse_min_width(const char *format, t_param *param)
{
	param->min_width = -1;
	if (ft_strchr("0123456789", *format))
	{
		param->min_width = ft_atoi(format);
		while (ft_strchr("0123456789", *format))
			format++;
	}
	return (format);
}

static const char	*parse_max_width(const char *format, t_param *param)
{
	param->max_width = -1;
	if (*format == '.' && ft_strchr("0123456789", *(format + 1)))
	{
		param->max_width = ft_atoi(++format);
		while (ft_strchr("0123456789", *format))
			format++;
	}
	return (format);
}

static const char	*parse_length(const char *format, t_param *param)
{
	if (*format == 'h' && *(format + 1) == 'h')
		param->flags = param->flags | LTH_HH;
	else if (*format == 'h')
		param->flags = param->flags | LTH_H;
	else if (*format == 'l')
		param->flags = param->flags | LTH_L;
	else if (*format == 'l' && *(format + 1) == 'l')
		param->flags = param->flags | LTH_LL;
	else if (*format == 'j')
		param->flags = param->flags | LTH_J;
	else if (*format == 'z')
		param->flags = param->flags | LTH_Z;
	else if (*format == 't')
		param->flags = param->flags | LTH_T;
	else
		return (format);
	return (parse_length(++format, param));
}

const char			*parse_arg(const char *format, t_param *param)
{
	param->flags = 0;
	if ((format = parse_flags(format, param)))
	{
		if ((format = parse_min_width(format, param)))
		{
			if ((format = parse_max_width(format, param)))
			{
				if ((format = parse_length(format, param)))
				{
					if (ft_strchr("%sSpdDioOuUxXcC", *format))
					{
						param->conv = *format++;
						return (format);
					}
				}
			}
		}
	}
	return (NULL);
}