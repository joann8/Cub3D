/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:51:10 by jacher            #+#    #+#             */
/*   Updated: 2021/02/08 10:56:59 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
void	f_reset_ray(t_ray *r)
{
	r->res = 1;
	r->x_hit = 0;
	r->y_hit = 0;
	r->dist = 0;
	r->height = 0;
	r->fac_up = 0;
	r->fac_down = 0;
	r->fac_right = 0;
	r->fac_left = 0;
	r->hit_vert = 0;
}

void	f_reset_sprite(t_data *d)
{
	int i;

	i = 0;
	while (i < d->map->sprite)
	{
		d->sprite[i].dist = 0;
		d->sprite[i].angle = 0;
		d->sprite[i].height = 0;
		d->sprite[i].length = 0;
		d->sprite[i].visible = 0;
		i++;
	}
}
