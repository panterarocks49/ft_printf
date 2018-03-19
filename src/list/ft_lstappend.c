/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 21:31:44 by jbrown            #+#    #+#             */
/*   Updated: 2018/02/23 22:07:57 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*node;

	if (!alst)
		return ;
	else if (!*alst)
	{
		*alst = new;
		return ;
	}
	node = *alst;
	while (node->next)
		node = node->next;
	node->next = new;
}
