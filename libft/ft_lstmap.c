/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:28:37 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/05 19:45:05 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;
	t_list	*resulthead;
	t_list	*result;
	t_list	*tmp;

	elem = lst;
	resulthead = ft_lstnew(elem->content, elem->content_size);
	resulthead = f(resulthead);
	result = resulthead;
	elem = elem->next;
	while (elem)
	{
		tmp = ft_lstnew(elem->content, elem->content_size);
		tmp = f(tmp);
		result->next = tmp;
		elem = elem->next;
		result = result->next;
	}
	return (resulthead);
}
