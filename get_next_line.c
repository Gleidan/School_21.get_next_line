/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <jconcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 09:52:13 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/20 12:44:23 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		line_is_ready(char **stack, char **line)
{
	char	*temp;
	char	*str;
	int		i;

	i = 0;
	str = *stack;
	while (str[i] != '\n')
	{
		if (!str[i])
			return (0);
		i++;
	}
	temp = &str[i];
	*temp = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(temp + 1);
	free(str);
	return (1);
}

int		read_file(int fd, char *heap, char **stack, char **line)
{
	int		value;
	char	*temp;

	while ((value = read(fd, heap, BUFF_SIZE)) > 0)
	{
		heap[value] = '\0';
		if (*stack)
		{
			temp = *stack;
			*stack = ft_strjoin(temp, heap);
			free(temp);
			temp = NULL;
		}
		else
			*stack = ft_strdup(heap);
		if (line_is_ready(stack, line))
			break ;
	}
	return (value > 0 ? 1 : value);
}

int		get_next_line(const int fd, char **line)
{
	static char *stack[MAX_FD];
	char		*heap;
	int			counter;
	int			value;

	if ((fd < 0 || !line || fd >= MAX_FD) || (read(fd, stack[fd], 0) < 0)
		|| !(heap = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (stack[fd])
		if (line_is_ready(&stack[fd], line))
			return (1);
	counter = 0;
	while (counter < BUFF_SIZE)
		heap[counter++] = '\0';
	value = read_file(fd, heap, &stack[fd], line);
	free(heap);
	if (value != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		if (!value && *line)
			*line = NULL;
		return (value);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}
