/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_str_as_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:38:34 by shikwon           #+#    #+#             */
/*   Updated: 2023/12/02 17:14:56 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	save_str_as_file(char *s, char *file)
{
	int		fd;
	ssize_t	bytes_written;

	bytes_written = 0;
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	bytes_written = write(fd, s, ft_strlen(s));
	if (bytes_written == -1)
	{
		close(fd);
		return (2);
	}
	close(fd);
	return (0);
}
