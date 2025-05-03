/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:17:22 by ealves            #+#    #+#             */
/*   Updated: 2024/02/14 14:39:38 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cb_verif_extension(char *argv)
{
	int	i;

	i = 0;
	if (ft_strlen(argv) < 5)
		return (false);
	while (argv[i])
		i++;
	i--;
	if (argv[i - 4] != '\'' && argv[i - 3] == '.' && argv[i - 2] == 'c')
		if (argv[i - 1] == 'u' && argv[i] == 'b')
			return (true);
	return (false);
}

t_save	*cb_set_save(void)
{
	static t_save	*save = NULL;

	if (!save)
	{
		save = malloc(sizeof(*save));
		if (!save)
			(printf("Error: malloc failed"), exit(EXIT_FAILURE));
		save->config_file = NULL;
		save->game = NULL;
	}
	return (save);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		cb_err_msg("wrong parameters");
	if (!cb_verif_extension(argv[1]))
		cb_err_msg("extension problem");
	game = cb_parsing(argv[1]);
	mlx_loop_hook(game->mlx, &cb_graphic_render, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &cb_key_hook, game);
	mlx_hook(game->win, ClientMessage, StructureNotifyMask, &cb_close_game,
		game);
	mlx_loop(game->mlx);
	return (cb_free_save(), EXIT_SUCCESS);
}
