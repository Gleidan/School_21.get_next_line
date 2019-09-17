/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:17:53 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/13 14:46:09 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*temp1;
	const unsigned char *temp2;

	if (n == 0 || dst == src)
		return (dst);
	temp1 = (unsigned char *)dst;
	temp2 = (unsigned char *)src;
	while (n-- > 0)
	{
		*(temp1++) = *(temp2++);
	}
	return (dst);
}
