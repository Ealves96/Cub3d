/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:05:47 by bwolf             #+#    #+#             */
/*   Updated: 2024/02/14 14:39:17 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cb_rotate(t_player *play, double rotspeed)
{
	double	tmp;

	tmp = play->dir_x;
	play->dir_x = play->dir_x * cos(-rotspeed) - play->dir_y * sin(-rotspeed);
	play->dir_y = tmp * sin(-rotspeed) + play->dir_y * cos(-rotspeed);
	tmp = play->plane_x;
	play->plane_x = play->plane_x
		* cos(-rotspeed) - play->plane_y * sin(-rotspeed);
	play->plane_y = tmp * sin(-rotspeed) + play->plane_y * cos(-rotspeed);
}
