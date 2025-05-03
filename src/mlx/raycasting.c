/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwolf <bwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:06:05 by elie              #+#    #+#             */
/*   Updated: 2024/02/13 22:13:23 by bwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cb_raycasting(t_game *game)
{
	t_ray	*ray;
	int		i;

	i = -1;
	while (++i < LARG)
	{
		ray = cb_create_ray(game, i);
		cb_init_stepdist(ray);
		cb_dda(ray, game->map);
		cb_calcul_line(ray);
		cb_calcul_texture(ray);
		cb_create_walls(game, ray, i);
		cb_paint_ceiling_floor(game, ray, i);
		free(ray);
	}
}

void	cb_init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->raydir_x = 0;
	ray->raydir_y = 0;
	ray->raypos_x = 0;
	ray->raypos_y = 0;
	ray->raymap_x = 0;
	ray->raymap_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->step = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->lineheight = 0;
	ray->drawstart = 0;
	ray->drawend = 0;
	ray->perpwalldist = 0;
	ray->text_pos = 0;
	ray->tex_y = 0;
	ray->tex_x = 0;
	ray->hit = 0;
}

t_ray	*cb_create_ray(t_game *game, int i)
{
	t_ray		*ray;
	t_player	*play;

	play = game->play;
	ray = malloc(sizeof(*ray));
	if (!ray)
		cb_err_msg("Malloc failed");
	cb_init_ray(ray);
	ray->camera_x = 2 * i / (double)LARG - 1;
	ray->raydir_y = play->dir_y + play->plane_y * ray->camera_x;
	ray->raydir_x = play->dir_x + play->plane_x * ray->camera_x;
	ray->raypos_y = play->pos_y;
	ray->raypos_x = play->pos_x;
	ray->raymap_x = (int)(ray->raypos_x);
	ray->raymap_y = (int)(ray->raypos_y);
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
	return (ray);
}

void	cb_init_stepdist(t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (ray->raypos_x - ray->raymap_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->raymap_x + 1.0 - ray->raypos_x)
			* ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (ray->raypos_y - ray->raymap_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->raymap_y + 1.0 - ray->raypos_y)
			* ray->deltadist_y;
	}
}

void	cb_dda(t_ray *ray, char **map)
{
	float	safe;

	safe = -0.001;
	while (!ray->hit)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->raymap_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->raymap_y += ray->step_y;
			ray->side = 1;
		}
		if (map[ray->raymap_x][ray->raymap_y] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = (ray->sidedist_x - ray->deltadist_x) - safe;
	else
		ray->perpwalldist = (ray->sidedist_y - ray->deltadist_y) - safe;
}
