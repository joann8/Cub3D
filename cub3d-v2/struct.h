/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:29:46 by jacher            #+#    #+#             */
/*   Updated: 2021/01/21 18:54:29 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

typedef struct		s_map
{
	int				r;
	unsigned int	r_x_i;
	unsigned int	r_y_i;
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
	int				tile_col;
	int				tile_lin;
	int				tile_min;
}
					t_map;


typedef struct		s_player
{
	int				x_max; //pixel carte
	int				y_max; //limite pixel carte
	double			x; //pixel position
	double			y; //pixel position
	int				dir_turn; // 0 no turn, -1 left +1 right
	int				dir_walk_bf;// 0 no move, -1 recule +1 avance
	int				dir_walk_lr;// 0 no move, -1 lef +1 right
	double			fov;
	double			angle; //where my player is looking 0-2pi
	double			speed_ang; //how many angle per frame
	double			speed_walk; //how many pixels per frame
	//radius = size joueur pour minimap
}					t_player;

typedef struct	s_ray
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
}				t_ray;

typedef struct	s_hit
{	
	int		h_hit;
	double	h_x_hit;
	double	h_y_hit;
	double	h_dist;
	int		v_hit;
	double	v_x_hit;
	double	v_y_hit;
	double	v_dist;
}				t_hit;

typedef struct s_coord
{
	double	x_intercept;
	double	y_intercept;
	double	x_step;
	double	y_step;
	double	x_next;
	double	y_next;
}			 t_coord;

typedef struct	s_img
{
	void		*ptr;
	char		*addr;
	int			bits;
	int			length;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void 		*ptr;
	void 		*win;
	t_img		*img;
}		
				t_mlx;
	
typedef struct s_data
{
	t_mlx		*mlx;
	t_map 		*map;
	t_player	*player;
	t_ray		*ray;
	char 		**map_tab;

}				t_data;

#endif
