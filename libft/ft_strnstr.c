/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:27:53 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/09 11:53:50 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	unsigned int i;
	unsigned int j;
	unsigned int size;

	size = ft_strlen(s2);
	if (!size)
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j]
				&& s2[j] && i + j < len)
			j++;
		if (j == size)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
