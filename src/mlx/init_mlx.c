/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:35:26 by ealves            #+#    #+#             */
/*   Updated: 2024/02/14 14:57:57 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_player	*cb_set_player(void)
{
	t_player	*play;

	play = malloc(sizeof(*play));
	if (!play)
		return (NULL);
	play->dir_x = 0;
	play->dir_y = 0;
	play->plane_x = 0;
	play->plane_y = 0;
	play->pos_x = 0;
	play->pos_y = 0;
	return (play);
}

static t_player	*cb_init_player(char **config_file)
{
	t_player	*play;

	play = cb_set_player();
	if (!play)
		return (NULL);
	play->pos_x = cb_player_pos_x(config_file);
	play->pos_y = cb_player_pos_y(config_file);
	play->dir_x = cb_start_orientation(config_file) / 10;
	play->dir_y = cb_start_orientation(config_file) % 10;
	cb_point_of_view(play);
	return (play);
}

void	cb_init_structs(t_game *game, char **config_file)
{
	game->imgs = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->play = NULL;
	game->rgb = NULL;
	game->rgb = cb_init_rgb(config_file);
	if (!game->rgb)
		cb_err_msg("Malloc failed");
	game->map = cb_init_map(config_file);
	if (!game->map)
		cb_err_msg("Malloc failed");
	game->play = cb_init_player(game->map);
	if (!game->play)
		cb_err_msg("Malloc failed");
	game->map[(int)(game->play->pos_x)][(int)(game->play->pos_y)] = '0';
}

t_rgb	*cb_init_rgb(char **config_file)
{
	t_rgb	*rgb;
	int		i;
	int		j;

	i = -1;
	j = 0;
	rgb = malloc(sizeof(*rgb));
	if (!rgb)
		return (NULL);
	rgb->ceiling_color = malloc(sizeof(int) * 3);
	if (!rgb->ceiling_color)
		return (free(rgb), NULL);
	rgb->floor_color = malloc(sizeof(int) * 3);
	if (!rgb->floor_color)
		return (free(rgb->ceiling_color), free(rgb), NULL);
	while (config_file[++i] && j < 2)
	{
		if (!ft_strncmp("F", config_file[i], 1)
			|| !ft_strncmp("C", config_file[i], 1))
		{
			cb_get_rgb_cf(config_file[i], rgb);
			j++;
		}
	}
	return (rgb);
}

char	**cb_init_map(char **config_file)
{
	char	**map;
	int		i;
	int		j;

	i = cb_get_map(config_file);
	if (i == -1)
		return (NULL);
	while (config_file[i])
		i++;
	map = malloc(sizeof(*map) * (i + 1));
	if (!map)
		return (NULL);
	while (i > -1)
		map[i--] = NULL;
	i = cb_get_map(config_file) - 1;
	if (i == -2)
		return (cb_free_lines(map), NULL);
	j = -1;
	while (config_file[++i])
	{
		map[++j] = ft_strdup(config_file[i]);
		if (!map[j])
			return (cb_free_lines(map), NULL);
	}
	return (map);
}
