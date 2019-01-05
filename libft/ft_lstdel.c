/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:55:49 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/05 19:45:07 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *elem;
	t_list *elemnext;

	elem = *alst;
	while (elem)
	{
		elemnext = elem->next;
		del(elem->content, elem->content_size);
		free(elem);
		elem = elemnext;
	}
	free(elem);
	*alst = NULL;
}
