/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:48:50 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/05 19:49:44 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	int		stop;

	i = 0;
	stop = 0;
	while (str1[i] && stop == 0 && i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	if (str1[0] == 0)
		return (-str2[0]);
	else if (str1[i] == 0 && i < n)
		return (-str2[i]);
	return (0);
}
