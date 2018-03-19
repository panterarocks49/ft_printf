/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 22:51:43 by jbrown            #+#    #+#             */
/*   Updated: 2018/02/23 23:33:46 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	sub_lstrev(t_list **alst, int len)
{
	int		i;
	t_list	*start;
	t_list	*end;
	void	*tmp_content;
	size_t	tmp_size;

	i = -1;
	tmp_content = NULL;
	tmp_size = 0;
	while (++i < len--)
	{
		start = ft_lstat(*alst, i);
		end = ft_lstat(*alst, len);
		tmp_content = start->content;
		tmp_size = start->content_size;
		start->content = end->content;
		start->content_size = end->content_size;
		end->content = tmp_content;
		end->content_size = tmp_size;
	}
}

void		ft_lstrev(t_list **alst)
{
	int		len;

	if (!alst)
		return ;
	len = ft_lstsize(*alst);
	sub_lstrev(alst, len);
}
