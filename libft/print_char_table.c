/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:10:05 by anouri            #+#    #+#             */
/*   Updated: 2024/02/13 10:39:56 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_char_table(char **tab)
{
	ft_putstr_fd("\n",1);
	if (tab)
	{
		while (*tab)
			ft_putstr_fd(*tab++, 1);
			// printf("%s", *tab++);
		// ft_putstr_fd("\n----------------------- seperation end of map ---------------------\n\n", 1);
	}
}
