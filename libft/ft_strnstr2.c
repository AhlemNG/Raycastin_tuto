/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:01:40 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/28 22:44:06 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnstr_tf(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*big_tmp;

	i = 0;
	j = 0;
	if (!big && !len)
		return (1);
	big_tmp = (char *)big;
	if (*little == 0)
		return (1);
	while (big_tmp[i] && len > 0)
	{
		j = 0;
		if (big_tmp[i] == little[j])
		{
			while (j < len && little[j] && big_tmp[i + j] == little[j])
				j++;
			if (little[j] == 0)
				return (0);
		}
		i++;
		len--;
	}
	return (1);
}
