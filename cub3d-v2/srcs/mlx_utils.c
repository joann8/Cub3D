/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:31:08 by jacher            #+#    #+#             */
/*   Updated: 2021/02/07 19:31:40 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

unsigned int	mlx_img_get_pixel_value(t_img *img, int x, int y)
{
	char *dst;

	dst = img->addr + (y * img->length) + (x * 4);
	return (*(unsigned*)dst);
}

void			my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char *dst;

	dst = d->mlx->img->addr + (y * d->mlx->img->length
		+ x * (d->mlx->img->bits / 8));
	*(unsigned int*)dst = color;
}
