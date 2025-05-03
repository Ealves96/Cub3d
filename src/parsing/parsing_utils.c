/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:26:20 by bwolf             #+#    #+#             */
/*   Updated: 2024/02/14 14:28:57 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**cb_init_cf(char *argv)
{
	int		fd;
	int		i;
	char	**config_file;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		cb_err_msg(argv);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	config_file = malloc(sizeof(*config_file) * (i + 1));
	if (!config_file)
		cb_err_msg("config_file : malloc failed");
	while (i > -1)
		config_file[i--] = NULL;
	return (config_file);
}

char	**cb_set_cf(char *argv)
{
	int		fd;
	int		i;
	char	**config_file;
	char	*line;

	config_file = cb_init_cf(argv);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		cb_free_lines(config_file);
		cb_err_msg(argv);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		cb_clean_cf(config_file, &i, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (config_file);
}

void	cb_clean_cf(char **config_file, int *i, char *line)
{
	char	*str;

	config_file[i[0]] = ft_strdup(line);
	if (!config_file[i[0]])
	{
		free(line);
		cb_free_lines(config_file);
		cb_err_msg("Malloc failed");
	}
	str = ft_strchr(config_file[i[0]], '\n');
	if (str)
		str[0] = '\0';
	i[0]++;
}

void	cb_unsplit(char **config_file, char **line, int i)
{
	char	*new_line;
	char	*tmp;
	int		j;

	j = -1;
	new_line = NULL;
	while (line[++j])
	{
		tmp = new_line;
		if (!j)
			new_line = ft_strjoin(line[j], " ");
		else
			new_line = ft_strjoin(new_line, line[j]);
		free(tmp);
		if (!new_line)
		{
			cb_free_lines(line);
			cb_err_msg("Malloc failed");
		}
	}
	tmp = config_file[i];
	config_file[i] = new_line;
	free(tmp);
}

int	cb_check_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
	}
	return (true);
}
