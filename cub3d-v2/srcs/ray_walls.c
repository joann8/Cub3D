/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:29:11 by jacher            #+#    #+#             */
/*   Updated: 2021/01/20 18:16:30 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_column(t_mlx *mlx, float wall_height, int column_id, t_hit *h)
{
	int start;
	int i;
	int j;

	if (wall_height > (float)mlx->map->r_y)
	{
		wall_height = (float)mlx->map->r_y;
		start = 0;
	}
	else 
		start = (mlx->map->r_y / 2) - (((int)wall_height / 2));
//	printf("         start = %d\n         wall height = %f\n          column id = %d\n", start, wall_height, column_id);
	i = 0;
	while (i < mlx->ray->res)
	{
		j = 0;
		while (j < start && j < (int)mlx->map->r_y)
		{
		//	printf(" line i = %d | column j = %d\n", i, j);
			my_mlx_pixel_put(mlx, mlx->map->r_x - column_id - i, j,0x00696969);
			j++;
		}
		while (j < (int)wall_height + start && j < (int)mlx->map->r_y)
		{
			if (h->v_hit == 0)
				my_mlx_pixel_put(mlx, mlx->map->r_x - column_id - i, j,0x00ff0000);
			if (h->h_hit == 0)
				my_mlx_pixel_put(mlx, mlx->map->r_x - column_id - i, j,0x00ffff00);
			else
				my_mlx_pixel_put(mlx, mlx->map->r_x - column_id - i, j,0x0000ff00);
			j++;
		}
		while (j < (int)mlx->map->r_y)
		{
		//	printf(" line i = %d | column j = %d\n", i, j);
			my_mlx_pixel_put(mlx, mlx->map->r_x - column_id - i, j, 0x00000000);
			j++;
		}
		i++;
	}
//	printf("exit draw column\n");
}

int	ray_wall(t_mlx *mlx, int column_id, t_hit *h)
{
	float wall_height;
	float	dist_proj_plan;

//	printf("mlx map r_x = %d | mlx->ray->fov = %f\n", mlx->map->r_x, mlx->ray->fov);
	//printf("tan = %f\n", tan(deg_to_rad(30)));
	//printf("tan = %f\n", tangent(30));
	dist_proj_plan = (mlx->map->r_x / 2) / tan(deg_to_rad(mlx->ray->fov / 2));
//	printf("dist proj plan = %f | mlx->ray->dist = %f\n", dist_proj_plan, mlx->ray->dist);
	wall_height = ((mlx->map->tile_col / mlx->ray->dist) * dist_proj_plan);
	printf("wall height = %f for angle %f\n", wall_height, rad_to_deg(mlx->ray->ray_ang));
	draw_column(mlx, wall_height, column_id, h);
	return (1);
}

