/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_print_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:38:29 by jacher            #+#    #+#             */
/*   Updated: 2021/01/25 15:11:40 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_texture(t_data *d, path to texture, unsigned int start)
{
	unsigned int	ratio;



	j = *pos;

	
	while (j < d->ray->height + start && j < d->map->r_y)
	

}





void	draw_cube(t_data *d, unsigned int start, unsigned int j)
{
	if (d->ray->hit_vert == 1)
	{
		if (d->ray->fac_left == 1 || d->ray->angle == M_PI)
			draw_texture(d, west, j); // RED
		if (d->ray->fac_right == 1 || d->ray->angle == 0)
			draw_texture(d, east, j);
	}
	else if (d->ray->hit_vert == -1)
	{
		if (d->ray->fac_up == 1 || d->ray->angle == M_PI / 2)
			draw_texture(d, north, j)
		if (d->ray->fac_down == 1 || d->ray->angle == (3 * M_PI) / 2)
			draw_texture(d, south_, j;
	}
}

