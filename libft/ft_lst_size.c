/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:28:37 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/05 19:45:08 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_lst_size(t_list **begin_list)
{
	size_t i;
	t_list *list;

	if (*begin_list == NULL)
		return (0);
	list = *begin_list;
	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
