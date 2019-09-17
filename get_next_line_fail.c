/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 08:43:34 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/17 11:20:26 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char *box[2147483647];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	ssize_t		i;
	int			endl;

	if (fd < 0 || (!box[fd] && !(box[fd] = ft_strnew(1))) || !line)
		return (-1);
	while (!ft_strchr(box[fd], '\n') && (i = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[i] = '\0';
		temp = box[fd];
		box[fd] = ft_strjoin(box[fd], buffer);
		ft_strdel(&temp);
	}
	if (i == -1 || !*(temp = box[fd]))
		return (i = -1 ? -1 : 0);
	if ((endl = (ft_strchr(box[fd], '\n') > 0)))
		*line = ft_strsub(box[fd], 0, ft_strchr(box[fd], '\n') - box[fd]);
	else
		*line = ft_strdup(box[fd]);
	box[fd] = ft_strsub(box[fd], (unsigned int)(ft_strlen(*line) + endl),
			(size_t)(ft_strlen(box[fd]) - (ft_strlen(*line) + endl)));
	ft_strdel(&temp);
	return (!(!box[fd] && !ft_strlen(*line)));
}
