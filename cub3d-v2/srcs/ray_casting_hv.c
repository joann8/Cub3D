/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_hv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:28:05 by jacher            #+#    #+#             */
/*   Updated: 2021/01/21 16:35:18 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ray_cast_h_coord(t_data *d, t_coord *c, t_hit *h)
{
	//find coordinates of the closest horizontal grid intersection
	int	tronc;
	(void)h;
	printf("ang = %f\n", rad_to_deg(d->ray->angle));
	printf("player x = %f | player y = %f\n", d->player->x, d->player->y);	
	//printf("mlx->player->x = %d | mlx->map->tilelin = %d\n", mlx->player->x, mlx->map->tile_lin);
	tronc = d->player->y / d->map->tile_lin;
	c->y_intercept = (tronc * d->map->tile_lin);
	if (d->ray->fac_down == 1)
		c->y_intercept += d->map->tile_lin;
	c->x_intercept = d->player->x + ((-c->y_intercept + d->player->y) / tan((d->ray->angle)));
	//c->x_intercept = mlx->player->x + ((c->y_intercept - mlx->player->y) / tan((within_rad(mlx->ray->ray_ang - deg_to_rad(90)))));
//	if (c->x_intercept >= mlx->map->r_x)
//	{
//		h->h_hit = -1;
//		return ;
//	}
	//Calculate x step and y step
	c->y_step = d->map->tile_lin;
	if (d->ray->fac_up == 1)
		c->y_step *= -1;
	c->x_step = d->map->tile_lin / tan((d->ray->angle));
	//c->x_step = mlx->map->tile_lin / tan(within_rad((mlx->ray->ray_ang - deg_to_rad(90))));
	if (d->ray->fac_left == 1 && c->x_step > 0)
		c->x_step *= -1;
	if (d->ray->fac_right == 1 && c->x_step < 0)
		c->x_step *= -1;
	c->x_next = c->x_intercept;
	c->y_next = c->y_intercept;
//	my_mlx_pixel_put(mlx, c->x_next, c->y_next, 0x00999999);
}

void	ray_cast_horizontal(t_data *d, t_coord *c, t_hit *h)
{
	double	min;

	ray_cast_h_coord(d, c, h);
	if (h->h_hit == -1)
		return ;
	h->h_hit = 0;
	min = 0;
	if (d->ray->fac_up == 1)
		min = 1;
	print_coord(c);
	//printf("first c->y_next = %f | c->x_next = %f\n", c->y_next, c->x_next);
	//printf("first c->y_step = %f | c->x_step = %f\n", c->y_step, c->x_step);
	while ((c->x_next >= 0 && c->x_next < d->map->r_x)
			&& (c->y_next - min >= 0 && c->y_next < d->map->r_y)) // a caster double?
	{
		if (hit_a_wall(c->x_next, c->y_next - min, d->map_tab, d->map) == 1)
		{
			h->h_x_hit = c->x_next;
			h->h_y_hit = c->y_next;
			h->h_hit = 1;
			printf("ray horizontal ok | h->h_hit = %d\n", h->h_hit);
			return ;
		}
		else
		{
			if (c->x_next + c->x_step >= 0 && c->y_next + c->y_step >= 0)
			{
				c->x_next += c->x_step;
				c->y_next += c->y_step;
				//printf("c->y_next = %f | c->x_next = %f\n", c->y_next, c->x_next);
			}
			else
				break ;
			//my_mlx_pixel_put(mlx, c->y_next, c->x_next, 0x00999999);
		}
	}
	printf("hWARNING!!!!!!!!!!!!!! horizontal exit weird\n");

}

void	ray_cast_v_coord(t_data *d, t_coord *c, t_hit *h)
{
	//find coordinates of the closest vertical grid intersection
	int	tronc;
	(void)h;
	
	printf("ang = %f\n", rad_to_deg(d->ray->angle));
	printf("player x = %f | player y = %f\n", d->player->x, d->player->y);	
	//printf("mlx->player->x = %d | mlx->map->tilecol = %d\n", mlx->player->x, mlx->map->tile_col);
	tronc = d->player->x / d->map->tile_col;
	c->x_intercept =  (tronc * d->map->tile_col);
	if (d->ray->fac_right == 1)
		c->x_intercept += d->map->tile_col;

	c->y_intercept = d->player->y	+ ((-c->x_intercept + d->player->x) * tan((d->ray->angle)));	
//	c->y_intercept = mlx->player->y	+ ((c->x_intercept - mlx->player->x) * tan((within_rad(mlx->ray->ray_ang - deg_to_rad(90)))));	
//	if (c->y_intercept >= mlx->map->r_y)
//	{
//		h->v_hit = -1;
//		return ;
//	}
	//Calculate x step and y step
	c->x_step = d->map->tile_col;
	if (d->ray->fac_left == 1)
		c->x_step *= -1;
	c->y_step = d->map->tile_col * tan((d->ray->angle));
//	c->y_step = mlx->map->tile_col * tan(within_rad(mlx->ray->ray_ang - deg_to_rad(90)));
	if (d->ray->fac_up == 1 && c->y_step > 0)
		c->y_step *= -1;
	if (d->ray->fac_down == 1 && c->y_step < 0)
		c->y_step *= -1;
	c->x_next = c->x_intercept;
	c->y_next = c->y_intercept;
//	my_mlx_pixel_put(mlx, c->x_next, c->y_next, 0x00999999);
}

void	ray_cast_vertical(t_data *d, t_coord *c, t_hit *h)
{
	double	min;

	ray_cast_v_coord(d, c, h);
//	if (h->v_hit == -1)
//		return ;
	h->v_hit = 0;
	min = 0;
	if (d->ray->fac_left == 1)
		min = 1;
	print_coord(c);
	//printf("first c->y_next = %f | c->x_next = %f\n", c->y_next, c->x_next);
	//printf("first c->y_step = %f | c->x_step = %f\n", c->y_step, c->x_step);
	while ((c->x_next - min  >= 0 && c->x_next < d->map->r_x)
			&& (c->y_next >= 0 && c->y_next < d->map->r_y))
	{
		if (hit_a_wall(c->x_next - min, c->y_next, d->map_tab, d->map) == 1)
		{
			h->v_x_hit = c->x_next;
			h->v_y_hit = c->y_next;
			h->v_hit = 1;
			printf("ray vertical ok | h->v_hit = %d\n", h->v_hit);
			return ;
		}
		else
		{
			//my_mlx_pixel_put(mlx, c->y_next, c->x_next, 0x00000000);
//			printf("here\n");
			if (c->x_next + c->x_step >= 0 && c->y_next + c->y_step >= 0)
			{
				c->x_next += c->x_step;
				c->y_next += c->y_step;
				//printf("c->y_next = %f | c->x_next = %f\n", c->y_next, c->x_next);
			}
			else
				break ;
//			printf("with c->y_next = %f | c->x_next = %f\n", c->y_next, c->x_next);
		}
		
	}
	printf("WARNING!!!!!!!!!!!!!! vertical exit weird\n");
//	printf("with c->y_next = %f | c->x_next = %f\n", c->y_next, c->x_next);
}
