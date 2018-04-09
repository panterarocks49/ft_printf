/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:54:28 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/23 19:54:43 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_arg_2(t_env *env, t_param *param)
{
	int						i;
	static const t_handler	handlers[9] = {
		{.conv = 's', .handler = &handle_str},
		{.conv = 'S', .handler = &handle_str},
		{.conv = 'c', .handler = &handle_char},
		{.conv = 'C', .handler = &handle_char},
		{.conv = 'f', .handler = &handle_float},
		{.conv = 'F', .handler = &handle_float},
		{.conv = 'b', .handler = &handle_uint},
		{.conv = 'B', .handler = &handle_uint},
		{.conv = 'n', .handler = &handle_int_ptr}};

	i = -1;
	while (++i < 9)
	{
		if (handlers[i].conv == param->conv)
			handlers[i].handler(env, param);
	}
}

void		handle_arg(t_env *env, t_param *param)
{
	int						i;
	static const t_handler	handlers[11] = {
		{.conv = '%', .handler = handle_perc},
		{.conv = 'p', .handler = &handle_ptr},
		{.conv = 'd', .handler = &handle_int},
		{.conv = 'D', .handler = &handle_int},
		{.conv = 'i', .handler = &handle_int},
		{.conv = 'o', .handler = &handle_uint},
		{.conv = 'O', .handler = &handle_uint},
		{.conv = 'u', .handler = &handle_uint},
		{.conv = 'U', .handler = &handle_uint},
		{.conv = 'x', .handler = &handle_uint},
		{.conv = 'X', .handler = &handle_uint}};

	handle_min_wld(env, param);
	handle_max_wld(env, param);
	i = -1;
	while (++i < 11)
	{
		if (handlers[i].conv == param->conv)
			handlers[i].handler(env, param);
	}
	handle_arg_2(env, param);
}
