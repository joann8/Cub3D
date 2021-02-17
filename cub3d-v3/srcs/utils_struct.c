/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:51:10 by jacher            #+#    #+#             */
/*   Updated: 2021/02/02 16:33:35 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	f_init_mapdata(t_map *map)
{
	map->r = -1;
	map->r_x_i = 0;
	map->r_y_i = 0;
	map->r_x = 0;
	map->r_y = 0;
	map->no = -1;
	map->no_path = NULL;
	map->so = -1;
	map->so_path = NULL;
	map->we = -1;
	map->we_path = NULL;
	map->ea = -1;
	map->ea_path = NULL;
	map->s = -1;
	map->s_path = NULL;
	map->f = -1;
	map->f_r = -1;
	map->f_g = -1;
	map->f_b = -1;
	map->c = -1;
	map->c_r = -1;
	map->c_g = -1;
	map->c_b = -1;
	map->player = -1;
	map->player_col = -1;
	map->player_lin = -1;
	map->map_col = -1;
	map->map_lin = -1;
	map->tile_lin = -1;
	map->tile_col = -1;
	map->tile_min = -1;
	map->sprite = 0;
}

void	f_free_mapdata(t_map *map)
{
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->ea_path)
		free(map->ea_path);
	if (map->we_path)
		free(map->we_path);
	if (map->s_path)
		free(map->s_path);
}

double	f_init_dir_ang(char c)
{
	double	ang_rad;
/*
	if (c == 'S')
		ang_rad = deg_to_rad(0);
	else if (c ==  'E')
		ang_rad = deg_to_rad(90); 
	else if (c ==  'N')
		ang_rad = deg_to_rad(180); 
	else // c ==  'w'
		ang_rad = deg_to_rad(270); 
	return (ang_rad);
*/
// normalement pas d'erreur car detecter au parsing
	if (c == 'N')
		ang_rad = (3 * M_PI) / 2;
	else if (c ==  'W')
		ang_rad = M_PI; 
	else if (c ==  'S')
		ang_rad = M_PI / 2; 
	else // c ==  'e'
		ang_rad = 0; 
	return (ang_rad);
}

void	f_init_player(t_player *player, t_map *map)
{
	player->x_max = map->r_x;
	player->y_max = map->r_y;
	player->x = ((map->player_col * map->tile_col) + (map->tile_col / 2));
	player->y = ((map->player_lin * map->tile_lin) + (map->tile_lin / 2));
	printf("init : player x= %f | player y = %f\n", player->x, player->y);
	player->dir_turn = 0;
	player->dir_walk_bf = 0;
	player->dir_walk_lr = 0;
	player->fov = M_PI / 3;
	player->angle= f_init_dir_ang(map->player_pos);
	player->speed_walk = 3; //((map->r_x * map->r_y) / 9600); // a modifier?
	player->speed_ang = deg_to_rad(5);//deg_to_rad((player->speed_walk / 3));  // a modifier?
}

void	f_reset_ray(t_ray *r)
{
	r->res = 1;
	r->x_hit = 0;
	r->y_hit = 0;
	r->dist = 0;
	r->height = 0;
	r->fac_up = 0;
	r->fac_down = 0;
	r->fac_right = 0;
	r->fac_left = 0;
	r->hit_vert = 0;
}

void	f_init_sprite(t_sprite *s)
{
	s->x_d = 0;
	s->y_d = 0;	
	s->x_d = 0;
	s->y_d = 0;
	s->dist = 0;
}

void	f_reset_sprite(t_data *d)
{
	int i;

	i = 0;
	while (i < d->map->sprite)
	{
		d->sprite[i].dist = 0;
		d->sprite[i].angle = 0;
		d->sprite[i].height = 0;
		d->sprite[i].length = 0;
		d->sprite[i].visible = 0;
		i++;
	}
}
