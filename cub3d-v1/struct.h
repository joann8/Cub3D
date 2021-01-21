/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:29:46 by jacher            #+#    #+#             */
/*   Updated: 2021/01/14 23:07:13 by jacher           ###   ########.fr       */
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
	int				x; //pixel position
	int				y; //pixel position
	float			dir_turn; // 0 no turn, -1 left +1 right
	int				dir_walk_bf;// 0 no move, -1 recule +1 avance
	int				dir_walk_lr;// 0 no move, -1 lef +1 right
	float			dir_ang; //where my player is looking 0-2pi
	float			speed_ang; //how many angle per frame
	float			speed_walk; //how many pixels per frame
	//radius = size joueur pour minimap
}					t_player;

typedef struct	s_ray
{
	float	fov;
	int		res;
	float	ray_ang;
	float	x_hit;
	float	y_hit;
	float	dist;
	int		fac_down;
	int		fac_up;
	int		fac_right;
	int		fac_left;
	int		hit_vert;
}				t_ray;

typedef struct	s_hit
{	
	int		h_hit;
	float	h_x_hit;
	float	h_y_hit;
	float	h_dist;
	int		v_hit;
	float	v_x_hit;
	float	v_y_hit;
	float	v_dist;
}				t_hit;

typedef struct s_coord
{
	float	x_intercept;
	float	y_intercept;
	float	x_step;
	float	y_step;
	float 	x_next;
	float	y_next;
}			 t_coord;

typedef struct s_mlx
{
	void 		*ptr;
	void 		*win;
	void		*img;
	char		*img_addr;

	//a effacer?
	void		*mm_win;
	void		*mm_img;
	char		*mm_img_addr;
	int			mm_img_bits;
	int			mm_img_line_length;
	int			mm_img_endian;
	//
	int			img_bits;
	int			img_line_length;
	int			img_endian;
	t_map 		*map;
	t_player	*player;
	t_ray		*ray;
	char 		**map_tab;

}				t_mlx;

#endif
