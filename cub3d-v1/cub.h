/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:29:46 by jacher            #+#    #+#             */
/*   Updated: 2021/01/20 14:43:01 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H

# define CUB_H


//#define PI 3.14159265358979323846

#include "struct.h"
#include "libft.h"
#include<mlx.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
//#include<sys/types.h>
//#include<sys/stat.h>
#include<stdio.h>
//#include<errno.h>
#include<math.h> //a verifier

int					check_arg1(char *av);
int					check_path_ext(char *str);
int					check_path_open(char *str);
char				*map_create_str(char *av);

//errors
void				print_error_msg(int err_num);
//map_parsing
char				**map_parsing(char *av, t_map *map);

//map_creation
char				**map_creation(char *map_str, int pos, t_map *map);

//map_parsing_rcf
int					data_r(char *map_str, t_map *map, int *position);
int					data_c(char *map_str, t_map *map, int *position);
int					data_f(char *map_str, t_map *map, int *position);

//map_parsing_nsews
int					data_no(char *map_str, t_map *map, int *position);
int					data_so(char *map_str, t_map *map, int *position);
int					data_ea(char *map_str, t_map *map, int *position);
int					data_we(char *map_str, t_map *map, int *position);
int					data_s(char *map_str, t_map *map, int *position);
//map_check_col_int
int					check_lin(char **map_tab, int lin, int col);
int					check_col(char **map_tab, int lin, int col);
int					check_ext_col(char **map_tab);
int					check_ext_lin(char **map_tab);

//map_check_diag
int					check_diag1(char **map_tab, int lin, int col);
int					check_diag2(char **map_tab, int lin, int col);
int					check_diag3(char **map_tab, int lin, int col);
int					check_diag4(char **map_tab, int lin, int col);

//map_check_walls
int					map_check_walls(char **map_tab);
//ft_utils
int					ft_atoi_cub(const char *str, int *pos);
void				ft_free_map(char **map_tab, int j);
int					define_tile_size(t_map *map);

//functions_init
void				f_init_mapdata(t_map *map);
void				f_free_mapdata(t_map *map);
void				f_init_player(t_player *player, t_map *map);
void				f_update_player(t_player *player, char **map_tab, t_map *map);
//others
void	print_mapdata(t_map *map);
void	print_maptab(char **map_tab);
void	print_player(t_player *player);
void	print_coord(t_coord *c);
void	print_hit(t_hit *h);
void	print_ray(t_ray *r);
void	print_ray_orientation(t_ray *r);

//main minilibX
int		mlx_main(t_mlx *mlx);
int		close_game(t_mlx *mlx);
int		player_move(t_mlx *mlx);
int		mini_map_update(t_mlx *mlx);

//mlx_utils
int		key_hook(int key, t_mlx *mlx);
int		deal_key(int key, void * param);
int		deal_button(int key, void *param);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		close_win(t_mlx *mlx);
int		enter_win(int key,t_mlx *mlx);
int		exit_win(int key, t_mlx *mlx);

//mlx utils bis
void	mlx_draw_circle(int r, t_mlx *mlx);
void	mlx_draw_line(t_mlx *mlx);

//mlx player
int		key_release(int key, t_mlx *mlx);
int		key_press(int key, t_mlx *mlx);

//minimap
void	mlx_create_map(t_mlx *mlx);

//trigo
float deg_to_rad(float deg);
float rad_to_deg(float rad);
float within_rad(float rad);
float tangent(int deg);

//algo utils
int		hit_a_wall(int x, int y, char **map_tab, t_map *map);

// ray main
int		cast_all_rays(t_mlx *mlx);

//ray casting
int		cast_a_ray(t_mlx *mlx, int column_id);
//ray casting hv
void	ray_cast_vertical(t_mlx *mlx, t_coord *c, t_hit *h);
void	ray_cast_horizontal(t_mlx *mlx, t_coord *c, t_hit *h);

//ray walls
int ray_wall(t_mlx *, int column_id, t_hit *h);

#endif
