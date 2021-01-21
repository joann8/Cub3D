# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacher <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 09:41:42 by jacher            #+#    #+#              #
#    Updated: 2021/01/14 22:51:30 by jacher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = main.c \
srcs/arguments_check.c \
srcs/error_mngt.c \
srcs/gl_player_move.c \
srcs/map_check_col_lin.c \
srcs/map_check_diag.c \
srcs/map_creation.c \
srcs/map_openandread.c \
srcs/map_parsing_main.c \
srcs/map_parsing_nsew.c \
srcs/map_parsing_rcf.c \
srcs/map_parsing_walls.c \
srcs/mlx_key_press.c \
srcs/mlx_main.c \
srcs/mlx_mini_map.c \
srcs/mlx_utils.c \
srcs/mlx_utils_bis.c \
srcs/print_support.c \
srcs/utils_algo.c \
srcs/utils_divers.c \
srcs/utils_struct.c \
srcs/utils_trigo.c  \
srcs/ray_main.c \
srcs/ray_casting.c \
srcs/ray_casting_hv.c \
srcs/ray_walls.c

OBJS = ${SRCS:.c=.o}

INC = -I includes/ -I libft/ -I ${MLX_DIR}
#./usr/include -I libft -I ${MLX_DIR}

CC = clang
RM = rm -f
FLAGS = -O3 -Wall -Werror -Wextra

MLX_DIR = ./minilibx-linux
MLX = ${MLX_DIR}/libmlx_Linux.a

LIBFT_DIR = ./libft
LIBFT = ${LIBFT_DIR}/libft.a

LIBS = -L ${LIBFT_DIR} -lft -L ${MLX_DIR} -lmlx -lXext -lX11 -lbsd -lm

.c.o: 
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} ${INC}

all: ${NAME}

${NAME}: ${LIBFT} ${MLX} ${OBJS} 
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
