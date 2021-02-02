/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:10:14 by jacher            #+#    #+#             */
/*   Updated: 2021/01/31 15:36:48 by jacher           ###   ########.fr       */
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
		while(d->map_tab[i][j] != '\0')
		{
			if (hit_a_wall(j * d->map->tile_col, i * d->map->tile_lin, d->map_tab, d->map) == 2)
				count++;
			j++;
		}
		i++;
	}
	d->map->sprite = count;
//	printf("count inside function = %d\n", count);
	return (count);
}

void record_sprite(t_data *d, unsigned int count)
{
	int				i;
	int				j;
	int				k;
//	t_sprite		*sprite_tab;

	k = 0;
	d->sprite = malloc(sizeof(t_sprite) * count);
	//sprite_tab = malloc(sizeof(t_sprite) * count);
	if (!d->sprite)
		return ;
	i = 0;
	while (d->map_tab[i])
	{
		j = 0;
		while(d->map_tab[i][j] != '\0')
		{
			//printf("i = %d | j = %d\n", i, j);
			if (hit_a_wall(j * d->map->tile_col, i * d->map->tile_lin, d->map_tab, d->map) == 2)
			{
				//printf("k = %d\n", k);
				printf("record sprites\n");
				d->sprite[k].x_i = j;
				printf("d->sprite[k].x_i = %d\n", d->sprite[k].x_i);
				d->sprite[k].y_i = i; 
				printf("d->sprite[k].y_i = %d\n", d->sprite[k].y_i);
				d->sprite[k].x_d = j * d->map->tile_col + d->map->tile_col / 2; 
				printf("d->sprite[k].x_d = %f\n", d->sprite[k].x_d);
				d->sprite[k].y_d = i * d->map->tile_lin + d->map->tile_lin / 2;
				printf("d->sprite[k].y_d = %f\n", d->sprite[k].y_d);
				d->sprite[k].visible = 0;
				d->sprite[k].dist = 0;
				d->sprite[k].angle = 0;
				//print_sprite(d, count);
				k++;
			}
			j++;
		}
		i++;
	}
	return ;
	//return (sprite_tab);
}
