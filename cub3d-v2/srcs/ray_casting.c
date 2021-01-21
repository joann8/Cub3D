/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:28:05 by jacher            #+#    #+#             */
/*   Updated: 2021/01/21 16:28:01 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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
	print_ray_orientation(d->ray); 
/*
	if (mlx->ray->ray_ang > (M_PI / 2) && mlx->ray->ray_ang < ((3 * M_PI) / 2))
	{
		mlx->ray->fac_up = 1;
		mlx->ray->fac_down = -1;
	}
	else if (mlx->ray->ray_ang < (M_PI / 2)
				|| mlx->ray->ray_ang > ((3 * M_PI) / 2))
	{
		mlx->ray->fac_up = -1;
		mlx->ray->fac_down = 1;
	}
	if (mlx->ray->ray_ang < M_PI)
	{
		mlx->ray->fac_right = 1;
		mlx->ray->fac_left = -1;
	}
	else if (mlx->ray->ray_ang > M_PI)
	{
		mlx->ray->fac_right = -1;
		mlx->ray->fac_left = 1;
	}
	print_ray_orientation(mlx->ray);*/
}

int		calculate_distance(t_data *d, t_hit *h)
{
	if (h->h_hit == 1)
	{
		h->h_dist = sqrt((h->h_x_hit - d->player->x)
			* (h->h_x_hit - d->player->x)
			+ ((h->h_y_hit - d->player->y)
			* (h->h_y_hit - d->player->y)));
		//printf("h->h_dist = %f\n", h->h_dist);
	}
	if (h->v_hit == 1)
	{
		h->v_dist = sqrt((h->v_x_hit - d->player->x)
			* (h->v_x_hit - d->player->x)
			+ ((h->v_y_hit - d->player->y)
			* (h->v_y_hit - d->player->y)));
		//printf("h->v_dist = %f\n", h->v_dist);
	}
	if ((h->v_hit == 1) && (h->h_hit != 1 || h->h_dist >= h->v_dist))
	{
		d->ray->x_hit = h->v_x_hit;
		d->ray->y_hit = h->v_y_hit;
		d->ray->dist = h->v_dist;
		d->ray->hit_vert = 1;
		printf("-------final distance from vertical = %f\n", d->ray->dist);
	}
	else if ((h->h_hit == 1) && (h->v_hit != 1 || h->h_dist < h->v_dist))
	{
		d->ray->x_hit = h->h_x_hit;
		d->ray->y_hit = h->h_y_hit;
		d->ray->dist = h->h_dist;
		d->ray->hit_vert = -1;
		printf("--------final distance from horizontal = %f\n", d->ray->dist);
	}
	return (1);
}

int		cast_a_ray(t_data *d)
{
	t_coord	c_v;
	t_coord	c_h;
	t_hit	h;
	
	printf("***enter cast a ray***\n");
	h.v_hit = 0;
	h.h_hit = 0;
	ray_orientation(d);
	//printf("ok1\n");
//	printf("cast a ray : mlx->ray->ray_ang = %f\n", rad_to_deg(mlx->ray->ray_ang));
	
	ray_cast_horizontal(d, &c_h, &h);
//	print_coord(&c_h);
	ray_cast_vertical(d, &c_v, &h);
//	print_coord(&c_v);
//	print_ray(mlx->ray);
	/*
	if ((mlx->ray->ray_ang - (M_PI / 2) < 0.0001 &&  mlx->ray->ray_ang - (M_PI / 2) > -0.0001)
			|| (mlx->ray->ray_ang - ((3 * M_PI) / 2) < 0.0001 && mlx->ray->ray_ang - ((3 * M_PI) / 2) > -0.0001))
	{
		printf("no horizontal\n");
		h.h_hit = 0;
	}
	else
	{
		printf("horizontal yes\n");
		ray_cast_horizontal(mlx, &c_h, &h);
	}
	if ((mlx->ray->ray_ang < 0.0001 && mlx->ray->ray_ang > -0.0001)
	 		|| (mlx->ray->ray_ang - M_PI < 0.0001 && mlx->ray->ray_ang - M_PI > -0.0001)
	 		|| (mlx->ray->ray_ang - (2 * M_PI) < 0.0001 && mlx->ray->ray_ang - (2 * M_PI) > -0.0001))
	{
		printf("no vertical\n");
		h.v_hit = 0;
	}
	else
	{
		printf("vertical yes\n");
		ray_cast_vertical(mlx, &c_v, &h);
	}*/
//	printf("ok2\n");
	//printf("ok3\n");
	printf("=====> h_v_hit == %d & h_h_hit = %d\n", h.v_hit, h.h_hit);
	if (h.h_hit == 1 || h.v_hit == 1)
	{
		if (calculate_distance(d, &h) == -1)
			return (-1);
		//print_hit(&h);
	}
	ray_wall(d, &h);
	printf(">> exit cast a ray\n");
	return (1);
}
