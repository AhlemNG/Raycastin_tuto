/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:17:29 by anouri            #+#    #+#             */
/*   Updated: 2022/11/30 14:05:54 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dt;
	char	*sr;
	size_t	i;

	i = 0;
	dt = (char *)dest;
	sr = (char *)src;
	if (dt == sr || n == 0)
		return (dest);
	if (dt > sr && dt - sr < (long int)n)
	{
		while (n-- > 0)
			dt[n] = sr[n];
		return (dest);
	}
	if (sr > dt && sr - dt < (long int)n)
	{
		while (i++ < n)
			dt[i - 1] = sr[i - 1];
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}
