/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:33:19 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/16 16:44:29 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_list_len(t_list *alst)
{
	size_t len;

	len = 0;
	if (alst)
		while (alst)
		{
			len++;
			alst = alst->next;
		}
	return (len);
}
