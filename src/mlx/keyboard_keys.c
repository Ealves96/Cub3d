/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:39:40 by ealves            #+#    #+#             */
/*   Updated: 2024/02/14 14:39:07 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	cb_close_game(t_game *game)
{
	return (mlx_loop_end(game->mlx), EXIT_SUCCESS);
}

void	cb_key_press(t_game *game, int keycode)
{
	if (keycode == XK_w)
		cb_move_forward(game->play, game->map);
	if (keycode == XK_a)
		cb_move_left(game->play, game->map);
	if (keycode == XK_d)
		cb_move_right(game->play, game->map);
	if (keycode == XK_s)
		cb_move_back(game->play, game->map);
	if (keycode == XK_Left)
		cb_rotate(game->play, -1 * ROTSPEED);
	if (keycode == XK_Right)
		cb_rotate(game->play, ROTSPEED);
}

int	cb_key_hook(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		return (cb_close_game(game));
	cb_key_press(game, keycode);
	(cb_process_graphic((t_game *)game), mlx_do_sync(((t_game *)game)->mlx));
	return (EXIT_SUCCESS);
}
