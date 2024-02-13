/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:11:28 by anouri            #+#    #+#             */
/*   Updated: 2024/01/31 11:36:40 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenGNL(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoinGNL(char *s1, char *s2)
{
	size_t	i;
	size_t	size;
	char	*res;

	size = ft_strlenGNL(s1) + ft_strlenGNL(s2);
	i = 0;
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	while (i < ft_strlenGNL(s1) || i < ft_strlenGNL(s2))
	{
		if (i < ft_strlenGNL(s1))
			res[i] = s1[i];
		if (i < ft_strlenGNL(s2))
			res[i + ft_strlenGNL(s1)] = s2[i];
		i++;
	}
	res[size] = '\0';
	return (res);
}
