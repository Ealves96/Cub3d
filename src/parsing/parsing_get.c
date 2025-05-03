/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:20:21 by bwolf             #+#    #+#             */
/*   Updated: 2024/02/14 14:43:22 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	cb_get_map(char **config_file)
{
	int		i;
	char	**clean_line;

	i = -1;
	clean_line = NULL;
	while (config_file[++i])
	{
		if (ft_strchr(config_file[i], '1'))
		{
			clean_line = ft_split(config_file[i], ' ');
			if (!clean_line)
				return (-1);
			if (cb_check_digit_tab(clean_line))
				break ;
			cb_free_lines(clean_line);
			clean_line = NULL;
		}
	}
	cb_free_lines(clean_line);
	return (i);
}

int	cb_get_textures(char *str, char **config_file)
{
	int		i;
	int		txt;
	char	**line;

	i = -1;
	txt = 0;
	if (!str)
		return (cb_verif_texture_name(config_file));
	while (config_file[++i])
	{
		line = ft_split(config_file[i], ' ');
		if (!line)
			cb_err_msg("Malloc failed on line");
		if (!ft_strncmp(line[0], str, ft_strlen(line[0])))
		{
			if (!cb_verif_fc(line, str, &txt))
			{
				cb_free_lines(line);
				return (false);
			}
		}
		cb_free_lines(line);
	}
	return (txt == 1);
}
