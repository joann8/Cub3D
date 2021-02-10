/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:08:47 by jacher            #+#    #+#             */
/*   Updated: 2021/02/10 13:02:00 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		skip_space_folder(char *map_str, int *pos)
{
	int	i;
	int count;
	int dot;

	i = *pos;
	dot = 0;
	while (map_str[i] == ' ')
		i++;
	if (i == *pos)
		return (-1);
	*pos = i;
	count = 0;
	while (ft_isprint(map_str[i]) == 1 && map_str[i] != ' '
			&& map_str[i] != '\n' && map_str[i])
	{
		if (map_str[i] == '.' && i != *pos)
			dot++;
		count++;
		i++;
	}
	if (count == 0 || dot > 1)
		return (print_error_parsing(11));
	return (count);
}

int		check_lin(char **map_tab, int lin, int col)
{
	int i;
	int max;

	max = ft_strlen(map_tab[0]);
	i = col - 1;
	while (i >= 0 && map_tab[lin][i] != '1' && map_tab[lin][i] != ' ')
		i--;
	if (i == -1 || map_tab[lin][i] == ' ')
		return (-1);
	i = col + 1;
	while (i < max && map_tab[lin][i] != '1' && map_tab[lin][i] != ' ')
		i++;
	if (i == max || map_tab[lin][i] == ' ')
		return (-1);
	return (1);
}

int		check_col(char **map_tab, int lin, int col)
{
	int i;
	int max;

	max = 0;
	while (map_tab[max] != NULL)
		max++;
	i = lin - 1;
	while (i >= 0 && map_tab[i][col] != '1' && map_tab[i][col] != ' ')
		i--;
	if (i == -1 || map_tab[i][col] == ' ')
		return (-1);
	i = lin + 1;
	while (i < max && map_tab[i][col] != '1' && map_tab[i][col] != ' ')
		i++;
	if (i == max || map_tab[i][col] == ' ')
		return (-1);
	return (1);
}

int		record_player_pos(t_map *map, char **map_tab)
{
	int i;
	int j;

	i = 0;
	while (map_tab[i] != NULL)
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (map_tab[i][j] == 'N' || map_tab[i][j] == 'S'
					|| map_tab[i][j] == 'E' || map_tab[i][j] == 'W')
			{
				map->player = 1;
				map->player_pos = map_tab[i][j];
				map->player_lin = i;
				map->player_col = j;
				map_tab[i][j] = '0';
				return (1);
			}
			j++;
		}
		i++;
	}
	print_error_parsing(8);
	return (-1);
}

int		check_walls_texture(t_map *map, char *map_str)
{
	if (ft_strncmp(map->no_path, map->so_path, ft_strlen(map->no_path)) != 0
		&& ft_strncmp(map->no_path, map->ea_path, ft_strlen(map->no_path)) != 0
		&& ft_strncmp(map->no_path, map->we_path, ft_strlen(map->no_path)) != 0
		&& ft_strncmp(map->so_path, map->ea_path, ft_strlen(map->so_path)) != 0
		&& ft_strncmp(map->so_path, map->we_path, ft_strlen(map->so_path)) != 0
		&& ft_strncmp(map->we_path, map->ea_path, ft_strlen(map->ea_path)) != 0)
		return (1);
	free(map_str);
	return (print_error_parsing(17));
}
