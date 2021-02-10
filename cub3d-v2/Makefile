# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacher <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 09:41:42 by jacher            #+#    #+#              #
#    Updated: 2021/02/10 12:43:01 by jacher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = main.c \
srcs/arguments_check.c \
srcs/error_mngt.c \
srcs/free_functions.c \
srcs/parsing_map_checkwalls.c \
srcs/parsing_map_create_str.c \
srcs/parsing_map_checkinputs.c \
srcs/parsing_map_create_tab.c \
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
srcs/print_support.c \
srcs/utils_divers.c \
srcs/utils_maths.c  \
srcs/struct_init.c \
srcs/struct_reset.c \
srcs/ray_main.c \
srcs/ray_casting.c \
srcs/ray_casting_hv.c \
srcs/ray_casting_sprite.c \
srcs/ray_walls.c \
srcs/bmp.c \
srcs/bmp_utils.c


OBJS = ${SRCS:.c=.o}

INC = -I includes/ -I libft/ -I ${MLX_DIR}
#./usr/include -I libft -I ${MLX_DIR}

CC = clang
RM = rm -f
FLAGS =  -Wall -Werror -Wextra

MLX_DIR = ./minilibx-linux
MLX = ${MLX_DIR}/libmlx_Linux.a
#MLX_DIR = ./minilibx_mac
#MLX = ${MLX_DIR}/libmlx.a


LIBFT_DIR = ./libft
LIBFT = ${LIBFT_DIR}/libft.a

LIBS = -L ${LIBFT_DIR} -lft -L ${MLX_DIR} -lmlx -lXext -lX11 -lbsd -lm
#LIBS = -L${LIBFT_DIR} -lft -L${MLX_DIR} -lmlx -framework AppKit -framework OpenGL -lm 

.c.o: 
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} ${INC}

all: ${NAME}

${NAME}: cub.h struct.h ${LIBFT} ${MLX} ${OBJS}  
	${CC} ${FLAGS} ${INC} ${OBJS} ${LIBS} -o ${NAME}		

${LIBFT}:
	@echo "Making libft"
	@${MAKE} bonus -C ${LIBFT_DIR}
	@echo "libft done!"

${MLX}:
	@echo "Making mlx"
	@${MAKE} -C ${MLX_DIR}
	@echo "mlx done!"

clean:
	${MAKE} -C ${LIBFT_DIR} clean
	${MAKE} -C ${MLX_DIR} clean
	${RM} ${OBJS} 

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY:		all clean fclean re 
