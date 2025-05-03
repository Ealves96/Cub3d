/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:50:01 by ealves            #+#    #+#             */
/*   Updated: 2024/02/12 21:54:17 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_text	*cb_select_text(t_imgs *imgs, int id)
{
	t_imgs	*tmp;

	tmp = imgs;
	while (tmp)
	{
		if (tmp->text->id == id)
			return (tmp->text);
		tmp = tmp->next;
	}
	return (NULL);
}

void	cb_process_graphic(t_game *game)
{
	cb_raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->imgs->text->img, 0, 0);
}

int	cb_graphic_render(void *game)
{
	static int	time_to_draw;

	time_to_draw = 0;
	if (!(time_to_draw % 1000))
		(cb_process_graphic((t_game *)game),
			mlx_do_sync(((t_game *)game)->mlx));
	time_to_draw++;
	if (time_to_draw == INT_MAX)
		time_to_draw = 0;
	return (EXIT_SUCCESS);
}

void	cb_paint_ceiling_floor(t_game *game, t_ray *ray, int x)
{
	int	y;
	int	*rgb;
	int	color;

	y = -1;
	rgb = game->rgb->ceiling_color;
	color = cb_rgb_int(rgb[0], rgb[1], rgb[2]);
	while (++y < ray->drawstart)
		cb_put_pxl(game, x * 1000 + y, color);
	rgb = game->rgb->floor_color;
	color = cb_rgb_int(rgb[0], rgb[1], rgb[2]);
	y = ray->drawend - 1;
	while (++y < LONG - 1)
		cb_put_pxl(game, x * 1000 + y, color);
}
