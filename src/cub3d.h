/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:17:17 by ealves            #+#    #+#             */
/*   Updated: 2024/02/14 14:56:51 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../includes/get_next_line/get_next_line.h"
# include "../includes/libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define LARG 1280
# define LONG 720

# define IMG_SIZE 64

# define MOVESPEED 0.1
# define ROTSPEED 0.05
# define DEGREE 60

# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4
# define BACKGROUND 5

# define ESPACE "                                                             \n"

typedef struct s_rgb
{
	int			*floor_color;
	int			*ceiling_color;
}				t_rgb;

typedef struct s_text
{
	void		*img;
	char		*layout;
	int			height;
	int			width;
	int			pixel_bits;
	int			size_line;
	int			endian;
	int			id;
}				t_text;

typedef struct s_imgs
{
	struct s_text	*text;
	struct s_imgs	*next;
}					t_imgs;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_y;
	double		dir_x;
	double		plane_y;
	double		plane_x;
}				t_player;

typedef struct s_ray
{
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		raypos_x;
	double		raypos_y;
	int			raymap_x;
	int			raymap_y;
	int			step_x;
	int			step_y;
	double		step;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		wall_dist;
	double		wall_x;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		perpwalldist;
	double		text_pos;
	int			tex_y;
	int			tex_x;
	bool		hit;
}				t_ray;

typedef struct s_game
{
	char		**map;
	void		*mlx;
	void		*win;
	t_rgb		*rgb;
	t_player	*play;
	t_imgs		*imgs;
}				t_game;

typedef struct s_save
{
	t_game		*game;
	char		**config_file;
}				t_save;

///// GRAPHIC_RENDER.C /////
t_text	*cb_select_text(t_imgs *imgs, int id);
void	cb_process_graphic(t_game *game);
int		cb_graphic_render(void *game);
void	cb_paint_ceiling_floor(t_game *game, t_ray *ray, int x);

///// INIT_MLX.C //////
void	cb_init_structs(t_game *game, char **config_file);
char	**cb_init_map(char **config_file);
t_rgb	*cb_init_rgb(char **config_file);

///// INIT_TEXTURES.C /////
void	cb_images(t_game *game, char **config_file);
void	cb_create_bg(t_game *game);
void	cb_create_wall_imgs(t_game *game, char **config_file,
			char *str, int id);
char	*cb_found_imgs_path(char **config_file, char *str);
void	cb_loading_imgs(t_game *game, char *path, int id);

///// KEYBOARD_KEYSS.C /////
int		cb_close_game(t_game *game);
void	cb_key_press(t_game *game, int keycode);
int		cb_key_hook(int keycode, t_game *game);

///// PLAYER_MOVE.C /////
void	cb_move_forward(t_player *play, char **map);
void	cb_move_left(t_player *play, char **map);
void	cb_move_right(t_player *play, char **map);
void	cb_move_back(t_player *play, char **map);

///// PLAYER_POS.C /////
double	cb_player_pos_x(char **map);
double	cb_player_pos_y(char **map);
int		cb_start_orientation(char **config_file);
void	cb_point_of_view(t_player *play);

///// PLAYER_ROTATE.C /////
void	cb_rotate(t_player *play, double rotspeed);

///// RAYCASTING_UTILS.C /////
void	cb_create_walls(t_game *game, t_ray *ray, int x);
void	cb_calcul_line(t_ray *ray);
void	cb_calcul_texture(t_ray *ray);
void	cb_put_pxl(t_game *game, int coord, int color);

///// RAYCASTING.C /////
void	cb_raycasting(t_game *game);
void	cb_init_ray(t_ray *ray);
t_ray	*cb_create_ray(t_game *game, int i);
void	cb_init_stepdist(t_ray *ray);
void	cb_dda(t_ray *ray, char **map);

///// TEXTURES_PIX.C /////
void	cb_get_rgb_cf(char *str, t_rgb *rgb);
char	cb_blue(int color);
char	cb_green(int color);
char	cb_red(int color);
int		cb_rgb_int(unsigned char b, unsigned char g, unsigned char r);

///// PARSING_CHECK.C /////
int		cb_check_file(char **config_file);
int		cb_check_textures(char **config_file);
int		cb_check_last_line(char **config_file);
int		cb_check_map(char **config_file);
int		cb_check_char(char **config_file, int i);

///// PARSING_GET.C /////
int		cb_get_map(char **config_file);
int		cb_get_textures(char *str, char **config_file);

///// PARSING_MAP.C /////
int		cb_parse_map(char **config_file, int i);
int		cb_verif_wall_h(char **config_file, int start, int end);
int		cb_verif_wall_v(char **config_file, int start);
int		cb_check_holes(char **config_file, int i, int j);
int		cb_check_path(char **config_file, int start, int end);

///// PARSING_UTILS.C /////
char	**cb_init_cf(char *argv);
char	**cb_set_cf(char *argv);
void	cb_clean_cf(char **config_file, int *i, char *line);
void	cb_unsplit(char **config_file, char **line, int i);
int		cb_check_digit(char *str);

///// PARSING_UTILS2.C /////
int		cb_check_digit_tab(char **str);
int		cb_one_player(char **config_file, int i);
int		cb_verif_rgb(char *str, char **config_file);
int		cb_verif_rgb2(char **str);
int		cb_verif_fc(char **line, char *str, int *txt);

///// PARSING.C /////
t_game	*cb_create_game(char **config_file);
int		cb_verif_texture_name(char **config_file);
t_game	*cb_parsing(char *argv);
int		cb_verif_empty_line(char **config_file, int i);

///// ERROR.C /////
void	cb_err_msg(char *msg);

///// FREE.C /////
void	cb_free_save(void);
void	cb_free_game(t_game *game);
void	cb_free_rgb(t_rgb *rgb);
void	cb_free_imgs(void *mlx, t_imgs *imgs);
void	cb_free_lines(char **str);

///// MAIN.C /////
int		cb_verif_extension(char *argv);
t_save	*cb_set_save(void);

#endif
