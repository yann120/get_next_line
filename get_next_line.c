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

// 10420

#include "get_next_line.h"
#include "../../libft/verif/libft.h"
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 5

int get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	// char	**headtemp;
	// char	*head;
	// int idebug = 0;
	static char *rest;
	char result[10420];
	int i = 0;
	int j;


	// temp = 
	while (read(fd, &buf, BUFF_SIZE) != 0)
	{	
		j = 0;
		buf[BUFF_SIZE] = '\0';
		// ft_putstr(buf);
		// printf("\n");
		if (ft_strchr(buf, '\n'))
		{
			while (buf[j] != '\n')
				result[i++] = buf[j++];
			result[i] = '\0';
			*line = result;
			rest = ft_strsub(buf, j, ft_strlen(buf) - j);
			return (1);
			// printf("new line%d\n", idebug++);
		}
		else
		{
			// printf("new string\n");
			while (buf[j])
				result[i++] = buf[j++];
		}
			// write(1, &buf, BUFF_SIZE);
	}
	return (0);
}

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("../poeme.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}
