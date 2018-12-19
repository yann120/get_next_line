/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldgnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 09:50:09 by ypetitje          #+#    #+#             */
/*   Updated: 2018/12/18 16:21:27 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 10420
// probleme a resoudre : faire en sorte que le rest lu soit effacé et remis a zero. il doit rester que ce qui n'a pas été lu du reste apres le \n.
#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

char	*ft_strichr(const char *s, int c, int i)
{
	while (s[i])
	{
		if (s[i] == c)
			return (&((char *)s)[i]);
		i++;
	}
	if (s[i] == c)
		return (&((char *)s)[i]);
	return (NULL);
}

int get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	// char	*head;
	// int idebug = 0;
	static char *rest;
	char result[10420];
	int i = 0;
	int j;
	ft_strclr(*line);
	// printf("rest = %s\n", rest);
	if (rest != NULL && read(fd, &buf, BUFF_SIZE) == 0)
		while (rest[i] && rest[i] != '\n')
		{
			result[i] = rest[i];
			i++;

		}
		j = 0;
		while (i >= 0)
		{
			rest[j] = rest[i] 
		}

	// temp = 
	while (read(fd, &buf, BUFF_SIZE) != 0)
	{	
		j = 0;
		buf[BUFF_SIZE] = '\0';
		// ft_putstr(buf);
		// printf("\n");
		// printf("buf=%s\n", buf);
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

// int main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i = 0;

// 	// fd = open("../poeme.txt", O_RDONLY);
// 	fd = open("../1line.txt", O_RDONLY);
// 	while(i++ < 3)
// 	{
// 		get_next_line(fd, &line);
// 		printf("%s\n", line);
// 	}
// 	return 0;
// }