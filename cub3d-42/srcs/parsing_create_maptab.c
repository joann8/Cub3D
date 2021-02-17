/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_create_tab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:45:46 by jacher            #+#    #+#             */
/*   Updated: 2021/02/10 12:52:11 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		create_map_line(char **map_tab, char *map_str, int j, int col)
{
	int k;
	int i;

	k = 0;
	i = 0;
	while ((map_str[i] != '\n' && map_str[i]))
	{
		map_tab[j][k] = map_str[i];
		i++;
		k++;
	}
	while (k < col)
	{
		map_tab[j][k] = ' ';
		k++;
	}
	map_tab[j][k] = '\0';
	return (i);
}

int		create_map_tab(char *map_str, char **map_tab, int i, t_map *map)
{
	int j;

	j = 0;
	while (j < map->map_lin)
	{
		map_tab[j] = malloc(sizeof(char) * (map->map_col + 1));
		if (map_tab[j] == NULL)
		{
			ft_free_map(map_tab, j);
			return (print_error_parsing(10));
		}
		else
			i += create_map_line(map_tab, map_str + i, j, map->map_col);
		j++;
		i++;
	}
	map_tab[j] = NULL;
	return (1);
}

char	**map_creation(char *map_str, int pos, t_map *map)
{
	int		i;
	int		lines;
	char	**map_tab;

	i = pos;
	lines = 0;
	if (check_str(map_str, &i, map) == -1)
	{
		free(map_str);
		return (NULL);
	}
	map_tab = malloc(sizeof(char*) * (map->map_lin + 1));
	if (map_tab == NULL)
	{
		free(map_str);
		print_error_parsing(10);
		return (NULL);
	}
	if (create_map_tab(map_str, map_tab, i, map) == -1)
	{
		free(map_str);
		return (NULL);
	}
	free(map_str);
	return (map_tab);
}
