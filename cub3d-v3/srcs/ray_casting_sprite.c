/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:10:14 by jacher            #+#    #+#             */
/*   Updated: 2021/02/02 16:39:42 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	sprite_ray(t_data *d, double x_h, double y_h)
{
	int i;
	int x;
	int y;
	x = x_h / d->map->tile_col;
	y = y_h / d->map->tile_lin;
	//printf("x = %i | y = %d \n",x, y);
	i = 0;
	while (i < d->map->sprite)
	{
	//	printf("s.x = %i | s.y = %d \n",d->sprite[i].x_i, d->sprite[i].y_i);
		if (x == d->sprite[i].x_i && y == d->sprite[i].y_i && d->sprite[i].visible == 0)
		{
			//printf("found a sprite! \n");
			d->sprite[i].visible = 1;
			d->sprite[i].dist = calculate_distance(d->sprite[i].x_d, d->player->x, d->sprite[i].y_d, d->player->y);
			return (1);
		}
		i++;
	}
//	printf("no sprite\n");
	return (0);
}

int	find_max(t_data *d)
{
	double			max;
	int				i;
	int				res;

	max = 0;
	res = -1;
	i = 0;
	while (i < d->map->sprite)
	{
		if (d->sprite[i].visible == 1)
		{
			if (max < d->sprite[i].dist)
			{
				max = d->sprite[i].dist;
				res = i;
			}
		}
		i++;
	}
	if (res >= 0)
		d->sprite[res].visible = 0;
	return (res);
}
	

void	get_sprite_data(t_data *d, int i)
{
	double sprite_angle;
	double temp_angle;	
	double corrected_dist;
	double dist_proj_plan;

	printf("*****get sprite %d data ****\n", i);

	dist_proj_plan = (d->map->r_x / 2) / tan((d->player->fov / 2));
	d->sprite[i].x_toplayer = d->sprite[i].x_d - d->player->x;
	d->sprite[i].y_toplayer = d->sprite[i].y_d - d->player->y;
			printf("x_toplayer = %f | y_toplayer = %f \n", d->sprite[i].x_toplayer, d->sprite[i].y_toplayer);
	temp_angle = atan2(d->sprite[i].y_toplayer, d->sprite[i].x_toplayer);
	sprite_angle = temp_angle - d->player->angle;
	if (sprite_angle < -M_PI)
		sprite_angle += 2 * M_PI;
	if (sprite_angle >= M_PI)
		sprite_angle -= 2 * M_PI;
	//sprite_angle = within_rad(temp_angle - d->player->angle);
			printf("sprite angle = %f\n", sprite_angle);
			printf("dist to projected plan = %f\n",dist_proj_plan);
	d->sprite[i].angle = sprite_angle;
			printf("cos sprite angle = %f\n", cos(d->sprite[i].angle));
	corrected_dist = (d->sprite[i].dist * cos(d->sprite[i].angle));
	//		corrected_dist = d->sprite[i].dist * cos(d->ray->angle);
			printf("corrected dist = %f\n", corrected_dist);
		//	d->sprite[i].height = (((d->map->tile_col / corrected_dist) * dist_proj_plan));
		// d->sprite[i].height = (((d->map->tile_col / corrected_dist) * dist_proj_plan));
	d->sprite[i].height = fabs((dist_proj_plan / corrected_dist) * d->map->tile_col);
	d->sprite[i].length = fabs((dist_proj_plan / corrected_dist) * d->map->tile_lin);
	//if (d->player->dir_walk_lr != 0)
		d->sprite[i].first_x = d->map->r_x / 2 +  dist_proj_plan * (tan(d->sprite[i].angle)) - d->sprite[i].length / 2;
	//else
	//	d->sprite[i].first_x = d->map->r_x / 2 - dist_proj_plan * (tan(d->sprite[i].angle)) - d->sprite[i].length / 2;
			printf("tan sprite angle = %f\n", tan(d->sprite[i].angle));
			printf("tan wirthin rad sprite angle = %f\n", tan(within_rad(d->sprite[i].angle)));
			printf("first x = %f\n", d->sprite[i].first_x);
	d->sprite[i].lim_top_x =  d->map->r_x /2 - d->sprite[i].height / 2;
		//	d->sprite[i].length = (((d->map->tile_lin / corrected_dist) * dist_proj_plan));
	printf("***** exit get sprite %d data ****\n", i);
}


void	draw_sprite(t_data *d, int i, double col, double start_x)
{
	unsigned int	color;
	int				x_color;
	int				y_color;
//	int				tronc;
	int	k;
//	unsigned int 	j;
	int				start_y;
	
	k = 0;
//	x_color = calculate_x_sprite(d, i);

//	tronc = start_x / d->map->tile_col;
//	tronc = d->ray->x_hit / d->map->tile_col;
	//printf("tronc = %d | d->ray->x_hit = %f | d->map->tile_s_c = %d\n", tronc, d->ray->x_hit, d->map->tile_col);
	//x_color = ((start_x - d->map->tile_col * tronc) * (d->t->length_spr / d->map->tile_col));
	//printf("x_color = %d\n", x_color);
	//printf("sprite text height = %d\n", d->t->height_spr);
	//start_y = d->sprite[i].y_d - d->sprite[i].height / 2;
	x_color = col * (d->t->length_spr / d->sprite[i].length) ;
	
	start_y = d->map->r_y / 2 - d->sprite[i].height / 2;
	while (start_y + k < 0)
		k++;
	while (k < d->sprite[i].height && start_y + k < (int)d->map->r_y)
	{
		//printf("   k = %u | d->sprite[%d].height = %f \n   d->t->height_spr = %d\n",k,i, d->sprite[i].height ,d->t->height_spr);		
		if (start_y + k >= (int)d->map->r_y)
			return ;
		if (start_y + k >= 0)
		{
			y_color = k * (d->t->height_spr / d->sprite[i].height);
			color = mlx_img_get_pixel_value(d->t->text_spr, x_color, y_color);
			//printf("color = %u | color no = %u\n", color, d->map->spr_col_no);
			if (color != 0 && color != d->map->spr_col_no)
				my_mlx_pixel_put(d, start_x + col, start_y + k, color);
		}
		k++;
	}
}


void mlx_sprite(t_data *d, double *rays)
{
	double			start_x;
	int			 	i;
	int 			k;

	printf("***enter mlx sprite***\n");
	i = find_max(d);
	printf("i = %d\n", i);
	while (i >= 0)
	{	
		k = 0;
		printf("**SPRITE TO PRINT %d**\n", i);
		get_sprite_data(d, i);
		printf("d->sprite[%d].height = %f\n", i, d->sprite[i].height);
		printf("d->sprite[%d].length = %f\n", i, d->sprite[i].length);
		start_x = d->sprite[i].first_x;
		while (start_x + k < 0)
			k++;
		while (start_x + k < d->map->r_x && k < d->sprite[i].length)
		{
			if (d->sprite[i].dist < rays[(int)(start_x + k)])
				draw_sprite(d, i, k, start_x);
			k++;
		}
		i = find_max(d);
	}
	printf("***exit mlx sprite***\n");
}
