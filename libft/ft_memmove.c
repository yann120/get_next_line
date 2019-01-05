/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:59:11 by yann              #+#    #+#             */
/*   Updated: 2019/01/05 19:45:00 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destbis;
	const char	*srcbis;

	destbis = (char *)dest;
	srcbis = (const char *)src;
	if (src >= dest)
		dest = ft_memcpy(dest, src, n);
	else
	{
		destbis += n;
		srcbis += n;
		while (n > 0)
		{
			*--destbis = *--srcbis;
			n--;
		}
	}
	return (dest);
}
