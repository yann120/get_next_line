/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 09:29:34 by yann              #+#    #+#             */
/*   Updated: 2018/12/17 15:56:33 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_new_line(char **s, char **line, int fd, int ret)
{
	char 	*tmp;
	int 	len;

	len = 0;
	while (s[0][len] != '\n' && s[0][len] != '\0')
		len++;
	if (s[0][len] == '\n')
	{
		*line = ft_strsub(s[0], 0, len);
		tmp = ft_strdup(s[0] + len + 1);
		free(s[0]);
		s[0] = tmp;
		if (s[0][0] == '\0')
			ft_strdel(&s[0]);
	}
	else if (s[0][len] == '\0')
	{
		*line = ft_strdup(s[0]);
		ft_strdel(&s[0]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static 	char *s[1];
	int		ret;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL )
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[0] == NULL)
			s[0] = ft_strnew(1);
		tmp = ft_strjoin(s[0], buf);
		free(s[0]);
		s[0] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[0] == NULL || s[0][0] == '\0'))
		return (0);
	return(ft_new_line(s, line, fd, ret));
}