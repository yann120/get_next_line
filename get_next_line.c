/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:25:38 by yann              #+#    #+#             */
/*   Updated: 2018/12/25 10:56:41 by yann             ###   ########.fr       */
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
	if (*temp != 0)
		free(temp);
	return (returnvalue);
}

int ft_return_good_line(char **result, char *temp, char **line)
{
	int returnvalue;

	if (*temp == '\n')
		returnvalue = 1;
	else
		returnvalue = 0;
	*temp = 0;
	*line = ft_strjoin("", *result);
	if (returnvalue == 0 && ft_strlen(*result) != 0)
	{
		*result = ft_strnew(1);
		return (1);
	}
	else if (returnvalue == 0 && !(ft_strlen(*result)))
		return (0);
	// *result = temp + 1;
	printf("avant = \"%s\"\n", *result);
	*result = ft_strjoin(temp + 1, "");
	printf("apres \"%s\"\n", *result);
	return (returnvalue);
}

int get_next_line(int const fd, char **line)
{
	int				returnvalue;
	static char 	*result;
	char			*temp;

// ordre a verifier entre 2 conditions result et line
	if (result == NULL)
		result = ft_strnew(1);
	if (line == NULL || BUFF_SIZE < 1)
		return (-1);
	returnvalue = BUFF_SIZE;
	while (line != NULL)
	{
		temp = result;
		while (*temp || returnvalue < BUFF_SIZE)
		{
			if (*temp == '\n' || *temp == 0)
				return (ft_return_good_line(&result, temp, line));
			temp++;
		}
		returnvalue = ft_read(&result, fd);
		if (returnvalue == -1)
			return (-1);
	}
	return (0);
}