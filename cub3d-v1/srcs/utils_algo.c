/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:23:06 by jacher            #+#    #+#             */
/*   Updated: 2021/01/20 19:37:27 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		hit_a_wall(int i, int j, char **map_tab, t_map *map)
{
	//printf("enter hit\n");
	int	i_lin;
	int j_col;
	
//	printf(" i = %d, j = %d\n", i, j);
//	printf(" map->tile_col = %d, map->tile lin = %d\n", map->tile_col, map->tile_lin);
	i_lin = i / map->tile_lin;
//	printf("ok\n");
	j_col = j / map->tile_col;
	//print_maptab(map_tab);
	printf(" i = %d, j = %d\n",  i, j);
	printf(" i_lin = %d, j_col = %d\n",  i_lin, j_col);
//	printf("map[%d][%d] = %c\n", i_lin, j_col, map_tab[i_lin][j_col]);
	if (i_lin < map->map_lin && j_col < map->map_col
			&& map_tab[i_lin][j_col] == '0') 
		return (0); //peut ton marcher sur un objet?
	else
		return (1);
}
