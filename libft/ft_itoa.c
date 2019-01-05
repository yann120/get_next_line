/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:16:40 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/05 19:45:10 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_len(int n)
{
	int len;

	len = 0;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		negative;
	int		len;
	char	*str;

	len = 1;
	negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	len += ft_len(n) + negative;
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	str[len-- + 1] = 0;
	while (len >= 0)
	{
		str[len--] = n % 10 + '0';
		n = n / 10;
	}
	if (negative == 1)
		str[0] = '-';
	return (str);
}
