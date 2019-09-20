/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 08:41:54 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/20 11:41:24 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 128
# define MAX_FD 256
# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"

int		get_next_line(const int fd, char **line);

#endif
