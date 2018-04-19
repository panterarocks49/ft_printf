/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 20:05:25 by jbrown            #+#    #+#             */
/*   Updated: 2018/04/18 18:22:28 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <libft.h>
# include <wchar.h>
# define BUF_SIZE 4096
# define FLAG_LEFT 1
# define FLAG_ZERO 2
# define FLAG_PLUS 4
# define FLAG_SPACE 8
# define FLAG_HASH 16
# define LTH_HH 32
# define LTH_H 64
# define LTH_L 128
# define LTH_LL 256
# define LTH_J 512
# define LTH_Z 1024
# define LTH_T 2048
# define LTH_CAPL 4096
# define MIN_WIDTH_WLD 8192
# define MAX_WIDTH_WLD 16384
# define MDF_W 32768

typedef struct		s_env
{
	va_list		*args;
	char		buf[BUF_SIZE];
	int			i;
	size_t		bytes;
}					t_env;

typedef struct		s_param
{
	int			flags;
	int			max_width;
	int			min_width;
	char		conv;
}					t_param;

typedef struct		s_handler
{
	char		conv;
	void		(*handler)(t_env *, t_param *);
}					t_handler;

void				pf_itoa(t_env *env, t_param *param, intmax_t d);
int					calc_width(t_env *env, t_param *param, int size, int sign);
char				intmax_sign(t_param *param, intmax_t d);

void				pf_uitoa_base(t_env *env, t_param *param, uintmax_t u,
									int base);

void				pf_ftoa(t_env *env, t_param *param, long double f);

void				cpy_wchar(t_env *env, wint_t wt);
void				cpy_char(t_env *env, int c);
void				flush_buf(t_env *env);

int					parse_arg(const char **format, t_param *param);

void				handle_arg(t_env *env, t_param *param);

void				handle_char(t_env *env, t_param *param);

void				handle_str(t_env *env, t_param *param);

void				handle_perc(t_env *env, t_param *param);

void				handle_ptr(t_env *env, t_param *param);

void				handle_int(t_env *env, t_param *param);

void				handle_uint(t_env *env, t_param *param);

void				handle_max_wld(t_env *env, t_param *param);
void				handle_min_wld(t_env *env, t_param *param);

void				handle_int_ptr(t_env *env, t_param *param);

void				handle_float(t_env *env, t_param *param);

#endif
