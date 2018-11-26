/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 09:50:09 by ypetitje          #+#    #+#             */
/*   Updated: 2018/11/26 11:41:34 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 20000

int		main(void)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];

	fd = open("../st_exupery_le_petit_prince.txt", O_RDONLY);
	while (read(fd, &buf, BUFF_SIZE) != 0)
	{	
		if (strchr(buf, '\n'))
		write(1, &buf, BUFF_SIZE);
	}
	return (0);
}
