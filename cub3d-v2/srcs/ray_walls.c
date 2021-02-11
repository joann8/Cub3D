/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:29:11 by jacher            #+#    #+#             */
/*   Updated: 2021/02/11 22:28:12 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		calculate_x_wall(t_data *d)
{
	int				x_color;
	int				tronc;

	if (d->ray->hit_vert == -1)
	{
		tronc = (d->ray->x_hit) / BLOCK;
		if (d->ray->angle > 0 && d->ray->angle < M_PI)
			x_color = ((d->ray->x_hit) - (BLOCK * tronc)) *
				(d->t->length / BLOCK);
		else
			x_color = (-(d->ray->x_hit) + (BLOCK * (tronc + 1)))
				* (d->t->length / BLOCK);
	}
	if (d->ray->hit_vert == 1)
	{
		tronc = (d->ray->y_hit) / BLOCK;
		if (d->ray->angle < M_PI / 2 || d->ray->angle > (3 * M_PI) / 2)
			x_color = ((d->ray->y_hit) - (BLOCK * tronc)) *
				(d->t->length / BLOCK);
		else
			x_color = (-(d->ray->y_hit) + (BLOCK * (tronc + 1))) *
				(d->t->length / BLOCK);
	}
	return (x_color);
}

void	draw_wall(t_data *d, int i, int j, int start)
{
	unsigned int	color;
	int				x_color;
	int				y_color;
	int				k;

	x_color = calculate_x_wall(d);
	k = 0;
	while (start + k < 0)
		k++;
	while (k < d->ray->height && j < (int)d->map->r_y)
	{
		if (start + k >= (int)d->map->r_y)
			return ;
		if (start + k >= 0)
		{
			y_color = k * (d->t->height / d->ray->height);
			color = mlx_img_get_pixel_value(d->t->text, x_color, y_color);
			my_mlx_pixel_put(d, d->ray->column_id + i, j, color);
		}
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

void	draw_column(t_data *d, int start)
{
	int				j;
	int				color;

	j = 0;
	while (j < start && j < (int)d->map->r_y)
	{
		color = create_trgb(0, d->map->c_r, d->map->c_g, d->map->c_b);
		my_mlx_pixel_put(d, d->ray->column_id, j, color);
		j++;
	}
	draw_wall(d, 0, j, start);
	j = j + d->ray->height;
	while (j < (int)d->map->r_y)
	{
		color = create_trgb(0, d->map->f_r, d->map->f_g, d->map->f_b);
		my_mlx_pixel_put(d, d->ray->column_id, j, color);
		j++;
	}
}
