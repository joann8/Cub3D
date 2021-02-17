/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:51:10 by jacher            #+#    #+#             */
/*   Updated: 2021/02/11 16:11:01 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	f_free_mapdata(t_map *map)
{
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->ea_path)
		free(map->ea_path);
	if (map->we_path)
		free(map->we_path);
	if (map->s_path)
		free(map->s_path);
}

void	free_textures(t_data *d)
{
	if (d->t->text_n)
		if (d->t->text_n->ptr)
			mlx_destroy_image(d->mlx->ptr, d->t->text_n->ptr);
	if (d->t->text_s)
		if (d->t->text_s->ptr)
			mlx_destroy_image(d->mlx->ptr, d->t->text_s->ptr);
	if (d->t->text_e)
		if (d->t->text_e->ptr)
			mlx_destroy_image(d->mlx->ptr, d->t->text_e->ptr);
	if (d->t->text_w)
		if (d->t->text_w->ptr)
			mlx_destroy_image(d->mlx->ptr, d->t->text_w->ptr);
	if (d->t->text)
		if (d->t->text_spr->ptr)
			mlx_destroy_image(d->mlx->ptr, d->t->text_spr->ptr);
}

void	free_textures_ptr(t_data *d)
{
	if (d->t->text_n)
		free(d->t->text_n);
	if (d->t->text_s->ptr)
		free(d->t->text_s);
	if (d->t->text_e->ptr)
		free(d->t->text_e);
	if (d->t->text_w->ptr)
		free(d->t->text_w);
	if (d->t->text_spr->ptr)
		free(d->t->text_spr);
}

void	ft_free_map(char **map_tab, int j)
{
	int i;

	i = 0;
	while (i < j && map_tab[i])
	{
		free(map_tab[i]);
		i++;
	}
	free(map_tab);
}

void	free_data(t_data *d)
{
	if (d->map)
	{
		f_free_mapdata(d->map);
		free(d->map);
	}
	if (d->map_tab)
		ft_free_map(d->map_tab, 2147483647);
	if (d->sprite)
		free(d->sprite);
	if (d->player)
		free(d->player);
	if (d->ray)
		free(d->ray);
	if (d->t)
		free(d->t);
	if (d->mlx->ptr)
	{
		mlx_destroy_display(d->mlx->ptr);
		free(d->mlx->ptr);
	}
}
