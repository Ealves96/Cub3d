/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_pix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:49:47 by elie              #+#    #+#             */
/*   Updated: 2024/02/14 14:38:42 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cb_get_rgb_cf(char *str, t_rgb *rgb)
{
	char	**tab;
	char	**tab_bis;
	int		i;

	i = -1;
	tab = ft_split(str, ' ');
	if (!tab)
		return (cb_free_rgb(rgb));
	tab_bis = ft_split(tab[1], ',');
	if (!tab_bis)
		return (cb_free_lines(tab), cb_free_rgb(rgb));
	while (tab_bis[++i])
	{
		if (tab[0][0] == 'F')
			rgb->floor_color[i] = ft_atoi(tab_bis[i]);
		else
			rgb->ceiling_color[i] = ft_atoi(tab_bis[i]);
	}
	cb_free_lines(tab);
	cb_free_lines(tab_bis);
}

char	cb_blue(int color)
{
	return ((color & 0x0000FF));
}

char	cb_green(int color)
{
	return ((color & 0x00FF00) >> 8);
}

char	cb_red(int color)
{
	return ((color & 0xFF0000) >> 16);
}

int	cb_rgb_int(unsigned char r, unsigned char g, unsigned char b)
{
	int	color;

	color = r << 16;
	color |= g << 8 ;
	color |= b;
	return (color);
}
