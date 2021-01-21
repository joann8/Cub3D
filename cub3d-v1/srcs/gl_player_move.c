/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:51:10 by jacher            #+#    #+#             */
/*   Updated: 2021/01/20 19:47:13 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	f_update_player(t_player *player, char **map_tab, t_map *map)
{
	float i;
	float j;
	int move;
	float ang;

//	printf("***enter update player****\n");
//	print_player(player);
	//based on turn direction
	//ang = player->dir_turn * player->speed_ang;
	ang = within_rad(player->dir_ang + player->dir_turn * player->speed_ang);
	player->dir_ang = ang;
	// aller a droite ou a gauche
	// pas sure des formules maths
	i = player->y;
	j = player->x;
	move = player->speed_walk * player->dir_walk_bf + player->speed_walk * player->dir_walk_lr;
//	printf("move = %d\n", move);
	ang = player->dir_ang;
	if (player->dir_walk_lr != 0)
	{	
		//printf("player->dir_walk_lr = %d\n", player->dir_walk_lr);	
		ang = within_rad(ang + deg_to_rad(90));
		//printf("player->dir_walk_lr = %d\n", player->dir_walk_lr);	
	//	j = player->x + cos(deg_to_rad(90) - player->dir_ang) * move_lr;
	//	i = player->y + sin(deg_to_rad(90) - player->dir_ang) * move_lr;
	}
	if (move != 0)
	{	
	//	printf("player->dir_walk_bf = %d\n", player->dir_walk_bf);	
	//	printf("cos(%f) = %f | sin(%f) = %f\n", ang, cos(ang), ang, sin(ang));
		j += cos(ang) * move;
		i += sin(ang) * move;
	//	printf("i = %f | j %f\n", i, j);
	}
	if (hit_a_wall((int)i, (int)j, map_tab, map) == 0)
	{
		//printf("update hit a wall\n");
		player->x = (int)j; // j
		player->y = (int)i; // i
	}	
	//printf("a : player->x = %d\n", player->x);
	//printf("a : player->y = %d\n", player->y);
	
	player->dir_turn = 0; //reset	
	player->dir_walk_bf = 0;
	player->dir_walk_lr = 0;

//	printf("***exit update player****\n");
}


