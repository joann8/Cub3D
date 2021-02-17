# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacher <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 09:41:42 by jacher            #+#    #+#              #
#    Updated: 2021/02/12 15:09:21 by jacher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = main.c \
srcs/arguments_check.c \
srcs/error_mngt.c \
srcs/free_functions.c \
srcs/parsing_create_maptab_utils.c \
srcs/parsing_create_mapstr.c \
srcs/parsing_map_col.c \
srcs/parsing_map_lin.c \
srcs/parsing_create_maptab.c \
srcs/parsing_main.c \
srcs/parsing_textures.c \
srcs/parsing_rcf.c \
srcs/parsing_map.c \
srcs/parsing_utils.c \
srcs/parsing_sprite.c \
srcs/mlx_events.c \
srcs/mlx_main.c \
srcs/mlx_player_move.c \
srcs/mlx_textures.c \
srcs/mlx_utils.c \
srcs/utils_divers.c \
srcs/utils_maths.c  \
srcs/struct_init.c \
srcs/struct_reset.c \
srcs/ray_main.c \
srcs/ray_casting.c \
srcs/ray_casting_hv.c \
srcs/ray_sprite.c \
srcs/ray_walls.c \
srcs/bmp.c \
srcs/bmp_utils.c \
srcs/mlx_minimap.c

OBJS = ${SRCS:.c=.o}
CC = clang
RM = rm -f
FLAGS = -Wall -Werror -Wextra 

MLX = ./minilibx-linux/libmlx.a
LIBFT = ./libft/libft.a

LIBS_FLAGS = -L ./libft -L ./minilibx-linux/
LIBS = -lft -lmlx -lXext -lX11 -lm

INC = -I libft/ -I minilibx-linux/  -I cub.h  -I struct.h

.c.o: ${LIBFT} ${MLX} cub.h struct.h 
	${CC} ${FLAGS} ${INC} -c $< -o ${<:.c=.o} 

all: ${NAME}

${NAME}: ${LIBFT} ${MLX} ${OBJS} cub.h struct.h  
	${CC} ${FLAGS} ${LIBS_FLAGS} ${OBJS} -o ${NAME}	${LIBS}	

${LIBFT}:
	make bonus -C ./libft/

${MLX}:
	make -C ./minilibx-linux/

clean:
	make clean -C ./libft/
	make clean -C ./minilibx-linux/
	${RM} ${OBJS} 

fclean:	clean
	make fclean -C ./libft/
	${RM} ${NAME}

re: fclean all

bonus: all

.PHONY:		all clean fclean re 
