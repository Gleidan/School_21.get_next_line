/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 09:54:40 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/16 16:42:08 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *first;

	tmp = ft_lstnew(lst->content, lst->content_size);
	if (!tmp || !f)
		return (NULL);
	tmp = (*f)(tmp);
	first = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = ft_lstnew(lst->content, lst->content_size);
		if (tmp->next == NULL)
		{
			ft_clear_list(first);
			return (NULL);
		}
		tmp->next = (*f)(tmp->next);
		tmp = tmp->next;
	}
	return (first);
}
