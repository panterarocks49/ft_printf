/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:52:12 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/17 14:52:21 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*ret;
	t_list	*lst_ptr;

	ret = NULL;
	if (lst)
	{
		ret = ft_lstnew(lst->content, lst->content_size);
		lst_ptr = ret;
		while (lst->next)
		{
			lst = lst->next;
			lst_ptr->next = ft_lstnew(lst->content, lst->content_size);
			lst_ptr = lst_ptr->next;
		}
	}
	return (ret);
}