/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 09:50:09 by ypetitje          #+#    #+#             */
/*   Updated: 2018/12/20 17:09:54 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000
# include <stdio.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
#include <unistd.h>
#include <fcntl.h>

int get_next_line(const int fd, char **line);
int	return_good_line(char *result, int *position, char **line);

#endif