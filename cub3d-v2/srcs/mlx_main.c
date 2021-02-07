/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:19:48 by jacher            #+#    #+#             */
/*   Updated: 2021/02/07 19:25:30 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	mlx_main(t_data *d)
{
	t_img img;

	d->mlx->img = &img;
	d->mlx->img->ptr = mlx_new_image(d->mlx->ptr, d->map->r_x, d->map->r_y);
	if (d->mlx->img->ptr == NULL)
	{
		close_game(d);
		return (print_error_mlx(2, d));
	}
	d->mlx->img->addr = mlx_get_data_addr(d->mlx->img->ptr,
		&(d->mlx->img->bits), &(d->mlx->img->length), &(d->mlx->img->endian));
	d->mlx->win = mlx_new_window(d->mlx->ptr, d->map->r_x, d->map->r_y, "win");
	if (d->mlx->win == NULL)
	{
		close_game(d);
		return (print_error_mlx(3, d));
	}
	if (init_texture(d) == -1)
	{
		close_game(d);
		return (-1);
	}
	events(d);
	close_game(d);
	return (1);
}
