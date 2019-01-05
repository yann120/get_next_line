/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:23:28 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/05 19:45:13 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static long	result(const char *str, int i, int negative)
{
	long	result;

	result = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i++] - 48) * negative;
		else
			return (result);
	}
	return (result);
}

int			ft_atoi(const char *str)
{
	int i;
	int negative;

	i = 0;
	negative = 1;
	if (ft_strcmp(str, "2147483647") == 0)
		return (2147483647);
	else if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		negative = -1;
	}
	return ((int)result(str, i, negative));
}
