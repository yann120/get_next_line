/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:25:38 by yann              #+#    #+#             */
/*   Updated: 2019/01/05 17:53:46 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read(char **result, int fd)
{
	int		returnvalue;
	char 	buf[BUFF_SIZE + 1];
	char	*temp;

	if ((returnvalue = read(fd, buf, BUFF_SIZE)) < 0)
		return (-1);
	buf[returnvalue] = 0;
	temp = *result;
	*result = ft_strjoin(*result, buf);
	free(temp);
	return (returnvalue);
}

int ft_return_good_line(char **result, char *temp, char **line)
{
	int returnvalue;
	char *tofree;

	if (*temp == '\n')
		returnvalue = 1;
	else
		returnvalue = 0;
	*temp = 0;
	*line = ft_strdup(*result);
	if (returnvalue == 0 && ft_strlen(*result) > 0)
	{
		*result = ft_strnew(1);
		return (1);
	}
	else if (returnvalue == 0 && !(ft_strlen(*result)))
		return (0);
	tofree = *result;
	*result = ft_strdup(temp + 1);
	free(tofree);
	return (returnvalue);
}

int get_next_line(int const fd, char **line)
{
	int				returnvalue;
	static char 	*result;
	char			*temp;

	if (line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (result == NULL)
		result = ft_strnew(1);
	returnvalue = BUFF_SIZE;
	while (line != NULL)
	{
		temp = result;
		while (*temp != 0 || returnvalue < BUFF_SIZE)
		{
			if (*temp == '\n' || *temp == '\0')
				return (ft_return_good_line(&result, temp, line));
			temp++;
		}
		if ((returnvalue = ft_read(&result, fd)) < 0)
		{
			free(result);
			return (-1);
		}
	}
	return (0);
}