/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:58:11 by jacher            #+#    #+#             */
/*   Updated: 2021/01/20 19:39:36 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		cast_all_rays(t_mlx *mlx)
{
	float	ray_ang_advance;
	int		i;
	int 	num_rays;

	printf("main : enter raycasting\n");
	mlx->ray->fov = 66;
	print_player(mlx->player);
	//printf("d_mlx ray fov = %f\n", mlx->ray->fov);
	//printf("r->d : mlx player ang = %f\n", rad_to_deg(mlx->player->dir_ang));
	printf("main : r->d : mlx ray ang = %f\n", rad_to_deg(mlx->player->dir_ang));
	mlx->ray->ray_ang = within_rad(mlx->player->dir_ang - deg_to_rad(mlx->ray->fov / 2));
	printf("main : r->d : mlx ray ang = %f\n", rad_to_deg(mlx->ray->ray_ang));
	//loop for all rays 
	i = 0;
	mlx->ray->res = 20; //un rayon tous les res pixels
	num_rays = mlx->map->r_x / mlx->ray->res; 
	ray_ang_advance = deg_to_rad((mlx->ray->fov * mlx->ray->res) / mlx->map->r_x);
	//printf("main : r->d : ray_ang_advance = %f\n*****\n", rad_to_deg(ray_ang_advance));
	while (i < num_rays)
	{
	//	printf("\nwhile : tour %d : r->d mlx ray ang = %f\n", i, rad_to_deg(mlx->ray->ray_ang));
		mlx->ray->fac_up = 0;
		mlx->ray->fac_down = 0;
		mlx->ray->fac_right = 0;
		mlx->ray->fac_left = 0;
		mlx->ray->x_hit = 0;
		mlx->ray->y_hit = 0;
		mlx->ray->dist = 0;
		mlx->ray->hit_vert = 0;
		cast_a_ray(mlx, i * mlx->ray->res); // column ID
		//my_mlx_pixel_put(mlx, mlx->ray->x_hit, mlx->ray->y_hit, 0x00000000 );
		mlx->ray->ray_ang = within_rad(mlx->ray->ray_ang + ray_ang_advance);
		// + de droite a  gauche	
		i++;
		//mlx_draw_line(mlx);
		//if (i == 5 )
		//	break ; // pour un seul
	}
//	printf("number of rays casted = %d\n", i);
	return (1);
}

