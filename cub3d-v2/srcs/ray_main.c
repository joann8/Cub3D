/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:58:11 by jacher            #+#    #+#             */
/*   Updated: 2021/01/26 16:13:51 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		cast_all_rays(t_data *d)
{
	double	ray_ang_advance;
	int		i;
	int 	num_rays;
	float		dist_plan;
	float		pixel;
	//printf("main : enter raycasting\n");
	f_reset_ray(d->ray);
//	print_player(d->player);

	//printf("d_mlx ray fov = %f\n", mlx->ray->fov);
	//printf("r->d : mlx player ang = %f\n", rad_to_deg(mlx->player->dir_ang));
	//printf("main : r->d : player ang = %f\n", rad_to_deg(d->player->angle));
	d->ray->angle = within_rad(d->player->angle + d->player->fov / 2);
//	printf("main : r->d : ray ang = %f\n", rad_to_deg(d->ray->angle));
	//loop for all rays 
	i = 0;
	num_rays = d->map->r_x / d->ray->res;
	

	// test
	dist_plan = (d->map->r_x / 2) / tan(d->player->fov / 2);
	pixel = d->map->r_x / num_rays;
		
	ray_ang_advance = ((d->player->fov * d->ray->res) / d->map->r_x);

//	printf("r_x = %d | d_ray-res = %u\n", d->map->r_x, d->ray->res);

	//printf("main : r->d : ray_ang_advance = %f\n*****\n", rad_to_deg(ray_ang_advance));
	while (i < num_rays)
	{
	//	printf("\nwhile : tour %d : r->d mlx ray ang = %f\n", i, rad_to_deg(mlx->ray->ray_ang));
		d->ray->angle = within_rad(d->player->angle + atan(((num_rays / 2) - i) / dist_plan)); // a verifier
		f_reset_ray(d->ray);
		d->ray->column_id = i * d->ray->res;
		cast_a_ray(d); // column ID
		//my_mlx_pixel_put(mlx, mlx->ray->x_hit, mlx->ray->y_hit, 0x00000000 );
		i++; 
		
		//d->ray->angle = within_rad(d->ray->angle - ray_ang_advance); // a verifier
		/* test
		ray_ang_advance = atan((d->map->r_x /2 - i * pixel)/ dist_plan); 
		d->ray->angle = within_rad(ray_ang_advance); // a verifier
		*/
		// + de droite a  gauche	
		//mlx_draw_line(mlx);
		//if (i == 5 )
		//	break ; // pour un seul
	}
//	printf("number of rays casted = %d\n", i);
	return (1);
}

