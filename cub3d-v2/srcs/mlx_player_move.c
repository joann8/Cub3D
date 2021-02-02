/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_player_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:51:10 by jacher            #+#    #+#             */
/*   Updated: 2021/02/02 21:31:43 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		player_move(t_data *d)
{
//	printf("enter player move\n");
	f_update_player(d);
// juste pour afficher minimap
//	mini_map_update(d);
	printf("cast all ray\n");
	cast_all_rays(d);
	mlx_put_image_to_window(d->mlx->ptr, d->mlx->win, d->mlx->img->ptr, 0, 0);
	return (0);
}

void	calculate_x_y(t_data *d, double *x, double *y)
{
	if (d->player->dir_walk_bf == 1)
	{
		*x = d->player->x + cos(d->player->angle) * d->player->speed_walk;
		*y = d->player->y - sin(d->player->angle) * d->player->speed_walk;
	}
	else if (d->player->dir_walk_bf == -1)
	{
		*x = d->player->x - cos(d->player->angle) * d->player->speed_walk;
		*y = d->player->y + sin(d->player->angle) * d->player->speed_walk;
	}
	else if (d->player->dir_walk_lr == 1)
	{
		*x = d->player->x + cos(within_rad(d->player->angle + (M_PI / 2)))
			* d->player->speed_walk;
		*y = d->player->y - sin(within_rad(d->player->angle + (M_PI / 2)))
			* d->player->speed_walk;
	}
	else if (d->player->dir_walk_lr == -1)
	{
		*x = d->player->x - cos(within_rad(d->player->angle + (M_PI / 2)))
			* d->player->speed_walk;
		*y = d->player->y + sin(within_rad(d->player->angle + (M_PI / 2)))
			* d->player->speed_walk;
	}
}

void	f_update_player(t_data *d)
{
	double	x;
	double	y;

	d->player->angle = within_rad(d->player->angle
			+ d->player->dir_turn * d->player->speed_ang);
	y = d->player->y;
	x = d->player->x;
	calculate_x_y(d, &x, &y);
	if (hit_a_wall(x, y, d->map_tab, d->map) == 0
		|| hit_a_wall(x, y, d->map_tab, d->map) == 2) // on accepte les objets
	{
		d->player->x = x;
		d->player->y = y;
	}
}
