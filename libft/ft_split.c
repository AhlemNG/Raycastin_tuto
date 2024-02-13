/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:22:04 by anouri            #+#    #+#             */
/*   Updated: 2022/11/24 18:25:33 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (n);
}

static size_t	word_length(char const *s, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void	*free_new(char **s, size_t n)
{
	while (n > 0)
	{
		n--;
		free(s[n]);
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	nb_words;
	char	**new;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	nb_words = count_words(s, c);
	new = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!new)
		return (NULL);
	while (j < nb_words)
	{
		while (s[i] && s[i] == c)
			i++;
		new[j] = ft_substr(s, i, word_length(s, c, i));
		if (!new[j])
			return (free_new(new, j));
		i += word_length(s, c, i);
		j++;
	}
	new[j] = NULL ;
	return (new);
}
