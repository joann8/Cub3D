/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:29:46 by jacher            #+#    #+#             */
/*   Updated: 2021/01/26 17:21:33 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H

# define CUB_H


// hello
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
void				f_reset_ray(t_ray *r);
//others
void	print_mapdata(t_map *map);
void	print_maptab(char **map_tab);
void	print_player(t_player *player);
void	print_coord(t_coord *c);
void	print_hit(t_hit *h);
void	print_ray(t_ray *r);
void	print_ray_orientation(t_ray *r);

//main minilibX
int		mlx_main(t_data *d);
int		close_game(t_data *d);
int		player_move(t_data *d);
int		mini_map_update(t_data *d);

//mlx_utils
int		key_hook(int key, t_data *d);
int		deal_key(int key, void * param);
int		deal_button(int key, void *param);
void	my_mlx_pixel_put(t_data *d, int x, int y, int color);
int		close_win(t_data *d);
int		enter_win(int key,t_data *d);
int		exit_win(int key, t_data *d);
unsigned int	mlx_img_get_pixel_value(t_img *img, int x, int y);


//mlx utils bis
void	mlx_draw_circle(int r, t_data *d);
void	mlx_draw_line(t_data *d);

//mlx key pressed
int		key_release(int key, t_data *d);
int		key_press(int key, t_data *d);

// mlx update player
void				f_update_player(t_data *d);


// mlx textures
int	init_texture(t_data *d);

//minimap
void	mlx_create_map(t_data *d);

//trigo
double deg_to_rad(double deg);
double rad_to_deg(double rad);
double within_rad(double rad);

//algo utils
int		hit_a_wall(double x, double y, char **map_tab, t_map *map);
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

// ray main
int		cast_all_rays(t_data *d);

//ray casting
int		cast_a_ray(t_data *d);
//ray casting hv
void	ray_cast_vertical(t_data *d, t_coord *c, t_hit *h);
void	ray_cast_horizontal(t_data *d, t_coord *c, t_hit *h);

//ray walls
int		ray_wall(t_data *d);
void	draw_wall(t_data *d, unsigned int i, unsigned int j, unsigned int start);
void	assign_texture(t_data *d);


#endif
