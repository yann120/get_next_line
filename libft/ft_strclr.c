/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:38:57 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/05 19:44:54 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strclr(char *s)
{
	int		n;
	int		i;
	char	*sptr;

	if (s == NULL)
		return ;
	n = 0;
	while (s[n])
		n++;
	i = 0;
	sptr = s;
	if (s != NULL)
		while (i < n)
			sptr[i++] = 0;
}
