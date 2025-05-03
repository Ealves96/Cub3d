/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:01:56 by ealves            #+#    #+#             */
/*   Updated: 2024/02/12 21:41:20 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cb_move_forward(t_player *play, char **map)
{
	int	i;
	int	j;

	i = (int)play->pos_x;
	j = (int)(play->pos_y + play->dir_y * MOVESPEED);
	if (map[i][j] == '0')
		play->pos_y += play->dir_y * MOVESPEED;
	i = (int)(play->pos_x + play->dir_x * MOVESPEED);
	j = (int)play->pos_y;
	if (map[i][j] == '0')
		play->pos_x += play->dir_x * MOVESPEED;
}

void	cb_move_left(t_player *play, char **map)
{
	int	i;
	int	j;

	i = (int)(play->pos_x - play->plane_x * MOVESPEED);
	j = (int)play->pos_y;
	if (map[i][j] == '0')
		play->pos_x -= play->plane_x * MOVESPEED;
	i = (int)play->pos_x;
	j = (int)(play->pos_y - play->plane_y * MOVESPEED);
	if (map[i][j] == '0')
		play->pos_y -= play->plane_y * MOVESPEED;
}

void	cb_move_right(t_player *play, char **map)
{
	int	i;
	int	j;

	i = (int)(play->pos_x + play->plane_x * MOVESPEED);
	j = (int)play->pos_y;
	if (map[i][j] == '0')
		play->pos_x += play->plane_x * MOVESPEED;
	i = (int)play->pos_x;
	j = (int)(play->pos_y + play->plane_y * MOVESPEED);
	if (map[i][j] == '0')
		play->pos_y += play->plane_y * MOVESPEED;
}

void	cb_move_back(t_player *play, char **map)
{
	int	i;
	int	j;

	i = (int)play->pos_x;
	j = (int)(play->pos_y - play->dir_y * MOVESPEED);
	if (map[i][j] == '0')
		play->pos_y -= play->dir_y * MOVESPEED;
	i = (int)(play->pos_x - play-> dir_x * MOVESPEED);
	j = (int)play->pos_y;
	if (map[i][j] == '0')
		play->pos_x -= play-> dir_x * MOVESPEED;
}
