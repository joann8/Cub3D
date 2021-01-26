/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:51:10 by jacher            #+#    #+#             */
/*   Updated: 2021/01/26 10:39:58 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int player_move(t_data *d)
{
//	printf("enter player move\n");
	f_update_player(d);
//juste pour afficher minimap
//	mini_map_update(d);
	printf("cast all ray\n");
	cast_all_rays(d);
	mlx_put_image_to_window(d->mlx->ptr, d->mlx->win, d->mlx->img->ptr, 0, 0);
	return(0);
}

void	f_update_player(t_data *d)
{
	double	x;
	double	y;
//	int		move;
	double	ang;

//	printf("***enter update player****\n");
//	print_player(player);
	//based on turn direction
	//ang = player->dir_turn * player->speed_ang;
	ang = within_rad(d->player->angle + d->player->dir_turn * d->player->speed_ang);
	/// gauche == + // droite == -

	d->player->angle = ang;
	// aller a droite ou a gauche
	// pas sure des formules maths
	y = d->player->y;
	x = d->player->x;
	
	if (d->player->dir_walk_bf == 1) // on avance
	{
		x = d->player->x + cos(d->player->angle) * d->player->speed_walk;
		y = d->player->y - sin(d->player->angle) * d->player->speed_walk;
	}
	else if (d->player->dir_walk_bf == -1) //on recule
	{
		x = d->player->x - cos(d->player->angle) * d->player->speed_walk;
		y = d->player->y + sin(d->player->angle) * d->player->speed_walk;
	}
	else if (d->player->dir_walk_lr == 1) // a gauche
	{
		x = d->player->x + cos(within_rad(d->player->angle + (M_PI / 2))) * d->player->speed_walk;
		y = d->player->y - sin(within_rad(d->player->angle + (M_PI / 2))) * d->player->speed_walk;
	}	
	else if (d->player->dir_walk_lr == -1) // a doite
	{
		x = d->player->x - cos(within_rad(d->player->angle + (M_PI / 2))) * d->player->speed_walk;
		y = d->player->y + sin(within_rad(d->player->angle + (M_PI / 2))) * d->player->speed_walk;
	}
	
/*

	move = player->speed_walk * player->dir_walk_bf + player->speed_walk * player->dir_walk_lr;
//	printf("move = %d\n", move);
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
	}*/
	if (hit_a_wall(x, y, d->map_tab, d->map) == 0)
	{
	//	printf("update hit a wall\n");
		d->player->x = x; // j
		d->player->y = y; // i
	}	
	//printf("a : player->x = %d\n", player->x);
	//printf("a : player->y = %d\n", player->y);
	
	d->player->dir_turn = 0; //reset	
	d->player->dir_walk_bf = 0;
	d->player->dir_walk_lr = 0;

//	printf("***exit update player****\n");
}


