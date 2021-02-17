/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:00:49 by jacher            #+#    #+#             */
/*   Updated: 2021/02/10 13:06:13 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		check_others(t_map *map, char *map_str, int mod)
{
	if (map->r == 1 && map->c == 1 && map->f == 1 && map->s == 1
			&& map->no == 1 && map->so == 1 && map->ea == 1 && map->we == 1)
		return (1);
	if (mod == 1)
	{
		free(map_str);
		print_error_parsing(4);
	}
	return (-1);
}

void	map_data_textures(char *map_str, t_map *map, int *pos, int *res)
{
	int i;

	i = *pos;
	if (map_str[i] == 'N' && map_str[i + 1] == 'O'
				&& map_str[i + 2] == ' ' && map->no == -1)
		*res = data_no(map_str, map, &i);
	else if (map_str[i] == 'S' && map_str[i + 1] == 'O'
				&& map_str[i + 2] == ' ' && map->so == -1)
		*res = data_so(map_str, map, &i);
	else if (map_str[i] == 'E' && map_str[i + 1] == 'A'
				&& map_str[i + 2] == ' ' && map->ea == -1)
		*res = data_ea(map_str, map, &i);
	else if (map_str[i] == 'W' && map_str[i + 1] == 'E'
				&& map_str[i + 2] == ' ' && map->we == -1)
		*res = data_we(map_str, map, &i);
	else if (map_str[i] == 'S' && map_str[i + 1] == ' ' && map->s == -1)
		*res = data_s(map_str, map, &i);
	else
		*res = print_error_parsing(4);
	*pos = i;
}

int		map_data_others_bis(char *map_str, t_map *map, int *pos)
{
	int	i;
	int res;

	i = *pos;
	res = 1;
	if (map_str[i] == 'R' && map_str[i + 1] == ' ' && map->r == -1)
		res = data_r(map_str, map, &i);
	else if (map_str[i] == 'F' && map_str[i + 1] == ' ' && map->f == -1)
		res = data_f(map_str, map, &i);
	else if (map_str[i] == 'C' && map_str[i + 1] == ' ' && map->c == -1)
		res = data_c(map_str, map, &i);
	else
		map_data_textures(map_str, map, &i, &res);
	*pos = i;
	return (res);
}

int		map_data_others(char *map_str, t_map *map, int *pos)
{
	int i;

	i = 0;
	while (map_str[i])
	{
		if (map_str[i] == ' ' || map_str[i] == '\n')
			i++;
		else
		{
			if (map_data_others_bis(map_str, map, &i) == -1)
			{
				free(map_str);
				return (-1);
			}
		}
		if (check_others(map, map_str, 0) == 1)
			break ;
	}
	*pos += i;
	return (1);
}

char	**map_parsing(char *av, t_map *map)
{
	char	*map_str;
	int		i;
	char	**map_tab;

	map_str = map_create_str(av);
	if (map_str == NULL)
		return (NULL);
	i = 0;
	if (map_data_others(map_str, map, &i) == -1)
		return (NULL);
	if (check_others(map, map_str, 1) == -1
			|| check_walls_texture(map, map_str) == -1)
		return (NULL);
	map_tab = map_creation(map_str, i, map);
	if (map_tab == NULL)
		return (NULL);
	if (record_player_pos(map, map_tab) == -1 ||
			map_check_walls(map_tab) == -1)
	{
		ft_free_map(map_tab, 2147483647);
		return (NULL);
	}
	return (map_tab);
}
