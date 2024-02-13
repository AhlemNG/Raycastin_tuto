/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:28:35 by anouri            #+#    #+#             */
/*   Updated: 2022/11/28 15:29:26 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lend(long int n)
{
	int	len;

	len = 1;
	if (n < 0)
		n = -n;
	while (n / 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	int_to_char(long int n, char *s, int i)
{
	while (i > 0)
	{
		s[i--] = (n % 10) + 48;
		n = n / 10;
	}
}

static void	int_to_char2(long int n, char *s, int i)
{
	while (i >= 0)
	{
		s[i--] = (n % 10) + 48;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	long int	m;
	char		*new;
	int			len;
	int			i;

	m = (long int)n;
	len = lend(n);
	i = len;
	if (m < 0)
		len += 1;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	if (m < 0)
	{
		new[0] = '-';
		int_to_char((-m), new, i);
		new[len] = '\0';
	}
	else
	{
		int_to_char2(m, new, i - 1);
		new[len] = '\0';
	}
	return (new);
}
