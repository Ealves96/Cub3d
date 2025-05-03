/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:19:49 by bwolf             #+#    #+#             */
/*   Updated: 2024/02/14 15:36:01 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static unsigned int	cb_select_pxl(t_game *game, int id, int x, int y)
{
	char	*pixel_color;
	t_text	*text;

	text = cb_select_text(game->imgs, id);
	if (!text)
		return (0);
	pixel_color = text->layout
		+ (y * text->size_line + x * (text->pixel_bits / 8));
	return (*(unsigned int *)pixel_color);
}

void	cb_create_walls(t_game *game, t_ray *ray, int x)
{
	int	y;

	ray->step = 1.0 * IMG_SIZE / (ray->lineheight);
	ray->text_pos = (ray->drawstart - LONG / 2 + ray->lineheight / 2)
		* ray->step;
	y = ray->drawstart - 1;
	while (++y < ray->drawend)
	{
		ray->tex_y = (int)(ray->text_pos) & (IMG_SIZE - 1);
		ray->text_pos += ray->step;
		if (ray->side == 1 && ray->raydir_y < 0)
			cb_put_pxl(game, x * 1000 + y, cb_select_pxl(game, WEST,
					ray->tex_x, ray->tex_y));
		else if (ray->side == 0 && ray->raydir_x > 0)
			cb_put_pxl(game, x * 1000 + y, cb_select_pxl(game, SOUTH,
					ray->tex_x, ray->tex_y));
		else if (ray->side == 1 && ray->raydir_y > 0)
			cb_put_pxl(game, x * 1000 + y, cb_select_pxl(game, EAST, ray->tex_x,
					ray->tex_y));
		else if (ray->side == 0 && ray->raydir_x < 0)
			cb_put_pxl(game, x * 1000 + y, cb_select_pxl(game, NORTH,
					ray->tex_x, ray->tex_y));
	}
}

void	cb_calcul_line(t_ray *ray)
{
	ray->lineheight = (int)(LONG / ray->perpwalldist);
	ray->drawstart = -1 * ray->lineheight / 2 + LONG / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + LONG / 2;
	if (ray->drawend >= LONG)
		ray->drawend = LONG - 1;
}

void	cb_calcul_texture(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = ray->raypos_y + ray->perpwalldist * ray->raydir_y;
	else
		ray->wall_x = ray->raypos_x + ray->perpwalldist * ray->raydir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)((ray->wall_x) * (double)IMG_SIZE);
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->tex_x = IMG_SIZE - ray->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->tex_x = IMG_SIZE - ray->tex_x - 1;
}

void	cb_put_pxl(t_game *game, int coord, int color)
{
	char	*layout;
	t_text	*text;

	text = game->imgs->text;
	layout = text->layout;
	*(int *)&layout[(coord / 1000) * (text->pixel_bits / 8) + (coord % 1000)
		* text->size_line + 0] = color;
}
