/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:28:10 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/17 12:47:30 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int				ft_fail(char **buffer, char **stock)
{
	ft_strdel(buffer);
	ft_strdel(stock);
	return (-1);
}

int				ft_end_of_file(char **line, char **stock, char **buffer)
{
	if (ft_strlen(*stock))
	{
		if (!(*line = ft_strdup(*stock)))
			return (ft_fail(buffer, stock));
		ft_strdel(stock);
		ft_strdel(buffer);
		return (1);
	}
	return (0);
}

unsigned int	ft_strchrpos(char *stock, char c)
{
	unsigned int i;

	i = 0;
	if (!stock)
		return (0);
	while (stock[i])
	{
		if (stock[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int				ft_realloc_box(char *temp, char **stock, char **buffer)
{
	ft_strdel(stock);
	if (!(*stock = ft_strdup(temp)))
		return (ft_fail(buffer, stock));
	ft_strdel(&temp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char *box = NULL;
	char		*buffer;
	char		*temp;
	int			i;

	if (fd < 0 || !line || BUFF_SIZE < 1 || BUFF_SIZE > 10000000)
		return (-1);
	box = (!box) ? ft_strnew(BUFF_SIZE) : box;
	while (!(ft_strchr(box, '\n')))
	{
		buffer = ft_strnew(BUFF_SIZE);
		if (!(i = read(fd, buffer, BUFF_SIZE)))
			return (ft_end_of_file(line, &box, &buffer));
		if (i == -1 || !box || !(temp = ft_strjoin(box, buffer)) ||
				ft_realloc_box(temp, &box, &buffer) == -1)
			return (ft_fail(&buffer, &box));
		ft_strdel(&buffer);
	}
	if (!(*line = ft_strsub(box, 0, ft_strchrpos(box, '\n'))))
		return (ft_fail(&buffer, &box));
	if (!(temp = ft_strsub(box, ft_strchrpos(box, '\n') + 1, ft_strlen(box))) ||
			ft_realloc_box(temp, &box, &buffer) == -1)
		return (ft_fail(&buffer, &box));
	return (1);
}
