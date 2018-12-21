/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:25:38 by yann              #+#    #+#             */
/*   Updated: 2018/12/21 15:04:28 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// seg

#include "get_next_line.h"

int	return_good_line(char *result, int *position, char **line)
{
	int start;

	start = *position;
	// printf("start %d\n", start);
	while (result[*position] != '\0')
	{
		if (result[*position] == '\n')
		{
			*line = ft_strsub(result, start, *position - start);
			// printf("%s\n", *line);
			(*position)++;
			// printf("lA\n");		
			return(1);	
		}
		(*position)++;
		// printf("position %d\n", *position);
	}
	if (result[*position] == '\0')
		*line = ft_strsub(result, start, *position - start);
	if (start < *position)
	{
		*position = -123;	
		return(1);
	}
	*position = -123;
		// printf("lA\n");		
	return(0);
}

int		get_next_line(const int fd, char **line)
{
	static	char		*result;
	char				buf[BUFF_SIZE + 1];
	char				*temp;
	int					returnvalue;
	static	int			position = 0;

	//copie l'integralite dans result
	if (line == NULL || fd < 0)
		return (-1);
	
	// printf("fd = %zd/n", fd);
	// printf("ret = %zd/n", read(fd, buf, BUFF_SIZE));
	// printf("%zd\n",read(fd, buf, BUFF_SIZE));
	while ((returnvalue = read(fd, buf, BUFF_SIZE)) > 0)
	{	
		if (returnvalue == 0)
			return (0);
		buf[returnvalue]  = '\0';
		if (result == NULL)
			result = ft_strnew(1);
		temp = ft_strjoin(result, buf);
		ft_strdel(&result);
		result = temp;
		if (ft_strchr(buf, '\n') && ft_strchr(buf, '\0'))
			return(return_good_line(result, &position, line));
	}
	// printf("lA\n");
	if (returnvalue < 0)
		return (-1);
	//ajoutè position == 0 pour ne pas que ca segfault quand on envoi un fichier vide avec return = 0. mais ca fait foirrer 2 test basic test de 8 ligne sans \n
	else if (returnvalue == 0 && (position == -123 || position == 0))
		return (0);
	return(return_good_line(result, &position, line)); 
}

// int main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i = 0;

// 	// fd = open("../poeme.txt", O_RDONLY);
// 	fd = open("gnl-sample/m83.txt", O_RDONLY);
// 	while(i++ < 9)
// 	{
// 		get_next_line(fd, &line);
// 		printf("%s\n", line);
// 	}
// 	return 0;
// }