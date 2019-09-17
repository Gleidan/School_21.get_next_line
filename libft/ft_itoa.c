/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:04:57 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/11 14:19:59 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		i++;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	unsigned int	number;

	len = ft_intlen(n);
	number = (n < 0) ? -n : n;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = number % 10 + '0';
	while (number /= 10)
		str[--len] = number % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
