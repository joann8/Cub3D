/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:19:48 by jacher            #+#    #+#             */
/*   Updated: 2021/02/10 17:55:37 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	prepare_mlx(t_data *d, int mod)
{
	d->mlx->img->ptr = mlx_new_image(d->mlx->ptr, d->map->r_x, d->map->r_y);
	if (d->mlx->img->ptr == NULL)
	{
		close_game(d);
		return (print_error_mlx(2));
	}
	d->mlx->img->addr = mlx_get_data_addr(d->mlx->img->ptr,
		&(d->mlx->img->bits), &(d->mlx->img->length), &(d->mlx->img->endian));
	if (mod == 2)
	{
		d->mlx->win = mlx_new_window(d->mlx->ptr, d->map->r_x,
			d->map->r_y, "cub3D");
		if (d->mlx->win == NULL)
		{
			close_game(d);
			return (print_error_mlx(3));
		}
	}
	if (init_texture(d) == -1)
	{
		close_game(d);
		return (-1);
	}
	return (1);
}

int	mlx_main(t_data *d, int mod)
{
	t_img	img;

	d->mlx->img = &img;
	if (prepare_mlx(d, mod) == -1)
		return (-1);
	d->rays_tab = malloc(sizeof(double) * (int)d->map->r_x);
	if (d->rays_tab == NULL)
		return (print_error_mlx(4));
	if (mod == 2)
		events(d);
	else
		save_bmp(d);
	free(d->rays_tab);
	close_game(d);
	return (1);
}
