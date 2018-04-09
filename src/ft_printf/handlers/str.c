/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:52:09 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/24 14:52:10 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	cpy_str(t_env *env, t_param *param, char *str)
{
	char	pad;
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(str);
	pad = ' ';
	if ((param->flags & FLAG_ZERO) == FLAG_ZERO)
		pad = '0';
	if (param->max_width > -1 && param->max_width < length)
		length = param->max_width;
	if ((param->flags & FLAG_LEFT) != FLAG_LEFT)
	{
		while (i++ < param->min_width - length)
			cpy_char(env, pad);
		i = 0;
	}
	while (i < length)
		cpy_char(env, str[i++]);
	if ((param->flags & FLAG_LEFT) == FLAG_LEFT)
		while (i++ < param->min_width)
			cpy_char(env, ' ');
}

static int	pf_wstrlen(t_param *param, wchar_t *wstr)
{
	int		i;
	int		len;

	i = 0;
	len = ft_wstrlen(wstr);
	if (param->max_width > -1 && param->max_width < len)
	{
		len = 0;
		while ((int)(len + ft_wclen(wstr[i])) <= param->max_width)
			len += ft_wclen(wstr[i++]);
	}
	return (len);
}

static void	cpy_wstr(t_env *env, t_param *param, wchar_t *wstr)
{
	char	pad;
	int		i;
	int		len;

	i = 0;
	len = pf_wstrlen(param, wstr);
	pad = ' ';
	if ((param->flags & FLAG_ZERO) == FLAG_ZERO)
		pad = '0';
	if ((param->flags & FLAG_LEFT) != FLAG_LEFT)
	{
		while (i++ < param->min_width - len)
			cpy_char(env, pad);
		i = 0;
	}
	while ((i += ft_wclen(*wstr)) <= len)
		cpy_wchar(env, *wstr++);
	if ((param->flags & FLAG_LEFT) == FLAG_LEFT)
		while (i++ < param->min_width)
			cpy_char(env, ' ');
}

void		handle_str(t_env *env, t_param *param)
{
	wchar_t	*wstr;
	char	*str;

	if (param->conv == 'S' || (param->flags & LTH_L) == LTH_L
		|| (param->flags & MDF_W) == MDF_W)
	{
		wstr = va_arg(*env->args, wchar_t *);
		if (wstr)
			cpy_wstr(env, param, wstr);
		else
			cpy_str(env, param, "(null)");
	}
	else
	{
		str = va_arg(*env->args, char *);
		if (str)
			cpy_str(env, param, str);
		else
			cpy_str(env, param, "(null)");
	}
}
