/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwolf <bwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:10:18 by ealves            #+#    #+#             */
/*   Updated: 2024/02/12 14:22:16 by bwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	cb_player_pos_x(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S')
				return ((double)i + 0.5);
			if (map[i][j] == 'E' || map[i][j] == 'W')
				return ((double)i + 0.5);
		}
	}
	return (-1);
}

double	cb_player_pos_y(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S')
				return ((double)j + 0.5);
			if (map[i][j] == 'E' || map[i][j] == 'W')
				return ((double)j + 0.5);
		}
	}
	return (-1);
}

int	cb_start_orientation(char **config_file)
{
	int		i;
	int		j;

	i = -1;
	while (config_file[++i])
	{
		j = -1;
		while (config_file[i][++j])
		{
			if (config_file[i][j] == 'N')
				return (-10);
			else if (config_file[i][j] == 'E')
				return (01);
			else if (config_file[i][j] == 'W')
				return (-01);
			else if (config_file[i][j] == 'S')
				return (10);
		}
	}
	return (-1);
}

void	cb_point_of_view(t_player *play)
{
	if (!play->dir_x)
	{
		play->plane_y = 0;
		if (play->dir_y > 0)
			play->plane_x = DEGREE / 100.0;
		else
			play->plane_x = -DEGREE / 100.0;
	}
	else
	{
		play->plane_x = 0;
		if (play->dir_x > 0)
			play->plane_y = -DEGREE / 100.0;
		else
			play->plane_y = DEGREE / 100.0;
	}
}
