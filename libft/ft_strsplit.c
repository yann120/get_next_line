/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:11:11 by ypetitje          #+#    #+#             */
/*   Updated: 2019/01/05 19:44:43 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char		**create_tab(char const *s, char c)
{
	size_t		i;
	int			count;
	char		**tab;

	count = 0;
	i = 0;
	while (s[i] && i < ft_strlen((char *)s))
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (tab == NULL)
		return (NULL);
	tab[count] = 0;
	return (tab);
}

static char		**free_memory(char **tab)
{
	free(tab);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	int		j;
	char	**tab;
	int		start;

	if (s == NULL)
		return (NULL);
	if ((tab = create_tab(s, c)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && i < ft_strlen((char *)s))
	{
		while (s[i] == c)
			i++;
		if (s[i] != 0)
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			if (!(tab[j++] = ft_strsub(s, start, i - start)))
				return (free_memory(tab));
		}
	}
	return (tab);
}
