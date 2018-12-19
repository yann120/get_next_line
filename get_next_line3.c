/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:25:38 by yann              #+#    #+#             */
/*   Updated: 2018/12/18 16:25:53 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

int		get_next_line(const int fd, char **line)
{
	static char 	*result[1];
	char			buf[BUFF_SIZE + 1];
	char			*temp;
	int				returnvalue;

	while ((returnvalue = read(fd, &buf, BUFF_SIZE) > 0))
	{
		buf[BUFF_SIZE]  = '\0';
		temp = ft_strjoin(result[0], buf);
		ft_strdel(&result[0]);
		result[0] = temp;
		ft_strdel(&temp);
		printf("%d\n", returnvalue);
	}
	return(1);
}