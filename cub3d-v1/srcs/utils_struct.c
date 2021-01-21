/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:51:10 by jacher            #+#    #+#             */
/*   Updated: 2021/01/20 19:43:07 by jacher           ###   ########.fr       */
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

float	f_init_dir_ang(char c)
{
	float	ang_rad;
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
	if (c == 'S')
		ang_rad = (3 * M_PI) / 2;
	else if (c ==  'W')
		ang_rad = M_PI; 
	else if (c ==  'N')
		ang_rad = M_PI / 2; 
	else // c ==  'e'
		ang_rad = 0; 
	return (ang_rad);
}

void	f_init_player(t_player *player, t_map *map)
{
	player->x_max = map->r_x;
	player->y_max = map->r_y;
	player->x = (map->player_col * map->tile_col) + (map->tile_col / 2);
	player->y = (map->player_lin * map->tile_lin) + (map->tile_lin / 2);
	player->dir_turn = 0;
	player->dir_walk_bf = 0;
	player->dir_walk_lr = 0;
	player->dir_ang = f_init_dir_ang(map->player_pos);
	player->speed_ang = deg_to_rad(15);  // a modifier?
	player->speed_walk = 15; // a modifier?
}
