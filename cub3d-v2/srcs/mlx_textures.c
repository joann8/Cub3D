/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_walls_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:11:03 by jacher            #+#    #+#             */
/*   Updated: 2021/01/25 16:50:28 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		init_texture(t_data *d)
{
	d->t->text_n->ptr = mlx_xpm_file_to_image(d->mlx->ptr, d->map->no_path, &(d->t->length_n), &(d->t->height_n));
	if (d->t->text_n->ptr == NULL)
		return (-1);
	d->t->text_n->addr = mlx_get_data_addr(d->t->text_n->ptr, &(d->t->text_n->bits), &(d->t->text_n->length), &(d->t->text_n->endian));

	d->t->text_s->ptr = mlx_xpm_file_to_image(d->mlx->ptr, d->map->so_path, &(d->t->length_s), &(d->t->height_s));
	if (d->t->text_s->ptr == NULL)
		return (-1);
	d->t->text_s->addr = mlx_get_data_addr(d->t->text_s->ptr, &(d->t->text_s->bits), &(d->t->text_s->length), &(d->t->text_s->endian));

	d->t->text_w->ptr = mlx_xpm_file_to_image(d->mlx->ptr, d->map->we_path,  &(d->t->length_w), &(d->t->height_w));
	if (d->t->text_w->ptr == NULL)
		return (-1);
	d->t->text_w->addr = mlx_get_data_addr(d->t->text_w->ptr, &(d->t->text_w->bits), &(d->t->text_w->length), &(d->t->text_w->endian));

	d->t->text_e->ptr = mlx_xpm_file_to_image(d->mlx->ptr, d->map->ea_path, &(d->t->length_e), &(d->t->height_e));
	if (d->t->text_e->ptr == NULL)
		return (-1);
	d->t->text_e->addr = mlx_get_data_addr(d->t->text_e->ptr, &(d->t->text_e->bits), &(d->t->text_e->length), &(d->t->text_e->endian));
	return (1);
}
