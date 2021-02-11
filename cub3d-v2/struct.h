/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:29:46 by jacher            #+#    #+#             */
/*   Updated: 2021/02/11 15:51:43 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

# define BLOCK 25

typedef struct		s_map
{
	int				r;
	unsigned int	r_x;
	unsigned int	r_y;
	int				no;
	char			*no_path;
	int				so;
	char			*so_path;
	int				we;
	char			*we_path;
	int				ea;
	char			*ea_path;
	int				s;
	char			*s_path;
	int				f;
	int				f_r;
	int				f_g;
	int				f_b;
	int				c;
	int				c_r;
	int				c_g;
	int				c_b;
	int				player;
	char			player_pos;
	int				player_col;
	int				player_lin;
	int				map_col;
	int				map_lin;
	int				sprite;
	unsigned int	spr_col_no;
}					t_map;

typedef struct		s_player
{
	double			x;
	double			y;
	int				dir_turn;
	int				dir_walk_bf;
	int				dir_walk_lr;
	double			fov;
	double			angle;
	double			speed_ang;
	double			speed_walk;
	double			dist_plan;
}					t_player;

typedef struct		s_sprite
{
	int				visible;
	double			x_d;
	double			y_d;
	int				x_i;
	int				y_i;
	double			x_toplayer;
	double			y_toplayer;
	double			dist;
	double			height;
	double			size;
	double			length;
	double			angle;
	double			first_x;
}					t_sprite;

typedef struct		s_ray
{
	unsigned int	res;
	double			angle;
	double			x_hit;
	double			y_hit;
	double			dist;
	int				column_id;
	double			height;
	int				fac_down;
	int				fac_up;
	int				fac_right;
	int				fac_left;
	int				hit_vert;
}					t_ray;

typedef struct		s_hit
{
	int				h_hit;
	double			h_x_hit;
	double			h_y_hit;
	double			h_dist;
	int				v_hit;
	double			v_x_hit;
	double			v_y_hit;
	double			v_dist;
}					t_hit;

typedef struct		s_coord
{
	double			x_intercept;
	double			y_intercept;
	double			x_step;
	double			y_step;
	double			x_next;
	double			y_next;
}					t_coord;

typedef struct		s_img
{
	void			*ptr;
	char			*addr;
	int				bits;
	int				length;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	t_img			*img;
}					t_mlx;

typedef struct		s_text
{
	t_img			*text;
	int				height;
	int				length;
	t_img			*text_n;
	int				height_n;
	int				length_n;
	t_img			*text_s;
	int				height_s;
	int				length_s;
	t_img			*text_e;
	int				height_e;
	int				length_e;
	t_img			*text_w;
	int				height_w;
	int				length_w;
	t_img			*text_spr;
	int				height_spr;
	int				length_spr;
}					t_text;

typedef struct		s_data
{
	t_mlx			*mlx;
	t_map			*map;
	t_text			*t;
	t_player		*player;
	t_ray			*ray;
	t_sprite		*sprite;
	char			**map_tab;
	double			*rays_tab;
}					t_data;

typedef struct		s_bmp_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_bmp_color;

typedef struct		s_img_header
{
	int				size_img_header;
	int				width;
	int				length;
	short			nb_planes;
	short			bpp;
	int				compression;
	int				size_img_total;
	int				res_ver;
	int				res_hor;
	int				color_array;
	int				img_array;
}					t_img_header;

typedef struct		s_file_header
{
	char			signature[2];
	int				size;
	int				reserved;
	int				offset_img;
	t_img_header	img;
}					t_file_header;

#endif
