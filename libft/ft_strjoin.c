/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:18:54 by anouri            #+#    #+#             */
/*   Updated: 2022/11/24 16:41:20 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const char	*s11;
	const char	*s22;
	char		*new;
	size_t		len;

	if (!s1)
		return (NULL);
	s11 = (const char *)s1;
	s22 = (const char *)s2;
	len = ft_strlen(s11) + ft_strlen(s22);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s11, (ft_strlen(s11) + 1));
	ft_strlcat(new, (const char *)s22, (len + 1));
	return (new);
}
