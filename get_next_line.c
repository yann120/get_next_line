/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:25:38 by yann              #+#    #+#             */
/*   Updated: 2019/01/07 19:36:58 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read(char **result, int fd)
{
	int		returnvalue;
	char	buf[BUFF_SIZE + 1];
	char	*temp;

	if ((returnvalue = read(fd, buf, BUFF_SIZE)) < 0)
		return (-1);
	buf[returnvalue] = 0;
	temp = result[fd];
	if (!(result[fd] = ft_strjoin(result[fd], buf)))
		return (-1);
	free(temp);
	return (returnvalue);
}

int	ft_return_good_line(char **result, char *temp, char **line, int fd)
{
	int		returnvalue;
	char	*tofree;

	if (*temp == '\n')
		returnvalue = 1;
	else
		returnvalue = 0;
	*temp = 0;
	if (!(*line = ft_strdup(result[fd])))
		return (-1);
	if (returnvalue == 0 && ft_strlen(result[fd]) > 0)
	{
		if (!(result[fd] = ft_strnew(1)))
			return (-1);
		return (1);
	}
	else if (returnvalue == 0 && !(ft_strlen(result[fd])))
		return (0);
	tofree = result[fd];
	if (!(result[fd] = ft_strdup(temp + 1)))
		return (-1);
	free(tofree);
	return (returnvalue);
}

int	get_next_line(int const fd, char **line)
{
	int				returnvalue;
	static char		*result[OPEN_MAX];
	char			*temp;

	if (fd < 0 || line == NULL || fd > OPEN_MAX)
		return (-1);
	if (result[fd] == NULL)
		if (!(result[fd] = ft_strnew(1)))
			return (-1);
	returnvalue = BUFF_SIZE;
	while (line != NULL)
	{
		temp = result[fd];
		while (*temp != 0 || returnvalue < BUFF_SIZE)
		{
			if (*temp == '\n' || *temp == '\0')
				return (ft_return_good_line(result, temp, line, fd));
			temp++;
		}
		if ((returnvalue = ft_read(result, fd)) < 0)
			return (-1);
	}
	return (0);
}
