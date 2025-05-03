/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwolf <bwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:31:56 by bwolf             #+#    #+#             */
/*   Updated: 2024/02/13 20:07:57 by bwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_game	*cb_create_game(char **config_file)
{
	t_game	*game;
	t_save	*save;

	save = cb_set_save();
	game = malloc(sizeof(*game));
	if (!game)
		cb_err_msg("Malloc failed");
	save->game = game;
	cb_init_structs(game, config_file);
	game->mlx = mlx_init();
	if (!game->mlx)
		cb_err_msg("Failed mlx init");
	game->win = mlx_new_window(game->mlx, LARG, LONG, "Cub3D");
	if (!game->win)
		cb_err_msg("Failed create win");
	return (cb_images(game, config_file), game);
}

int	cb_verif_texture_name(char **config_file)
{
	int		i;
	char	**line;

	i = -1;
	while (config_file[++i])
	{
		line = ft_split(config_file[i], ' ');
		if (!line)
			cb_err_msg("malloc failed in line");
		if (ft_strlen(line[0]) > 0 && ft_strncmp(line[0], "NO", 2)
			&& ft_strncmp(line[0], "SO", 2) && ft_strncmp(line[0], "EA", 2)
			&& ft_strncmp(line[0], "WE", 2) && ft_strncmp(line[0], "F", 1)
			&& ft_strncmp(line[0], "C", 1) && ft_strncmp(line[0], "0", 1)
			&& ft_strncmp(line[0], "1", 1))
		{
			cb_free_lines(line);
			return (false);
		}
		cb_free_lines(line);
	}
	return (true);
}

t_game	*cb_parsing(char *argv)
{
	t_save	*save;
	char	**config_file;

	save = cb_set_save();
	config_file = cb_set_cf(argv);
	save->config_file = config_file;
	if (!cb_check_file(config_file))
		cb_err_msg(argv);
	return (cb_create_game(config_file));
}

int	cb_verif_empty_line(char **config_file, int i)
{
	int	j;

	while (config_file[i] && config_file[i][0] != '\0')
	{
		j = i;
		if (config_file[j][0] == '\n' && config_file[i][0] != '\0')
		{
			j++;
			if (config_file[j] && config_file[j][0] != '\n')
				return (false);
		}
		i++;
	}
	return (true);
}
