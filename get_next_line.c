/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 09:50:09 by ypetitje          #+#    #+#             */
/*   Updated: 2018/12/01 11:49:04 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 10420

#include "get_next_line.h"
#include "libft/libft.h"
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

	if (rest != NULL)
		while (rest[i])
		{
			result[i] = rest[i];
			i++;
		}

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
			rest = ft_strsub(buf, j + 1, ft_strlen(buf) - j);
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

// int		main(void)
// {
// 	char 	*line;
// 	int		out;
// 	int		p[2];
// 	int		fd;

// 	out = dup(1);
// 	pipe(p);

// 	fd = 1;
// 	dup2(p[1], fd);
// 	write(fd, "efghijkl", 8);
// 	close(p[1]);
// 	dup2(out, fd);
// 	get_next_line(p[0], &line);
// 	printf("%s\n", line);
// 	printf("%d\n", ft_strcmp(line, "efghijkl"));
// 	return (0);
// }

int main(void)
{
	int		fd;
	char	*line;
	int		i = 0;

	// fd = open("../poeme.txt", O_RDONLY);
	fd = open("../1line.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return 0;
}