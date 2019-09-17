/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:44:54 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/16 16:45:25 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_list(t_list *lst)
{
	t_list *temp;

	while (lst)
	{
		temp = lst->next;
		ft_memdel((void **)&lst);
		lst = temp;
	}
}
