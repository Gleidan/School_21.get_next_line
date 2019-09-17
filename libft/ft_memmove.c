/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:29:57 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/13 14:50:22 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*temp1;
	const unsigned char *temp2;

	if (len == 0 || dst == src)
		return (dst);
	temp1 = (unsigned char *)dst;
	temp2 = (unsigned char *)src;
	i = 0;
	if (temp2 < temp1)
		while (++i <= len)
			temp1[len - i] = temp2[len - i];
	else
		while (len-- > 0)
			*(temp1++) = *(temp2++);
	return (dst);
}
