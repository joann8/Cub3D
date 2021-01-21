/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:29:11 by jacher            #+#    #+#             */
/*   Updated: 2021/01/21 16:13:11 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_column(t_data *d, t_hit *h)
{
	unsigned int start;
	unsigned int i;
	unsigned int j;

	if (d->ray->height > d->map->r_y)
	{
	//	d->ray->height = d->map->r_y;
		start = 0;
	}
	else 
		start = (d->map->r_y / 2) - ((d->ray->height / 2));
	printf("         start = %d\n         wall height = %f\n        column id = %d\n", start, d->ray->height, d->ray->column_id);
	i = 0;
	while (i < d->ray->res)
	{
		j = 0;
		while (j < start && j < d->map->r_y)
		{
		//	printf(" line i = %d | column j = %d\n", i, j);
			my_mlx_pixel_put(d, d->ray->column_id + i, j,0x00696969);
			j++;
		}
		while (j < d->ray->height + start && j < d->map->r_y)
		{
			if (h->v_hit == 0) //RED
				my_mlx_pixel_put(d, d->ray->column_id + i, j,0x00ff0000);
			if (h->h_hit == 0) //yellow
				my_mlx_pixel_put(d, d->ray->column_id + i, j,0x00ffff00);
			else //GREEN
				my_mlx_pixel_put(d, (int)(d->ray->column_id + i), (int)j,0x0000ff00);
			j++;
		}
		while (j < d->map->r_y)
		{
		//	printf(" line i = %d | column j = %d\n", i, j);
			my_mlx_pixel_put(d, d->ray->column_id + i, j, 0x00000000);
			j++;
		}
		i++;
	}
//	printf("exit draw column\n");
}

int	ray_wall(t_data *d, t_hit *h)
{
	double	dist_proj_plan;
	int 	test;
	unsigned int test2;

//	printf("mlx map r_x = %d | mlx->ray->fov = %f\n", mlx->map->r_x, mlx->ray->fov);
	//printf("tan = %f\n", tan(deg_to_rad(30)));
	//printf("tan = %f\n", tangent(30));
	dist_proj_plan = (d->map->r_x / 2) / tan((d->player->fov / 2));
//	printf("dist proj plan = %f | mlx->ray->dist = %f\n", dist_proj_plan, mlx->ray->dist);


	d->ray->height = (((d->map->tile_col / d->ray->dist) * dist_proj_plan));
	test = (((d->map->tile_col / d->ray->dist) * dist_proj_plan));
	test2 = (((d->map->tile_col / d->ray->dist) * dist_proj_plan));
// A REVOIR
	

	draw_column(d,h);
	return (1);
}

