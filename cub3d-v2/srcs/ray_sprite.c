/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:10:14 by jacher            #+#    #+#             */
/*   Updated: 2021/02/10 19:17:13 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		sprite_ray(t_data *d, double x_h, double y_h)
{
	int i;
	int x;
	int y;

	x = x_h / d->map->tile_col;
	y = y_h / d->map->tile_lin;
	i = 0;
	while (i < d->map->sprite)
	{
		if (x == d->sprite[i].x_i && y == d->sprite[i].y_i
				&& d->sprite[i].visible == 0)
		{
			d->sprite[i].visible = 1;
			d->sprite[i].dist = calculate_distance(d->player->x,
				d->sprite[i].x_d, d->player->y, d->sprite[i].y_d);
			return (1);
		}
		i++;
	}
	return (0);
}

int		find_max(t_data *d)
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
	double angle_sprite_to_ortho;
	double angle_player_to_sprite;
	double cor_dist;
	double dist_proj_plan;

	dist_proj_plan = (d->map->r_x / 2) / tan((d->player->fov / 2));
	d->sprite[i].x_toplayer = d->sprite[i].x_d - d->player->x;
	d->sprite[i].y_toplayer = d->sprite[i].y_d - d->player->y;
	angle_sprite_to_ortho = atan2(d->sprite[i].y_toplayer,
		d->sprite[i].x_toplayer);
	angle_player_to_sprite = d->player->angle + angle_sprite_to_ortho;
	d->sprite[i].angle = angle_player_to_sprite;
	d->sprite[i].angle = within_rad(angle_player_to_sprite);
	cor_dist = (d->sprite[i].dist * cos(d->sprite[i].angle));
	d->sprite[i].height = ((dist_proj_plan / cor_dist) * d->map->tile_col);
	d->sprite[i].length = ((dist_proj_plan / cor_dist) * d->map->tile_lin);
	d->sprite[i].first_x = d->map->r_x / 2 + dist_proj_plan *
		tan(d->sprite[i].angle) - d->sprite[i].length / 2;
}

void	draw_sprite(t_data *d, int i, double col, double start_x)
{
	unsigned int	color;
	int				x_color;
	int				y_color;
	int				k;
	int				start_y;

	k = 0;
	x_color = col * (d->t->length_spr / d->sprite[i].length);
	start_y = d->map->r_y / 2 - d->sprite[i].height / 2;
	while (start_y + k < 0)
		k++;
	while (k < d->sprite[i].height && start_y + k < (int)d->map->r_y)
	{
		if (start_y + k >= (int)d->map->r_y)
			return ;
		if (start_y + k >= 0)
		{
			y_color = k * (d->t->height_spr / d->sprite[i].height);
			color = mlx_img_get_pixel_value(d->t->text_spr, x_color, y_color);
			if (color != d->map->spr_col_no)
				my_mlx_pixel_put(d, start_x + col, start_y + k, color);
		}
		k++;
	}
}

void	mlx_sprite(t_data *d, double *rays)
{
	double	start_x;
	int		i;
	int		k;

	i = find_max(d);
	while (i >= 0)
	{
		k = 0;
		get_sprite_data(d, i);
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
}
