/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:28:05 by jacher            #+#    #+#             */
/*   Updated: 2021/02/11 22:30:26 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		ray_wall(t_data *d)
{
	double			corrected_dist;
	int				start;

	corrected_dist = d->ray->dist * cos(d->ray->angle - d->player->angle);
	d->ray->height = (((BLOCK / corrected_dist) * d->player->dist_plan));
	start = (d->map->r_y / 2) - ((d->ray->height / 2));
	if (d->ray->hit_vert == 1)
		assign_texture_v(d);
	else if (d->ray->hit_vert == -1)
		assign_texture_h(d);
	draw_column(d, start);
	return (1);
}

void	ray_orientation(t_data *d)
{
	if (d->ray->angle < M_PI)
	{
		d->ray->fac_up = 1;
		d->ray->fac_down = -1;
	}
	else if (d->ray->angle > M_PI)
	{
		d->ray->fac_up = -1;
		d->ray->fac_down = 1;
	}
	if (d->ray->angle < M_PI / 2 || d->ray->angle > (3 * M_PI) / 2)
	{
		d->ray->fac_right = 1;
		d->ray->fac_left = -1;
	}
	else if (d->ray->angle > M_PI / 2 && d->ray->angle < (3 * M_PI) / 2)
	{
		d->ray->fac_right = -1;
		d->ray->fac_left = 1;
	}
}

int		assign_distance(t_data *d, t_hit *h)
{
	if (h->h_hit == 1)
		h->h_dist = calculate_distance(h->h_x_hit, d->player->x,
			h->h_y_hit, d->player->y);
	if (h->v_hit == 1)
		h->v_dist = calculate_distance(h->v_x_hit, d->player->x,
			h->v_y_hit, d->player->y);
	if ((h->v_hit == 1) && (h->h_hit != 1 || h->h_dist >= h->v_dist))
	{
		d->ray->x_hit = h->v_x_hit;
		d->ray->y_hit = h->v_y_hit;
		d->ray->dist = h->v_dist;
		d->ray->hit_vert = 1;
		return (1);
	}
	else if ((h->h_hit == 1) && (h->v_hit != 1 || h->h_dist < h->v_dist))
	{
		d->ray->x_hit = h->h_x_hit;
		d->ray->y_hit = h->h_y_hit;
		d->ray->dist = h->h_dist;
		d->ray->hit_vert = -1;
		return (1);
	}
	return (-1);
}

int		cast_a_ray(t_data *d)
{
	t_coord	c_v;
	t_coord	c_h;
	t_hit	h;

	h.v_hit = 0;
	h.h_hit = 0;
	ray_orientation(d);
	ray_cast_h_coord(d, &c_h);
	ray_cast_horizontal(d, &c_h, &h);
	ray_cast_v_coord(d, &c_v);
	ray_cast_vertical(d, &c_v, &h);
	if (h.h_hit == 1 || h.v_hit == 1)
	{
		if (assign_distance(d, &h) == -1)
			return (-1);
	}
	ray_wall(d);
	return (1);
}
