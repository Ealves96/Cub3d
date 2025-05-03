/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwolf <bwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:33:24 by bwolf             #+#    #+#             */
/*   Updated: 2024/02/13 17:19:13 by bwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	cb_check_digit_tab(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!cb_check_digit(str[i]))
			return (false);
	}
	return (true);
}

int	cb_one_player(char **config_file, int i)
{
	static int	n = 0;
	static int	s = 0;
	static int	e = 0;
	static int	w = 0;
	int			j;

	i--;
	while (config_file[++i])
	{
		j = -1;
		while (config_file[i][++j])
		{
			if (config_file[i][j] == 'N')
				n++;
			else if (config_file[i][j] == 'S')
				s++;
			else if (config_file[i][j] == 'E')
				e++;
			else if (config_file[i][j] == 'W')
				w++;
		}
	}
	return (n + s + e + w == 1);
}

int	cb_verif_rgb(char *str, char **config_file)
{
	int		i;
	char	**line;

	i = -1;
	while (config_file[++i])
	{
		line = ft_split(config_file[i], ' ');
		if (!line)
			cb_err_msg("Malloc failed");
		if (!ft_strncmp(line[0], str, ft_strlen(str)))
		{
			cb_unsplit(config_file, line, i);
			cb_free_lines(line);
			line = ft_split(config_file[i], ' ');
			if (!line)
				cb_err_msg("Malloc failed");
			if (!cb_verif_rgb2(line))
				return (false);
		}
		cb_free_lines(line);
	}
	return (true);
}

int	cb_verif_rgb2(char **str)
{
	char	**line;
	int		i;

	i = -1;
	if (!str[1])
		return (cb_free_lines(str), false);
	line = ft_split(str[1], ',');
	if (!line)
		(cb_free_lines(str), cb_err_msg("Malloc failed"));
	while (line[++i])
	{
		if (!(ft_strlen(line[i]) > 0 && ft_strlen(line[i]) < 4))
			return (cb_free_lines(str), cb_free_lines(line), false);
		if (!cb_check_digit(line[i]))
			return (cb_free_lines(str), cb_free_lines(line), false);
		if (!(ft_atoi(line[i]) > -1 && ft_atoi(line[i]) < 256))
			return (cb_free_lines(str), cb_free_lines(line), false);
	}
	if (i != 3)
		return (cb_free_lines(str), cb_free_lines(line), false);
	return (cb_free_lines(line), true);
}

int	cb_verif_fc(char **line, char *str, int *txt)
{
	int	fd;

	if (!*(str + 1) && (*str == 'F' || *str == 'C'))
	{
		txt[0]++;
		return (true);
	}
	if (line[1] && ft_strlen(str) == ft_strlen(line[0]) && !line[2])
	{
		txt[0]++;
		if (ft_strlen(str) == 2)
		{
			fd = open(line[1], O_RDONLY);
			if (fd == -1)
				return (false);
			close (fd);
		}
	}
	else
		return (false);
	return (true);
}
