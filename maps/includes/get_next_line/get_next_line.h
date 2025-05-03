/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwolf <bwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:48:22 by bwolf             #+#    #+#             */
/*   Updated: 2024/01/16 17:56:49 by bwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000

# endif

# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 

int		ft_strlen_gnl(char *str);
int		ft_strchr_gnl(char *str, char c);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	clean_all(char *line, char *buffer);
char	*get_next_line(int fd);

#endif