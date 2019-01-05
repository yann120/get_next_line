/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:28:37 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/05 19:45:09 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lst_push_back(t_list **begin_list, void const *data)
{
	t_list	*list;

	if (*begin_list == NULL)
	{
		*begin_list = ft_lst_create_elem(data);
		if (*begin_list == NULL)
			return ;
	}
	else
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		list->next = ft_lst_create_elem(data);
	}
}
