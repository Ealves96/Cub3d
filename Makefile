# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ealves <ealves@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 17:21:19 by ealves            #+#    #+#              #
#    Updated: 2024/02/14 15:05:18 by ealves           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

LIBFT			=	includes/libft/libft.a

GNL				=	includes/get_next_line/get_next_line.c \
					includes/get_next_line/get_next_line_utils.c

MLX				=	./mlx/libmlx.a

SRCS			=	./src/main.c \
					./src/free.c \
					./src/error.c \
					./src/parsing/parsing.c \
					./src/parsing/parsing_check.c \
					./src/parsing/parsing_map.c \
					./src/parsing/parsing_utils.c \
					./src/parsing/parsing_utils2.c \
					./src/parsing/parsing_get.c \
					./src/mlx/init_mlx.c \
					./src/mlx/init_textures.c \
					./src/mlx/keyboard_keys.c \
					./src/mlx/player_move.c \
					./src/mlx/player_pos.c \
					./src/mlx/player_rotate.c \
					./src/mlx/textures_pix.c \
					./src/mlx/raycasting.c \
					./src/mlx/raycasting_utils.c \
					./src/mlx/graphic_render.c


OBJS			=	${SRCS:.c=.o}

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I includes

CFLAGS			=	-Wall -Werror -Wextra -g3

all				:	${NAME}

$(NAME) : $(OBJS)
	@make -C includes/libft
	@make -C mlx
	cc $(OBJS) mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 ${LIBFT} ${GNL} -o $(NAME) -lm #-g3 -fsanitize=address

clean			:
					make clean -C includes/libft/
					rm -rf ${OBJS}

fclean			:	clean
					make fclean -C includes/libft/
					rm -rf ${LIBFT}
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
