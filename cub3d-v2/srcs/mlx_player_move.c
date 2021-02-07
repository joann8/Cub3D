/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_player_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:51:10 by jacher            #+#    #+#             */
/*   Updated: 2021/02/07 19:28:22 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		close_game(t_data *d)
{
	free_textures(d);
	free_textures_ptr(d);
	if (d->mlx->img->ptr)
		mlx_destroy_image(d->mlx->ptr, d->mlx->img->ptr);
	if (d->mlx->win)
		mlx_destroy_window(d->mlx->ptr, d->mlx->win);
	if (d->mlx->ptr)
	{
		mlx_destroy_display(d->mlx->ptr);
		free(d->mlx->ptr);
	}
	return (1);
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
		|| hit_a_wall(x, y, d->map_tab, d->map) == 2)// on accepte les objets
	{
		d->player->x = x;
		d->player->y = y;
	}
}
