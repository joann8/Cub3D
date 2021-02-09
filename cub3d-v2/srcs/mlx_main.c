/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:19:48 by jacher            #+#    #+#             */
/*   Updated: 2021/02/09 18:15:20 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	mlx_main(t_data *d, int mod)
{
	t_img img;

	d->mlx->img = &img;
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
		d->mlx->win = mlx_new_window(d->mlx->ptr, d->map->r_x, d->map->r_y, "win");
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
	if (mod == 2)
		events(d);
	else
		save_bmp(d);
	close_game(d);
	return (1);
}
