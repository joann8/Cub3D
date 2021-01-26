/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:29:11 by jacher            #+#    #+#             */
/*   Updated: 2021/01/26 15:28:28 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_column(t_data *d, t_hit *h)
{
	unsigned int start;
	unsigned int i;
	unsigned int j;
	int			color;
	(void)h;

	if (d->ray->height > d->map->r_y)
	{
		d->ray->height = d->map->r_y - 1;
		start = 0;
	}
	else 
		start = (d->map->r_y / 2) - ((d->ray->height / 2));
	//printf("         start = %d\n         wall height = %f\n        column id = %d\n", start, d->ray->height, d->ray->column_id);
	i = 0;
	while (i < d->ray->res)
	{
		j = 0;
		while (j < start && j < d->map->r_y)
		{
		//	printf(" line i = %d | column j = %d\n", i, j);
			color = create_trgb(0, d->map->c_r, d->map->c_g, d->map->c_b);
			my_mlx_pixel_put(d, d->ray->column_id + i, j, color);
			j++;
		}
		draw_wall(d,i,j, start);
		j = j + d->ray->height;
		/*
		while (j < d->ray->height + start && j < d->map->r_y)
		{
			if (d->ray->hit_vert == 1)
			{
				if (d->ray->fac_left == 1 || d->ray->angle == M_PI)
					my_mlx_pixel_put(d, d->ray->column_id + i, j,0x00ff0000); // RED
				if (d->ray->fac_right == 1 || d->ray->angle == 0)
					my_mlx_pixel_put(d, d->ray->column_id + i, j,0x000000ff); // REDish
			}
			else if (d->ray->hit_vert == -1)
			{
				if (d->ray->fac_up == 1 || d->ray->angle == M_PI / 2)
					my_mlx_pixel_put(d, d->ray->column_id + i, j,0x00ffff00); // Yellow
				if (d->ray->fac_down == 1 || d->ray->angle == (3 * M_PI) / 2)
					my_mlx_pixel_put(d, d->ray->column_id + i, j,0x0000ff00); // yellowish
			}
				//my_mlx_pixel_put(d, (int)(d->ray->column_id + i), (int)j,0x0000ff00);
			j++;
		}*/
		while (j < d->map->r_y)
		{
		//	printf(" line i = %d | column j = %d\n", i, j);
			color = create_trgb(0, d->map->f_r, d->map->f_g, d->map->f_b);
			my_mlx_pixel_put(d, d->ray->column_id + i, j, color);
			j++;
		}
		i++;
	}
//	printf("exit draw column\n");
}

int	ray_wall(t_data *d, t_hit *h)
{
	double	dist_proj_plan;
	double	corrected_dist;	


//	printf("mlx map r_x = %d | mlx->ray->fov = %f\n", mlx->map->r_x, mlx->ray->fov);
	//printf("tan = %f\n", tan(deg_to_rad(30)));
	//printf("tan = %f\n", tangent(30));
	dist_proj_plan = (d->map->r_x / 2) / tan((d->player->fov / 2));
//	printf("dist proj plan = %f | mlx->ray->dist = %f\n", dist_proj_plan, mlx->ray->dist);

	corrected_dist = d->ray->dist * cos(d->ray->angle - d->player->angle);
	d->ray->height = (((d->map->tile_col / corrected_dist) * dist_proj_plan));
// A REVOIR
	

	draw_column(d,h);
	return (1);
}

