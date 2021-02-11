/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:29:46 by jacher            #+#    #+#             */
/*   Updated: 2021/02/11 14:49:51 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H

# define CUB_H

# include "struct.h"
# include "libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

int				check_arg1(char *av);
int				check_arg(int ac, char **av);
int				check_path_ext(char *str);
int				check_path_open(char *str);
int				print_error_parsing(int err_num);
int				print_error_mlx(int err_num);
int				print_error_else(int err_num);
char			*map_create_str(char *av);
int				check_str(char *map_str, int *i, t_map *map);
int				data_r(char *map_str, t_map *map, int *position);
int				data_c(char *map_str, t_map *map, int *position);
int				data_f(char *map_str, t_map *map, int *position);
int				data_no(char *map_str, t_map *map, int *position);
int				data_so(char *map_str, t_map *map, int *position);
int				data_ea(char *map_str, t_map *map, int *position);
int				data_we(char *map_str, t_map *map, int *position);
int				data_s(char *map_str, t_map *map, int *position);
void			f_free_mapdata(t_map *map);
void			free_data(t_data *d);
void			free_textures_ptr(t_data *d);
void			free_textures(t_data *d);
void			ft_free_map(char **map_tab, int j);
int				skip_space_folder(char *map_str, int *i);
int				record_player_pos(t_map *map, char **map_tab);
int				check_walls_texture(t_map *map, char *map_str);
char			**map_parsing(char *av, t_map *map);
char			**map_creation(char *map_str, int pos, t_map *map);
int				check_lin(char **map_tab, int lin, int col);
int				check_col(char **map_tab, int lin, int col);
int				check_ext_col(char **map_tab);
int				check_ext_lin(char **map_tab);
int				map_check_walls(char **map_tab);
unsigned int	count_sprite(t_data *d);
void			record_sprite(t_data *d, unsigned int count);
int				ft_atoi_cub(const char *str, int *pos);
int				check_block_size(t_map *map);
void			check_res(t_data *d, int mod);
int				hit_a_wall(double x, double y, char **map_tab, t_map *map);
int				create_trgb(int t, int r, int g, int b);
double			deg_to_rad(double deg);
double			rad_to_deg(double rad);
double			within_rad(double rad);
double			calculate_distance(double x1, double x2, double y1, double y2);
void			f_init_mapdata(t_map *map);
void			f_init_player(t_player *player, t_map *map);
void			f_init_sprite(t_sprite *s);
void			f_reset_sprite(t_data *d);
void			f_reset_ray(t_ray *r);
int				mlx_main(t_data *d, int mod);
int				key_release(int key, t_data *d);
int				key_press(int key, t_data *d);
int				player_move(t_data *d);
void			events(t_data *d);
void			my_mlx_pixel_put(t_data *d, int x, int y, int color);
unsigned int	mlx_img_get_pixel_value(t_img *img, int x, int y);
int				close_game(t_data *d);
void			f_update_player(t_data *d);
int				init_texture(t_data *d);
void			cast_all_rays(t_data *d);
int				assign_distance(t_data *d, t_hit *h);
int				cast_a_ray(t_data *d);
void			ray_cast_vertical(t_data *d, t_coord *c, t_hit *h);
void			ray_cast_horizontal(t_data *d, t_coord *c, t_hit *h);
void			ray_cast_v_coord(t_data *d, t_coord *c);
void			ray_cast_h_coord(t_data *d, t_coord *c);
int				ray_wall(t_data *d);
void			draw_wall(t_data *d, int i, int j, int start);
void			assign_texture_h(t_data *d);
void			assign_texture_v(t_data *d);
void			draw_column(t_data *d, int start);
int				sprite_ray(t_data *d, double x_h, double y_h);
void			mlx_sprite(t_data *d, double *rays);
void			convert_trgb_bmp(t_bmp_color *pixel, t_img *img, int x, int y);
int				get_byte_correction(int img_width);
int				save_bmp(t_data *d);

#endif
