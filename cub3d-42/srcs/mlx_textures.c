/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:11:03 by jacher            #+#    #+#             */
/*   Updated: 2021/02/11 16:09:47 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	create_texture_bis(t_data *d)
{
	d->t->text_n->addr = mlx_get_data_addr(d->t->text_n->ptr,
		&(d->t->text_n->bits), &(d->t->text_n->length),
		&(d->t->text_n->endian));
	d->t->text_s->addr = mlx_get_data_addr(d->t->text_s->ptr,
		&(d->t->text_s->bits), &(d->t->text_s->length),
		&(d->t->text_s->endian));
	d->t->text_w->addr = mlx_get_data_addr(d->t->text_w->ptr,
		&(d->t->text_w->bits), &(d->t->text_w->length),
		&(d->t->text_w->endian));
	d->t->text_e->addr = mlx_get_data_addr(d->t->text_e->ptr,
		&(d->t->text_e->bits), &(d->t->text_e->length),
		&(d->t->text_e->endian));
	d->t->text_spr->addr = mlx_get_data_addr(d->t->text_spr->ptr,
		&(d->t->text_spr->bits), &(d->t->text_spr->length),
		&(d->t->text_spr->endian));
	d->map->spr_col_no = mlx_img_get_pixel_value(d->t->text_spr, 0, 0);
}

int		create_texture(t_data *d)
{
	d->t->text_n->ptr = mlx_xpm_file_to_image(d->mlx->ptr, d->map->no_path,
		&(d->t->length_n), &(d->t->height_n));
	d->t->text_s->ptr = mlx_xpm_file_to_image(d->mlx->ptr, d->map->so_path,
		&(d->t->length_s), &(d->t->height_s));
	d->t->text_w->ptr = mlx_xpm_file_to_image(d->mlx->ptr, d->map->we_path,
		&(d->t->length_w), &(d->t->height_w));
	d->t->text_e->ptr = mlx_xpm_file_to_image(d->mlx->ptr, d->map->ea_path,
		&(d->t->length_e), &(d->t->height_e));
	d->t->text_spr->ptr = mlx_xpm_file_to_image(d->mlx->ptr, d->map->s_path,
		&(d->t->length_spr), &(d->t->height_spr));
	if (d->t->text_n->ptr == NULL || d->t->text_s->ptr == NULL
			|| d->t->text_w->ptr == NULL || d->t->text_e->ptr == NULL
			|| d->t->text_spr->ptr == NULL)
	{
		print_error_mlx(2);
		return (-1);
	}
	create_texture_bis(d);
	return (1);
}

int		init_texture(t_data *d)
{
	d->t->text_n = malloc(sizeof(t_img));
	d->t->text_s = malloc(sizeof(t_img));
	d->t->text_e = malloc(sizeof(t_img));
	d->t->text_w = malloc(sizeof(t_img));
	d->t->text_spr = malloc(sizeof(t_img));
	if (d->t->text_n == NULL || d->t->text_s == NULL
			|| d->t->text_w == NULL || d->t->text_e == NULL
			|| d->t->text_spr == NULL)
		return (-1);
	if (create_texture(d) == -1)
		return (-1);
	return (1);
}
