/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:23:06 by jacher            #+#    #+#             */
/*   Updated: 2021/01/26 08:50:34 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		hit_a_wall(double x, double y, char **map_tab, t_map *map)
{
	//printf("enter hit\n");
	int	i_lin;
	int j_col;
	
//	printf(" i = %d, j = %d\n", i, j);
//	printf(" map->tile_col = %d, map->tile lin = %d\n", map->tile_col, map->tile_lin);
	i_lin = y / map->tile_lin;
//	printf("ok\n");
	j_col = x / map->tile_col;
	//print_maptab(map_tab);
//	printf(" x = %f, y = %f\n",  x, y);
//	printf(" i_lin = %d, j_col = %d\n",  i_lin, j_col);
//	printf("map[%d][%d] = %c\n", i_lin, j_col, map_tab[i_lin][j_col]);
	if (i_lin < map->map_lin && j_col < map->map_col
			&& map_tab[i_lin][j_col] == '0') 
		return (0); //peut ton marcher sur un objet?
	else if (i_lin < map->map_lin && j_col < map->map_col
			&& map_tab[i_lin][j_col] == '1')
		return (1);
	else
		return (-1);
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		get_b(int trgb)
{
	return (trgb & 0xFF);
}
