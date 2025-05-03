/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwolf <bwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:19:01 by bwolf             #+#    #+#             */
/*   Updated: 2024/02/14 15:51:25 by bwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	cb_check_file(char **config_file)
{
	if (!cb_check_textures(config_file))
	{
		printf("Error: wrong informations\n");
		return (false);
	}
	if (!cb_check_map(config_file))
	{
		printf("Error : wrong map\n");
		return (false);
	}
	return (true);
}

int	cb_check_textures(char **config_file)
{
	if (!cb_get_textures("NO", config_file))
		return (false);
	if (!cb_get_textures("SO", config_file))
		return (false);
	if (!cb_get_textures("EA", config_file))
		return (false);
	if (!cb_get_textures("WE", config_file))
		return (false);
	if (!cb_get_textures("F", config_file))
		return (false);
	if (!cb_get_textures("C", config_file))
		return (false);
	if (!cb_get_textures(NULL, config_file))
		return (false);
	if (!cb_verif_rgb("F", config_file) || !cb_verif_rgb("C", config_file))
		return (false);
	if (!cb_check_last_line(config_file))
		return (false);
	return (true);
}

int	cb_check_last_line(char **config_file)
{
	int		i;
	int		j;

	i = 0;
	while (config_file[i])
		i++;
	i--;
	j = -1;
	while (config_file[i][++j])
	{
		if (config_file[i][j] != ' ' && config_file[i][j] != '1')
			return (false);
	}
	return (true);
}

int	cb_check_map(char **config_file)
{
	int	i;

	i = cb_get_map(config_file);
	if (i == -1)
		cb_err_msg("Malloc failed");
	if (!config_file[i])
		return (false);
	if (!cb_parse_map(config_file, i))
		return (false);
	return (cb_one_player(config_file, i));
}

int	cb_check_char(char **config_file, int i)
{
	int	j;

	while (config_file[i])
	{
		j = 0;
		while (config_file[i][j])
		{
			if (config_file[i][j] != '0' && config_file[i][j] != '1'
				&& config_file[i][j] != 'N' && config_file[i][j] != 'S'
				&& config_file[i][j] != 'E' && config_file[i][j] != 'W'
				&& config_file[i][j] != '\n' && config_file[i][j] != ' ')
				return (printf("Error : Character unknown\n"), false);
			j++;
		}
		i++;
	}
	return (true);
}
