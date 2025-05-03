/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwolf <bwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:47:55 by bwolf             #+#    #+#             */
/*   Updated: 2024/02/14 17:41:50 by bwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			been_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin_gnl(NULL, buffer);
	if (!line)
		return (NULL);
	been_read = 1;
	while (!ft_strchr_gnl(line, '\n') && been_read != 0)
	{
		been_read = read(fd, buffer, BUFFER_SIZE);
		if (been_read < 0)
			return (free(line), NULL);
		buffer[been_read] = '\0';
		line = ft_strjoin_gnl(line, buffer);
		if (!line)
			return (NULL);
	}
	if (!line[0])
		return (free(line), NULL);
	else
		clean_all(line, buffer);
	return (line);
}
