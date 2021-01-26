/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_print_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:38:29 by jacher            #+#    #+#             */
/*   Updated: 2021/01/26 14:03:34 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

unsigned int	mlx_img_get_pixel_value(t_img *img, int x, int y)
{
	char *dst;
	
	dst = img->addr + (y * img->length) + (x * 4);
	return(*(unsigned*)dst);
}

void	draw_texture(t_data *d, unsigned int i, unsigned int j, unsigned int start)
{
//	printf(">>enter draw texture\n");
	unsigned int	color;
	int				x_color;
	int				y_color;
	int				tronc;
	//float			ratio;
//	float			help;
	unsigned int	k;

 	// calcul x	
	tronc = (d->ray->x_hit) / d->map->tile_col;
  // 	printf("x hit = %f | tronc= %d\n", d->ray->x_hit, tronc);	
	x_color = ((d->ray->x_hit) - (d->map->tile_col) * tronc)  * (d->t->length / d->map->tile_col);
//	printf("x_color = %d | text width = %d\n", x_color, d->t->length);
	// calcul y
	k = 0;
	while (k < d->ray->height && j < d->map->r_y)
	{
		if (start >= d->map->r_y)
		   return;
		if (start >= 0)
		{	
			y_color = k * (d->t->height / d->ray->height);
	//	printf("y_color = %d | text height = %d\n", y_color, d->t->height);
			/*help = ((k - ((d->map->r_y -1) / 2)) / ratio + (d->map->r_y-1) / 2);
		else
			help = ((((d->map->r_y - 1) / 2) - j ) / ratio + (d->map->r_y-1) / 2);
		tronc = help / d->map->tile_lin;
		y_color =  (help - help * tronc) * (d->t->height / d->map->tile_lin);*/
		//y_color = (j - tronc) * (d->t->height / d->ray->height);
			color = mlx_img_get_pixel_value(d->t->text, x_color, y_color);
		//printf("x_color = %d | y_color = %d | d->text->height = %d | d->text->length = %d\n", x_color, y_color, d->t->height, d->t->length);
			my_mlx_pixel_put(d, d->ray->column_id + i, j, color);
		}
		start++;
		k++;
		j++;
	}
//	printf(">>exit draw texture\n");
}

void	draw_wall(t_data *d, unsigned int i, unsigned int j, unsigned int start)
{
//	printf(">enter draw wall\n");
	if (d->ray->hit_vert == 1
			&& (d->ray->fac_left == 1 || d->ray->angle == M_PI))
	{
		d->t->text = d->t->text_w;
		d->t->height = d->t->height_w;
		d->t->length = d->t->length_w;
	}
	else if (d->ray->hit_vert == 1
				&& (d->ray->fac_right == 1 || d->ray->angle == 0))
	{
		d->t->text = d->t->text_e;
		d->t->height = d->t->height_e;
		d->t->length = d->t->length_e;
	}
	else if (d->ray->hit_vert == -1
				&& (d->ray->fac_up == 1 || d->ray->angle == M_PI / 2))
	{
		d->t->text = d->t->text_n;
		d->t->height = d->t->height_n;
		d->t->length = d->t->length_n;
	}
	else if (d->ray->hit_vert == -1
				&& (d->ray->fac_down == 1 || d->ray->angle == (3 * M_PI) / 2))
	{
		d->t->text = d->t->text_s;
		d->t->height = d->t->height_s;
		d->t->length = d->t->length_s;
	}
//	printf(">end assignations\n");
	draw_texture(d,i,j,start);
//	printf(">exit draw wall\n");
}

