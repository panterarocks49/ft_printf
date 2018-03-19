/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:27:25 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/06 12:03:59 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 1024

typedef struct	s_file
{
	int		fd;
	char	*buf;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif
