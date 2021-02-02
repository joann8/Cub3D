/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:11:03 by jacher            #+#    #+#             */
/*   Updated: 2021/02/02 22:14:53 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		init_texture(t_data *d)
{
//	printf("enter textures\n");
	d->t->text_n->ptr = mlx_xpm_file_to_image(d->mlx->ptr, d->map->no_path, &(d->t->length_n), &(d->t->height_n));
//	printf("north path = %s\n", d->map->no_path);
	if (d->t->text_n->ptr == NULL)
		return (-1);
	d->t->text_n->addr = mlx_get_data_addr(d->t->text_n->ptr, &(d->t->text_n->bits), &(d->t->text_n->length), &(d->t->text_n->endian));

//	printf("texture north : length = %i | height = %i\n", d->t->length_n, d->t->height_n);

	d->t->text_s->ptr = mlx_xpm_file_to_image(d->mlx->ptr, d->map->so_path, &(d->t->length_s), &(d->t->height_s));
	if (d->t->text_s->ptr == NULL)
		return (-1);
	d->t->text_s->addr = mlx_get_data_addr(d->t->text_s->ptr, &(d->t->text_s->bits), &(d->t->text_s->length), &(d->t->text_s->endian));

//	printf("texture south : length = %i | height = %i\n", d->t->length_s, d->t->height_s);
	d->t->text_w->ptr = mlx_xpm_file_to_image(d->mlx->ptr, d->map->we_path,  &(d->t->length_w), &(d->t->height_w));
	if (d->t->text_w->ptr == NULL)
		return (-1);
	d->t->text_w->addr = mlx_get_data_addr(d->t->text_w->ptr, &(d->t->text_w->bits), &(d->t->text_w->length), &(d->t->text_w->endian));

//	printf("texture west : length = %i | height = %i\n", d->t->length_w, d->t->height_w);
	d->t->text_e->ptr = mlx_xpm_file_to_image(d->mlx->ptr, d->map->ea_path, &(d->t->length_e), &(d->t->height_e));
	if (d->t->text_e->ptr == NULL)
		return (-1);
	d->t->text_e->addr = mlx_get_data_addr(d->t->text_e->ptr, &(d->t->text_e->bits), &(d->t->text_e->length), &(d->t->text_e->endian));
//	printf("texture east : length = %i | height = %i\n", d->t->length_e, d->t->height_e);	

	d->t->text_spr->ptr = mlx_xpm_file_to_image(d->mlx->ptr, d->map->s_path, &(d->t->length_spr), &(d->t->height_spr));
	if (d->t->text_spr->ptr == NULL)
		return (-1);
	d->t->text_spr->addr = mlx_get_data_addr(d->t->text_spr->ptr, &(d->t->text_spr->bits), &(d->t->text_spr->length), &(d->t->text_spr->endian));
//	printf("texture sprite : length = %i | height = %i\n", d->t->length_spr, d->t->height_spr);
	d->map->spr_col_no = mlx_img_get_pixel_value(d->t->text_spr, 0, 0);
//	printf("color no = %d\n", d->map->spr_col_no);
	return (1);
}
