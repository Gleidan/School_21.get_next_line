/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:43:20 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/12 13:17:19 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *t;

	t = NULL;
	while (*s)
	{
		if (*s == c)
			t = (char *)s;
		s++;
	}
	if (t)
		return (t);
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
