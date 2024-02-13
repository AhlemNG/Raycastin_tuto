/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:33:11 by anouri            #+#    #+#             */
/*   Updated: 2022/11/29 18:28:36 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	if ((!dst || !src) && (size == 0))
		return (0);
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen || size == 0)
		return (size + srclen);
	i = 0;
	while ((src[i] != '\0') && size - 1 > dstlen + i)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if (size > i)
		dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
