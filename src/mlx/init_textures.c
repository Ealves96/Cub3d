/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:50:58 by ealves            #+#    #+#             */
/*   Updated: 2024/02/14 14:24:25 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cb_images(t_game *game, char **config_file)
{
	if (!game->imgs)
		cb_create_bg(game);
	cb_create_wall_imgs(game, config_file, "NO", NORTH);
	cb_create_wall_imgs(game, config_file, "SO", SOUTH);
	cb_create_wall_imgs(game, config_file, "EA", EAST);
	cb_create_wall_imgs(game, config_file, "WE", WEST);
}

void	cb_create_bg(t_game *game)
{
	game->imgs = malloc(sizeof(*(game->imgs)));
	if (!game->imgs)
		cb_err_msg("Malloc_failed");
	game->imgs->next = NULL;
	game->imgs->text = malloc(sizeof(*(game->imgs->text)));
	if (!game->imgs->text)
		cb_err_msg("Malloc_failed");
	game->imgs->text->img = mlx_new_image(game->mlx, LARG, LONG);
	if (!game->imgs->text->img)
		cb_err_msg("Image not found");
	game->imgs->text->layout = mlx_get_data_addr(game->imgs->text->img, \
		&game->imgs->text->pixel_bits, &game->imgs->text->size_line,
			&game->imgs->text->endian);
	game->imgs->text->id = BACKGROUND;
}

void	cb_create_wall_imgs(t_game *game, char **config_file, char *str, int id)
{
	char	*path;

	path = cb_found_imgs_path(config_file, str);
	if (!path)
		cb_err_msg("Malloc_failed");
	cb_loading_imgs(game, path, id);
	free(path);
}

char	*cb_found_imgs_path(char **config_file, char *str)
{
	char	**line;
	char	*path;
	int		i;

	i = -1;
	path = NULL;
	while (config_file[++i])
	{
		line = ft_split(config_file[i], ' ');
		if (!line)
			return (NULL);
		if (!ft_strncmp(str, line[0], ft_strlen(line[0])))
		{
			path = ft_strdup(line[1]);
			if (!path)
				return (cb_free_lines(line), NULL);
			break ;
		}
		cb_free_lines(line);
	}
	cb_free_lines(line);
	return (path);
}

void	cb_loading_imgs(t_game *game, char *path, int id)
{
	t_imgs	*tmp;

	tmp = game->imgs;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = malloc(sizeof(*tmp));
	if (!tmp->next)
		cb_err_msg("Malloc_failed");
	tmp = tmp->next;
	tmp->next = NULL;
	tmp->text = malloc(sizeof(*(tmp->text)));
	if (!tmp->text)
		cb_err_msg("Malloc_failed");
	tmp->text->img = mlx_xpm_file_to_image(game->mlx, path, \
	&tmp->text->width, &tmp->text->height);
	tmp->text->id = id;
	tmp->text->layout = NULL;
	if (!tmp->text->img)
	{
		free(path);
		cb_err_msg("Image not found");
	}
	tmp->text->layout = mlx_get_data_addr(tmp->text->img,
			&tmp->text->pixel_bits, &tmp->text->size_line, &tmp->text->endian);
}
