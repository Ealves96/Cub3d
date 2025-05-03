/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwolf <bwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:14:51 by bwolf             #+#    #+#             */
/*   Updated: 2024/02/14 13:24:51 by bwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cb_free_save(void)
{
	t_save	*save;

	save = cb_set_save();
	cb_free_lines(save->config_file);
	if (save->game)
	{
		cb_free_game(save->game);
		if (save->game->mlx)
			mlx_destroy_display(save->game->mlx);
		(free(save->game->mlx), free(save->game));
	}
	free(save);
	save = NULL;
}

void	cb_free_game(t_game *game)
{
	if (!game)
		return ;
	cb_free_lines(game->map);
	cb_free_rgb(game->rgb);
	free(game->play);
	if (game->mlx)
	{
		cb_free_imgs(game->mlx, game->imgs);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
	}
}

void	cb_free_rgb(t_rgb *rgb)
{
	if (!rgb)
		return ;
	free(rgb->ceiling_color);
	free(rgb->floor_color);
	free(rgb);
	rgb = NULL;
}

void	cb_free_imgs(void *mlx, t_imgs *imgs)
{
	t_imgs	*tmp;

	if (!imgs || !mlx)
		return ;
	while (imgs)
	{
		tmp = imgs->next;
		if (imgs->text && imgs->text->img)
			mlx_destroy_image(mlx, imgs->text->img);
		(free(imgs->text), free(imgs));
		imgs = tmp;
	}
}

void	cb_free_lines(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
