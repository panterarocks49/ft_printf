/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:54:19 by jbrown            #+#    #+#             */
/*   Updated: 2018/02/23 21:14:22 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	next = NULL;
	if (alst && *alst && del)
	{
		next = (*alst)->next;
		ft_lstdelone(alst, del);
		ft_lstdel(&next, del);
	}
}
