/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:03:38 by anouri            #+#    #+#             */
/*   Updated: 2022/11/24 10:31:12 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dt;
	const char	*sr;
	size_t		i;

	i = 0;
	dt = (char *)dest;
	sr = (const char *)src;
	if (!dt && !sr)
		return (NULL);
	while (i < n)
	{
		dt[i] = sr[i];
		i++;
	}
	return ((void *)dest);
}
