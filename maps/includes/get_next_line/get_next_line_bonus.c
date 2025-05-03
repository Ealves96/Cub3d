/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwolf <bwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:25:13 by bwolf             #+#    #+#             */
/*   Updated: 2023/02/09 19:29:42 by bwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;
	int			been_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	line = ft_strjoin(line, buffer[fd]);
	been_read = 1;
	while (!ft_strchr(line, '\n') && been_read != 0)
	{
		been_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (been_read < 0)
			return (free(line), NULL);
		buffer[fd][been_read] = '\0';
		line = ft_strjoin(line, buffer[fd]);
	}
	if (!line[0])
		return (free(line), NULL);
	else
		clean_all(line, buffer[fd]);
	return (line);
}
