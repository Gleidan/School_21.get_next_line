/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:26:18 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/16 16:45:58 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t			i;
	unsigned long	res;
	unsigned long	overflow;
	int				sign;

	i = 0;
	res = 0;
	overflow = 9223372036854775807;
	while (ft_isspace(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if ((res > overflow || (res == overflow && (str[i] - '0') > 7))
				&& sign == 1)
			return (-1);
		else if ((res > overflow || (res == overflow && (str[i] - '0') > 8))
				&& sign == -1)
			return (0);
		res = res * 10 + (str[i++] - '0');
	}
	return ((int)(res * sign));
}
