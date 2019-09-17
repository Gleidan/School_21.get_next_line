/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:50:25 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/11 13:57:50 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int len;
	unsigned int i;
	unsigned int j;

	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	if (!s[i])
		return (ft_strsub(s, i, 0));
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	if (!i && j == ft_strlen(s) - 1)
		return (ft_strdup(s));
	len = j - i;
	return (ft_strsub(s, i, len + 1));
}
