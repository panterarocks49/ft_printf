/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:57:20 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/24 14:57:23 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_ptr(t_env *env, t_param *param)
{
	uintmax_t u;

	param->flags = param->flags | FLAG_HASH;
	u = (uintmax_t)va_arg(*env->args, void *);
	pf_uitoa_base(env, param, u, 16);
}
