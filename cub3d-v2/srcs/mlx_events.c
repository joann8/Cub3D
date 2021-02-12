/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:26:05 by jacher            #+#    #+#             */
/*   Updated: 2021/02/12 11:06:17 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		key_press(int key, t_data *d)
{
	if (key == 119 || key == 13)
		d->player->dir_walk_bf = 1;
	else if (key == 115 || key == 1)
		d->player->dir_walk_bf = -1;
	else if (key == 97 || key == 0)
		d->player->dir_walk_lr = 1;
	else if (key == 100 || key == 2)
		d->player->dir_walk_lr = -1;
	else if (key == 65361 || key == 123)
		d->player->dir_turn = 1;
	else if (key == 65363 || key == 124)
		d->player->dir_turn = -1;
	else if (key == 65307 || key == 53)
		mlx_loop_end(d->mlx->ptr);
	return (1);
}

int		key_release(int key, t_data *d)
{
	if (key == 119 || key == 13)
		d->player->dir_walk_bf = 0;
	else if (key == 115 || key == 1)
		d->player->dir_walk_bf = 0;
	else if (key == 97 || key == 0)
		d->player->dir_walk_lr = 0;
	else if (key == 100 || key == 2)
		d->player->dir_walk_lr = 0;
	else if (key == 65361 || key == 123)
		d->player->dir_turn = 0;
	else if (key == 65363 || key == 124)
		d->player->dir_turn = 0;
	return (1);
}

int		player_move(t_data *d)
{
	f_update_player(d);
	cast_all_rays(d);
	mini_map_update(d);
	mlx_put_image_to_window(d->mlx->ptr, d->mlx->win, d->mlx->img->ptr, 0, 0);
	return (0);
}

void	events(t_data *d)
{
	mlx_hook(d->mlx->win, 33, 1L << 17, &mlx_loop_end, d->mlx->ptr);
	mlx_loop_hook(d->mlx->ptr, &player_move, d);
	mlx_hook(d->mlx->win, 2, 1L << 0, &key_press, d);
	mlx_hook(d->mlx->win, 3, 1L << 1, &key_release, d);
	mlx_loop(d->mlx->ptr);
}
