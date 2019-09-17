/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 09:45:29 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/13 17:08:26 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *temp;

	if (!alst || !del)
		return ;
	list = *alst;
	while (list)
	{
		temp = list;
		del(list->content, list->content_size);
		free(list);
		list = temp->next;
	}
	*alst = NULL;
}
