/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:42:30 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/02 19:35:26 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strgrow(char *ptr, size_t size)
{
	char	*new;

	if (!(new = ft_strnew(size)))
		return (NULL);
	ft_strcpy(new, ptr);
	free(ptr);
	return (new);
}

static t_file	*get_file(const int fd)
{
	static t_list	*files = NULL;
	t_list			*lst_ptr;
	t_file			*file;

	file = NULL;
	lst_ptr = files;
	while (lst_ptr)
	{
		file = lst_ptr->content;
		if (file->fd == fd)
			break ;
		file = NULL;
		lst_ptr = lst_ptr->next;
	}
	if (file == NULL)
	{
		file = (t_file *)ft_memalloc(sizeof(t_file));
		file->fd = fd;
		file->buf = ft_strnew(BUFF_SIZE);
		ft_lstadd(&files, ft_lstnew(file, sizeof(t_file)));
		free(file);
		file = (t_file *)files->content;
	}
	return (file);
}

static void		scrub_newline(char *buf)
{
	int		i;
	int		j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	j = 0;
	if (buf[i])
		i++;
	while (buf[i])
		buf[j++] = buf[i++];
	while (buf[j])
		buf[j++] = '\0';
}

static int		read_line(t_file *file, char **line, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (file->buf[i] != '\n')
	{
		if (!file->buf[i])
		{
			if (!(i = read(file->fd, file->buf, BUFF_SIZE)))
				break ;
			else if (i == -1)
				return (-1);
			file->buf[i] = '\0';
			i = 0;
		}
		else if (!(j < len))
			*line = ft_strgrow(*line, (len *= 2));
		else
			(*line)[j++] = file->buf[i++];
	}
	if (!j && file->buf[i] != '\n')
		return (0);
	scrub_newline(file->buf);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	t_file	*file;
	int		len;

	if (fd < 0 || !line)
		return (-1);
	file = get_file(fd);
	len = BUFF_SIZE;
	*line = ft_strnew(BUFF_SIZE);
	return (read_line(file, line, len));
}
