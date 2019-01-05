/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:48:04 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/05 19:44:44 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, int n)
{
	int i;
	int j;
	int k;

	i = 0;
	if (*to_find == 0)
		return ((char *)str);
	while (str[i] && i < n)
	{
		j = 0;
		k = i;
		while (str[i + j] == to_find[j] && k < n)
		{
			j++;
			k++;
			if (to_find[j] == 0)
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
