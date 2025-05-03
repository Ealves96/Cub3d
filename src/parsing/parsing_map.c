/* ************************************************************************** */
/*			                                                                  */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:17:45 by ealves            #+#    #+#             */
/*   Updated: 2024/01/24 12:27:32 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	cb_parse_map(char **config_file, int i)
{
	int	start;

	start = i;
	while (config_file[i])
		i++;
	if (!cb_verif_empty_line(config_file, start))
		return (false);
	if (!cb_check_char(config_file, start))
		return (false);
	if (!cb_verif_wall_h(config_file, start, i - 1))
		return (false);
	if (!cb_verif_wall_v(config_file, start))
		return (false);
	return (cb_check_path(config_file, start, i - 1));
}

//verifie les extremes horizontaux
int	cb_verif_wall_h(char **config_file, int start, int end)
{
	int	i;

	i = -1;
	while (config_file[start][++i])
	{
		if (config_file[start][i] != ' ' && config_file[start][i] != '1')
			return (false);
	}
	i = -1;
	while (config_file[end][++i])
	{
		if (config_file[end][i] != ' ' && config_file[end][i] != '1')
			return (false);
	}
	return (true);
}

//verifie les extremes verticaux
int	cb_verif_wall_v(char **config_file, int start)
{
	int		i;
	char	*str;
	char	*strbis;

	i = start - 1;
	while (config_file[++i])
	{
		str = ft_strchr(config_file[i], '1');
		strbis = ft_strchr(config_file[i], '0');
		if (strbis && strbis < str)
			return (false);
		if (!config_file[i][0])
			return (false);
		if (config_file[i][ft_strlen(config_file[i]) - 1] != '1'
			&& config_file[i][ft_strlen(config_file[i]) - 1] != ' ')
			return (false);
	}
	return (true);
}

int	cb_check_holes(char **config_file, int i, int j)
{
	int	len;

	len = ft_strlen(config_file[i - 1]);
	if (len < j - 1 || len < j || len < j + 1)
		return (false);
	len = ft_strlen(config_file[i]);
	if (len < j - 1 || len < j || len < j + 1)
		return (false);
	len = ft_strlen(config_file[i + 1]);
	if (len < j - 1 || len < j || len < j + 1)
		return (false);
	if (config_file[i - 1][j] == ' ' ||
		config_file[i][j - 1] == ' ' ||
		config_file[i][j] == ' ' || config_file[i][j + 1] == ' ' ||
		config_file[i + 1][j] == ' ')
		return (false);
	return (true);
}

int	cb_check_path(char **config_file, int start, int end)
{
	int	i;
	int	j;

	i = start;
	while (++i != end)
	{
		j = -1;
		while (config_file[i][++j])
		{
			if (config_file[i][j] == '0' || config_file[i][j] == 'N'
				|| config_file[i][j] == 'S' || config_file[i][j] == 'E'
				|| config_file[i][j] == 'W')
			{
				if (!cb_check_holes(config_file, i, j))
					return (false);
			}
		}
	}
	return (true);
}
