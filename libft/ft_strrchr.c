/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:18:41 by anouri            #+#    #+#             */
/*   Updated: 2023/10/14 19:49:57 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	my_c;
	char	*str;

	my_c = (char)c;
	str = (char *)s + ft_strlen((char *)s);
	while (str >= s)
	{
		if (*str == my_c)
			return (str);
		str--;
	}
	return (NULL);
}
