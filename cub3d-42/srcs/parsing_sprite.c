/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:10:14 by jacher            #+#    #+#             */
/*   Updated: 2021/02/11 14:47:58 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

unsigned int	count_sprite(t_data *d)
{
	int				i;
	int				j;
	unsigned int	count;

	count = 0;
	i = 0;
	while (d->map_tab[i])
	{
		j = 0;
		while (d->map_tab[i][j] != '\0')
		{
			if (hit_a_wall(j * BLOCK, i * BLOCK, d->map_tab, d->map) == 2)
				count++;
			j++;
		}
		i++;
	}
	d->map->sprite = count;
	return (count);
}

void			assign_sprite_table(t_data *d, int i, int j, int k)
{
	k = 0;
	i = 0;
	while (d->map_tab[i])
	{
		j = 0;
		while (d->map_tab[i][j] != '\0')
		{
			if (hit_a_wall(j * BLOCK, i * BLOCK,
				d->map_tab, d->map) == 2)
			{
				d->sprite[k].x_i = j;
				d->sprite[k].y_i = i;
				d->sprite[k].x_d = j * BLOCK + BLOCK / 2;
				d->sprite[k].y_d = i * BLOCK + BLOCK / 2;
				d->sprite[k].visible = 0;
				d->sprite[k].dist = 0;
				d->sprite[k].angle = 0;
				k++;
			}
			j++;
		}
		i++;
	}
}

void			record_sprite(t_data *d, unsigned int count)
{
	int				i;
	int				j;
	int				k;

	i = 0;
	j = 0;
	k = 0;
	d->sprite = malloc(sizeof(t_sprite) * count);
	if (!d->sprite)
	{
		print_error_parsing(10);
		return ;
	}
	assign_sprite_table(d, i, j, k);
	return ;
}
