/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:02:21 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/13 10:04:22 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **begin_list, t_list *new)
{
	t_list *temp;

	if (!*begin_list)
		*begin_list = new;
	else
	{
		temp = *begin_list;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
