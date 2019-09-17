/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:35:39 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/16 16:39:33 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strsort(char *str)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < ft_strlen(str))
	{
		j = 0;
		while (j < ft_strlen(str))
		{
			if (str[i] < str[j])
				ft_swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
}
