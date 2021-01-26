/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:29:11 by jacher            #+#    #+#             */
/*   Updated: 2021/01/26 17:05:48 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_wall(t_data *d, unsigned int i, unsigned int j, unsigned int start)
{
	unsigned int	color;
	int				x_color;
	int				y_color;
	int				tronc;
	unsigned int	k;

	tronc = (d->ray->x_hit) / d->map->tile_col;
	x_color = ((d->ray->x_hit) - (d->map->tile_col) * tronc)
		* (d->t->length / d->map->tile_col);
	k = 0;
	while (k < d->ray->height && j < d->map->r_y)
	{
		if (start >= d->map->r_y)
			return ;
		if (start >= 0)
		{
			y_color = k * (d->t->height / d->ray->height);
			color = mlx_img_get_pixel_value(d->t->text, x_color, y_color);
			my_mlx_pixel_put(d, d->ray->column_id + i, j, color);
		}
		start++;
		k++;
		j++;
	}
}

void	assign_texture_v(t_data *d)
{
	if (d->ray->fac_left == 1 || d->ray->angle == M_PI)
	{
		d->t->text = d->t->text_w;
		d->t->height = d->t->height_w;
		d->t->length = d->t->length_w;
	}
	else if (d->ray->fac_right == 1 || d->ray->angle == 0)
	{
		d->t->text = d->t->text_e;
		d->t->height = d->t->height_e;
		d->t->length = d->t->length_e;
	}
}

void	assign_texture_h(t_data *d)
{
	if (d->ray->fac_up == 1 || d->ray->angle == M_PI / 2)
	{
		d->t->text = d->t->text_n;
		d->t->height = d->t->height_n;
		d->t->length = d->t->length_n;
	}
	else if (d->ray->fac_down == 1 || d->ray->angle == (3 * M_PI) / 2)
	{
		d->t->text = d->t->text_s;
		d->t->height = d->t->height_s;
		d->t->length = d->t->length_s;
	}
}

void	draw_column(t_data *d, unsigned int start)
{
	unsigned int	i;
	unsigned int	j;
	int				color;

	i = 0;
	while (i < d->ray->res)
	{
		j = 0;
		while (j < start && j < d->map->r_y)
		{
			color = create_trgb(0, d->map->c_r, d->map->c_g, d->map->c_b);
			my_mlx_pixel_put(d, d->ray->column_id + i, j, color);
			j++;
		}
		draw_wall(d, i, j, start);
		j = j + d->ray->height;
		while (j < d->map->r_y)
		{
			color = create_trgb(0, d->map->f_r, d->map->f_g, d->map->f_b);
			my_mlx_pixel_put(d, d->ray->column_id + i, j, color);
			j++;
		}
		i++;
	}
}

int		ray_wall(t_data *d)
{
	double			dist_proj_plan;
	double			corrected_dist;
	unsigned int	start;

	dist_proj_plan = (d->map->r_x / 2) / tan((d->player->fov / 2));
	corrected_dist = d->ray->dist * cos(d->ray->angle - d->player->angle);
	d->ray->height = (((d->map->tile_col / corrected_dist) * dist_proj_plan));
	if (d->ray->height > d->map->r_y)
	{
		d->ray->height = d->map->r_y - 1;
		start = 0;
	}
	else
		start = (d->map->r_y / 2) - ((d->ray->height / 2));
	if (d->ray->hit_vert == 1)
		assign_texture_v(d);
	else if (d->ray->hit_vert == -1)
		assign_texture_h(d);
	draw_column(d, start);
	return (1);
}
