/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:29:07 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/16 16:59:42 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_split_creator(char const *s, char c,
						int word_count, int max_word_len)
{
	char	**sp_s;
	int		i;
	int		j;
	int		k;

	if (!(sp_s = (char **)malloc(sizeof(*sp_s) * word_count + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			if (!(sp_s[j] = (char *)malloc(sizeof(**sp_s) * max_word_len + 1)))
				return (ft_clear_table(sp_s, j));
			while (s[i] != c && s[i])
				sp_s[j][k++] = s[i++];
			sp_s[j++][k] = '\0';
		}
	}
	sp_s[j] = 0;
	return (sp_s);
}

char			**ft_strsplit(char const *s, char c)
{
	int word_count;
	int word_len;
	int max_word_len;
	int i;

	if (!s || !c)
		return (NULL);
	i = 0;
	word_count = 0;
	max_word_len = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			word_count++;
			word_len = 0;
			while (s[i] != c && s[i++])
				word_len++;
			if (word_len > max_word_len)
				max_word_len = word_len;
		}
	}
	return (ft_split_creator(s, c, word_count, max_word_len));
}
