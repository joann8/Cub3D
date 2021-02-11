/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:51:10 by jacher            #+#    #+#             */
/*   Updated: 2021/02/11 22:36:34 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	f_init_mapdata_bis(t_map *map)
{
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
	map->sprite = 0;
	map->spr_col_no = 0;
}

void	f_init_mapdata(t_map *map)
{
	map->r = -1;
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
	f_init_mapdata_bis(map);
}

double	f_init_dir_ang(char c)
{
	double	ang_rad;

	if (c == 'S')
		ang_rad = (3 * M_PI) / 2 + 0.01;
	else if (c == 'W')
		ang_rad = M_PI + 0.01;
	else if (c == 'N')
		ang_rad = M_PI / 2 + 0.01;
	else
		ang_rad = 0.01;
	return (ang_rad);
}

void	f_init_player(t_player *player, t_map *map)
{
	player->x = ((map->player_col * BLOCK) + (BLOCK / 2));
	player->y = ((map->player_lin * BLOCK) + (BLOCK / 2));
	player->dir_turn = 0;
	player->dir_walk_bf = 0;
	player->dir_walk_lr = 0;
	player->fov = M_PI / 3;
	player->angle = f_init_dir_ang(map->player_pos);
	player->speed_walk = 0.3;
	player->speed_ang = deg_to_rad(2);
	player->dist_plan = (map->r_x / 2) / (tan(player->fov / 2));
}

void	f_init_sprite(t_sprite *s)
{
	s->x_d = 0;
	s->y_d = 0;
	s->x_i = 0;
	s->y_i = 0;
	s->dist = 0;
}
