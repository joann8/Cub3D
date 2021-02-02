/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:10:14 by jacher            #+#    #+#             */
/*   Updated: 2021/02/01 16:12:52 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

/*
double	calculate_sprite_angle(t_data *d, int i)
{
	double sprite_angle;
	double temp_angle;

	temp_angle = within_rad(d->ray->angle - d->player->angle); // pas sur
	if (d->ray->angle > M_PI / 4 && d->ray->angle < (3 * M_PI) / 4)
		sprite_angle = temp_angle;
	else if (d->ray->angle > (3 * M_PI) / 4 && d->ray->angle < (M_PI * 5) / 4)
		sprite_angle = within_rad(temp_angle + M_PI / 2);
	else if (d->ray->angle > (M_PI * 5) / 4 && d->ray->angle < (M_PI * 7) / 4)
		sprite_angle = within_rad(temp_angle + M_PI);
	else
		sprite_angle = within_rad(temp_angle +  3 * (M_PI / 2));
	d->sprite[i].x_toplayer = d->sprite[i].x_d - d->player->x;
	d->sprite[i].y_toplayer = d->sprite[i].y_d - d->player->y;
	//temp_angle = atan2(d->sprite[i].y_toplayer, d->sprite[i].x_toplayer);
	//sprite_angle = temp_angle - d->player->angle;
	return (sprite_angle);
}*/

double	calculate_sprite_angle(t_data *d, int i)
{
	double sprite_angle;
	double temp_angle;

	d->sprite[i].x_toplayer = fabs(d->sprite[i].x_d - d->player->x);
	d->sprite[i].y_toplayer = fabs(d->sprite[i].y_d - d->player->y);
	temp_angle = atan2(d->sprite[i].y_toplayer, d->sprite[i].x_toplayer);
	sprite_angle = within_rad(temp_angle - d->player->angle);
	printf("sprite angle = %f\n", sprite_angle);
	return (sprite_angle);
}


void	calculate_sprite_lim(t_data *d, int i)
{

	d->sprite[i].lim_top_x = d->sprite[i].x_d - d->sprite[i].length / 2;
	d->sprite[i].lim_top_y = d->sprite[i].y_d - d->sprite[i].height / 2;
	d->sprite[i].lim_bot_x = d->sprite[i].x_d + d->sprite[i].length / 2;
	d->sprite[i].lim_bot_y = d->sprite[i].y_d + d->sprite[i].height / 2;
	printf("sprite limits:\n   top x = %f\n   top y = %f\n   bot x = %f\n   bot y = %f\n", d->sprite[i].lim_top_x, d->sprite[i].lim_top_y,d->sprite[i].lim_bot_x,d->sprite[i].lim_bot_y);
	printf("(  x spr = %f)\n(  y spr = %f)\n", d->sprite[i].x_d, d->sprite[i].y_d);
	
	
	/*d->sprite[i].lim_top_x = d->sprite[i].x_d + cos(within_rad(d->player->angle + M_PI /2)) * d->map->tile_s_c;
	d->sprite[i].lim_top_y = d->sprite[i].y_d + sin(within_rad(d->player->angle + M_PI /2)) * d->map->tile_s_l;
	d->sprite[i].lim_bot_x = d->sprite[i].x_d + cos(within_rad(d->player->angle - M_PI /2)) * d->map->tile_s_c;
	
	d->sprite[i].lim_bot_x = d->sprite[i].y_d + sin(within_rad(d->player->angle - M_PI /2)) * d->map->tile_s_l;*/
	
}

int	sprite_ray(t_data *d, double x_h, double y_h)
{
	int i;
	int x;
	int y;
	double corrected_dist;
	double dist_proj_plan;

	x = x_h / d->map->tile_col;
	y = y_h / d->map->tile_lin;
	dist_proj_plan = (d->map->r_x / 2) / tan((d->player->fov / 2));
	//printf("x = %i | y = %d \n",x, y);
	i = 0;
	while (i < d->map->sprite)
	{
	//	printf("s.x = %i | s.y = %d \n",d->sprite[i].x_i, d->sprite[i].y_i);
		if (x == d->sprite[i].x_i && y == d->sprite[i].y_i && d->sprite[i].visible == 0)
		{
		//	printf("new sprite!\n");
			d->sprite[i].visible = 1;
			d->sprite[i].dist = calculate_distance(d->sprite[i].x_d, d->player->x, d->sprite[i].y_d, d->player->y);
		//	d->sprite[i].angle = within_rad(d->ray->angle - d->player->angle); // pas sur
			d->sprite[i].angle = calculate_sprite_angle(d, i);
			printf("cos sprite angle = %f\n", cos(d->sprite[i].angle));
			corrected_dist = d->sprite[i].dist * cos(d->sprite[i].angle);
		//	corrected_dist = d->sprite[i].dist * cos(d->ray->angle);
		printf("corrected dist = %f\n", corrected_dist);
		//	d->sprite[i].height = (((d->map->tile_col / corrected_dist) * dist_proj_plan));
		d->sprite[i].height = (((d->map->tile_col / corrected_dist) * dist_proj_plan));
	//		d->sprite[i].height = dist_proj_plan / corrected_dist;
			d->sprite[i].length = (((d->map->tile_lin / corrected_dist) * dist_proj_plan));
			d->sprite[i].first_x = dist_proj_plan * tan(d->sprite[i].angle) + d->map->r_x /2 - d->sprite[i].height / 2;
		//	d->sprite[i].length = (((d->map->tile_lin / corrected_dist) * dist_proj_plan));
			//d->sprite[i].size = ((d->map->r_x / 2) / tan((d->player->fov / 2))) / (cos(d->sprite[i].angle) * d->sprite[i].dist);
			//d->sprite[i].x_f = tan(d->sprite[i].angle) *  ((d->map->r_x / 2) / tan((d->player->fov / 2))); 
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

int calculate_x_sprite(t_data *d, int i)
{
	int				x_color;
	int				tronc;

	if (d->sprite[i].angle < M_PI / 4 || d->sprite[i].angle > (7 * M_PI) / 4)
	{
		tronc = (d->ray->x_hit) / d->map->tile_col;
		if (d->ray->angle < (3 * M_PI) /4 && d->ray->angle > M_PI/ 4)
		{
			x_color = ((d->ray->x_hit) - (d->map->tile_col) * tronc) * (d->t->length_spr / d->map->tile_col);
		}
			else
			x_color = (-(d->ray->x_hit) + (d->map->tile_col) * (tronc + 1 )) * (d->t->length_spr / d->map->tile_col);
		}
		if (d->ray->hit_vert == 1)
		{
			tronc = (d->ray->y_hit) / d->map->tile_lin;
			if (d->ray->angle < M_PI / 2 || d->ray->angle > (3 * M_PI) / 2)
				x_color = ((d->ray->y_hit) - (d->map->tile_lin * tronc)) * (d->t->length_spr / d->map->tile_lin);
			else
				x_color = (-(d->ray->y_hit) + (d->map->tile_lin * (tronc + 1)))* (d->t->length_spr / d->map->tile_lin);
		}
	return (x_color);
}
	
void	draw_sprite(t_data *d, int i, double start_x)
{
	unsigned int	color;
	int				x_color;
	int				y_color;
	int				tronc;
	unsigned int	k;
	int				start_y;
	
	(void)start_x;
	k = 0;
//	x_color = calculate_x_sprite(d, i);
	
	tronc = d->ray->x_hit / d->map->tile_col;
//	tronc = d->ray->x_hit / d->map->tile_col;
	printf("tronc = %d | d->ray->x_hit = %f | d->map->tile_s_c = %d\n", tronc, d->ray->x_hit, d->map->tile_col);
	x_color = ((d->ray->x_hit - d->map->tile_col * tronc) *(d->t->length_spr / d->map->tile_col));
	//printf("x_color = %d\n", x_color);
	//printf("sprite text height = %d\n", d->t->height_spr);
	//start_y = d->sprite[i].y_d - d->sprite[i].height / 2;
	start_y = d->map->r_y / 2- d->sprite[i].height / 2;
	while (k < d->sprite[i].height && (unsigned int)start_y < d->map->r_y)
	{
		//printf("   k = %u | d->sprite[%d].height = %f \n   d->t->height_spr = %d\n",k,i, d->sprite[i].height ,d->t->height_spr);
		if (start_y >= 0)
		{
			y_color = k * (d->t->height_spr / d->sprite[i].height);
			color = mlx_img_get_pixel_value(d->t->text_spr, x_color, y_color);
	//	printf("color = %u | color no = %u\n", color, d->map->spr_col_no);
			if (color != 0 && color != d->map->spr_col_no)
				my_mlx_pixel_put(d, d->ray->column_id, start_y, color);
		}
		k++;
		start_y++;
	}
}
/*
	while (	d->sprite[i].lim_top_y + k < 0)
		k++;
	while (k < d->sprite[i].height && d->map->r_y -  start_y > 0) //d->sprite[i].lim_top_y + k < d->map->r_y)
	{
		//printf("   k = %u | d->sprite[%d].height = %f \n   d->t->height_spr = %d\n",k,i, d->sprite[i].height ,d->t->height_spr);
		y_color = k * (d->t->height_spr / d->sprite[i].height);
		color = mlx_img_get_pixel_value(d->t->text_spr, x_color, y_color);
	//	printf("color = %u | color no = %u\n", color, d->map->spr_col_no);
		if (color != 0 && color != d->map->spr_col_no)
			my_mlx_pixel_put(d, d->ray->column_id, start_y + k, color);
		k++;
	}
}*/

double	check_column(t_data *d, int i)
{
	int		tronc; 
	double	temp;

	tronc = d->ray->x_hit / d->map->tile_col;
	temp = d->sprite[i].first_x + d->ray->x_hit - d->map->tile_col * tronc;
	return (temp);
}

void mlx_sprite(t_data *d)
{
//	double			dist_proj_plan;
//	double			corrected_dist;
	double			start_x;
//	double			start_y;
	int			 	i;

	i = find_max(d);
//	dist_proj_plan = (d->map->r_x / 2) / tan((d->player->fov / 2));
	//printf("distance to projection plan = %f\n", dist_proj_plan);
	while (i >= 0)
	{	
	//	corrected_dist = d->sprite[i].dist * cos(d->sprite[i].angle);
	//	printf("corrected dist = %f\n", corrected_dist);
		//d->sprite[i].height = (((d->map->tile_s_c / corrected_dist) * dist_proj_plan));
		//d->sprite[i].height = dist_proj_plan / corrected_dist;
	//	d->sprite[i].length = (((d->map->tile_s_l / corrected_dist) * dist_proj_plan));
	//	start_y = d->sprite[i].y_d - d->sprite[i].height / 2;
	//	start_x = d->sprite[i].x_d - d->sprite[i].length / 2;
	//	start_x = dist_proj_plan * tan(d->sprite[i].angle) + (d->map->r_x / 2) -d->sprite[i].height / 2;
		calculate_sprite_lim(d, i);
		printf("**SPRITE TO PRINT**\n");
		printf("d->sprite[%d].height = %f\n", i, d->sprite[i].height);
		printf("d->sprite[%d].length = %f\n", i, d->sprite[i].length);
	//	printf("start_x = %f | start_y = %f\n", start_x, start_y);
		//if (start_y < 0)
		//	start_y = 0;
		//if (start_x < 0)
		//	start_x = 0;
		start_x = check_column(d, i);
		if (start_x >= 0)
		{
			if (d->sprite[i].dist < d->ray->dist)
				draw_sprite(d, i, start_x);
		}
		i = find_max(d);
	}
}
