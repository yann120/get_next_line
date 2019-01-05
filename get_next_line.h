/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 09:50:09 by ypetitje          #+#    #+#             */
/*   Updated: 2018/12/20 18:36:36 by ypetitje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10
#define ENDL '\n'
# include <stdio.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

int get_next_line(const int fd, char **line);
int	return_good_line(char *result, int *position, char **line);

#endif