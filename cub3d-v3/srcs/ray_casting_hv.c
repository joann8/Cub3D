/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_hv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:28:05 by jacher            #+#    #+#             */
/*   Updated: 2021/01/28 09:25:31 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ray_cast_h_coord(t_data *d, t_coord *c)
{
	int	tronc;

	tronc = d->player->y / d->map->tile_lin;
	c->y_intercept = (tronc * d->map->tile_lin);
	if (d->ray->fac_down == 1)
		c->y_intercept += d->map->tile_lin;
	c->x_intercept = d->player->x
		+ ((-c->y_intercept + d->player->y) / tan((d->ray->angle)));
	c->y_step = d->map->tile_lin;
	if (d->ray->fac_up == 1)
		c->y_step *= -1;
	c->x_step = d->map->tile_lin / tan((d->ray->angle));
	if (d->ray->fac_left == 1 && c->x_step > 0)
		c->x_step *= -1;
	if (d->ray->fac_right == 1 && c->x_step < 0)
		c->x_step *= -1;
	c->x_next = c->x_intercept;
	c->y_next = c->y_intercept;
}

void	ray_cast_horizontal(t_data *d, t_coord *c, t_hit *h)
{
	double	min;
	int		res;

	ray_cast_h_coord(d, c);
	min = 0;
	if (d->ray->fac_up == 1)
		min = 1;
	while ((c->x_next >= 0 && c->x_next < d->map->r_x)
			&& (c->y_next - min >= 0 && c->y_next < d->map->r_y))
	{
		res = hit_a_wall(c->x_next, c->y_next - min, d->map_tab, d->map); 
		if (res == 1)
		{
			h->h_x_hit = c->x_next;
			h->h_y_hit = c->y_next;
			h->h_hit = 1;
			return ;
		}
		else
		{
			if (res == 2)
				sprite_ray(d, c->x_next, c->y_next - min); 
				//print_sprite(lst->content);
			if (c->x_next + c->x_step < 0 || c->y_next + c->y_step < 0)
				break ;
			c->x_next += c->x_step;
			c->y_next += c->y_step;
		}
	}
}

void	ray_cast_v_coord(t_data *d, t_coord *c)
{
	int	tronc;

	tronc = d->player->x / d->map->tile_col;
	c->x_intercept = (tronc * d->map->tile_col);
	if (d->ray->fac_right == 1)
		c->x_intercept += d->map->tile_col;
	c->y_intercept = d->player->y
		+ ((-c->x_intercept + d->player->x) * tan((d->ray->angle)));
	c->x_step = d->map->tile_col;
	if (d->ray->fac_left == 1)
		c->x_step *= -1;
	c->y_step = d->map->tile_col * tan((d->ray->angle));
	if (d->ray->fac_up == 1 && c->y_step > 0)
		c->y_step *= -1;
	if (d->ray->fac_down == 1 && c->y_step < 0)
		c->y_step *= -1;
	c->x_next = c->x_intercept;
	c->y_next = c->y_intercept;
}

void	ray_cast_vertical(t_data *d, t_coord *c, t_hit *h)
{
	double	min;
	int		res;

	ray_cast_v_coord(d, c);
	min = 0;
	if (d->ray->fac_left == 1)
		min = 1;
	while ((c->x_next - min >= 0 && c->x_next < d->map->r_x)
			&& (c->y_next >= 0 && c->y_next < d->map->r_y))
	{
		res = hit_a_wall(c->x_next - min, c->y_next, d->map_tab, d->map);
		if ( res == 1)
		{
			h->v_x_hit = c->x_next;
			h->v_y_hit = c->y_next;
			h->v_hit = 1;
			return ;
		}
		else
		{	
			if (res == 2)
				sprite_ray(d, c->x_next - min, c->y_next);
				//print_sprite(lst->content);
		//	}
			if (c->x_next + c->x_step < 0 || c->y_next + c->y_step < 0)
				break ;
			c->x_next += c->x_step;
			c->y_next += c->y_step;
		}
	}
}