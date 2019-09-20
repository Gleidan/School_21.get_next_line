/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:55:39 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/16 17:04:05 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_clear_table(char **array, int i)
{
	int n;

	n = 0;
	while (n < i)
		free(array[n++]);
	free(array);
	return (0);
}
