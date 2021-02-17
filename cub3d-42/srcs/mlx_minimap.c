/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:44:15 by jacher            #+#    #+#             */
/*   Updated: 2021/02/12 15:10:50 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	mlx_draw_player_bis(t_data *d, double ratio, int x, int y)
{
	int		i;
	int		j;

	i = y * ratio;
	while (i <= (y + 1) * ratio)
	{
		j = x * ratio;
		while (j <= (x + 1) * ratio)
		{
			my_mlx_pixel_put(d, j, i, 0x00FF0000);
			j++;
		}
		i++;
	}
}

void	mlx_draw_player(t_data *d, unsigned int tile, double ratio)
{
	int		x;
	int		y;

	x = 0;
	while (x < BLOCK * d->map->map_col)
	{
		y = 0;
		while (y < BLOCK * d->map->map_lin)
		{
			if (((d->player->x - x) * (d->player->x - x)) < tile
				&& ((d->player->y - y) * (d->player->y - y)) < tile)
				mlx_draw_player_bis(d, ratio, x, y);
			y++;
		}
		x++;
	}
}

void	mlx_create_map(t_data *d, unsigned int tile)
{
	unsigned int	i;
	unsigned int	j;
	int				x;
	int				y;

	i = 0;
	y = 0;
	while (y < d->map->map_lin && i < tile * d->map->map_lin)
	{
		j = 0;
		x = 0;
		while (x < d->map->map_col && j < d->map->map_col * tile)
		{
			if (d->map_tab[y][x] == '1' || d->map_tab[y][x] == 'x')
				my_mlx_pixel_put(d, j, i, 0x00999999);
			else if (d->map_tab[y][x] == '0')
				my_mlx_pixel_put(d, j, i, 0x00FFFFFF);
			else if (d->map_tab[y][x] == '2')
				my_mlx_pixel_put(d, j, i, 0x000000FF);
			j++;
			x = j / tile;
		}
		i++;
		y = i / tile;
	}
}

int		mini_map_update(t_data *d)
{
	unsigned int	tile;
	unsigned int	tile_x;
	unsigned int	tile_y;
	double			ratio;

	tile_x = (d->map->r_x / 5) / d->map->map_col;
	tile_y = (d->map->r_y / 5) / d->map->map_lin;
	if (tile_x > tile_y)
		tile = tile_x;
	else
		tile = tile_y;
	mlx_create_map(d, tile);
	ratio = (double)tile / (double)BLOCK;
	mlx_draw_player(d, tile, ratio);
	return (0);
}
