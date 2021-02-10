/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:02:07 by jacher            #+#    #+#             */
/*   Updated: 2021/02/10 18:11:29 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	cast_all_rays(t_data *d)
{
	int		i;
	int		num_rays;

	f_reset_ray(d->ray);
	i = 0;
	num_rays = (int)d->map->r_x;
	while (i < num_rays)
	{
		d->ray->angle = within_rad(d->player->angle
				+ atan(((num_rays / 2) - i) / d->player->dist_plan));
		f_reset_ray(d->ray);
		d->ray->column_id = i;
		cast_a_ray(d);
		d->rays_tab[i] = d->ray->dist;
		i++;
	}
	mlx_sprite(d, d->rays_tab);
	f_reset_sprite(d);
}
