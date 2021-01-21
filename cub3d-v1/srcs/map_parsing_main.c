/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:00:49 by jacher            #+#    #+#             */
/*   Updated: 2021/01/13 12:21:22 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
//#include "../libft.h"

int		check_others(t_map *map)
{
	//if (map->f_r == map->c_r && map->f_g == map->c_g && map->f_b == map->c_b)
	//	return (-1); couleur sol plafond peuvent etre = finalement
	if (map->r == 1 && map->c == 1 && map->f == 1 && map->s == 1
			&& map->no == 1 && map->so == 1 && map->ea == 1 && map->we == 1)
		return (1);
	return (0);
}

int		map_data_others_bis(char *map_str, t_map *map, int *pos)
{
	int	i;
	int res;

	i = *pos;
	//printf("map_data_others : map_str[%d] = %c\n", i, map_str[i]);
	//printf("map_data_others : pos before data_function: i = %d\n", *pos);
	res = 1;
	if (map_str[i] == 'R' && map_str[i + 1] == ' ' && map->r == -1)
		 res = data_r(map_str, map, &i);
	else if (map_str[i] == 'F'  && map_str[i + 1] == ' ' && map->f == -1)
		res = data_f(map_str, map, &i);
	else if (map_str[i] == 'C'  && map_str[i + 1] == ' ' && map->c == -1)
		res = data_c(map_str, map, &i);
	else if (map_str[i] == 'N' && map_str[i + 1] == 'O'  && map_str[i + 2] == ' ' && map->no == -1)
		res = data_no(map_str, map, &i);
	else if (map_str[i] == 'S' && map_str[i + 1] == 'O'  && map_str[i + 2] == ' ' && map->so == -1)
		res = data_so(map_str, map, &i);
	else if (map_str[i] == 'E' && map_str[i + 1] == 'A'  && map_str[i + 2] == ' ' && map->ea == -1)
		res = data_ea(map_str, map, &i);
	else if (map_str[i] == 'W' && map_str[i + 1] == 'E'  && map_str[i + 2] == ' ' && map->we == -1)
		res = data_we(map_str, map, &i);
	else if (map_str[i] == 'S' && map_str[i + 1] == ' ' && map->s == -1)
		res = data_s(map_str, map, &i);
	else
		res = -1;
	*pos = i;
	//printf("map_data_others : pos before data_function: i = %d\n", *pos);
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
				return (-1);
		}
		if (check_others(map) == 1)
			break ;
	}
	*pos += i;
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
	return (-1);
}

char	**map_parsing(char *av, t_map *map)
{
	char	*map_str;
	int		i;
	char	**map_tab;

//	printf("ok1\n");
	map_str = map_create_str(av);
//	printf("ok2\n");
	if (map_str == NULL)
		return (NULL);
	i = 0;
	if (map_data_others(map_str, map, &i) == -1)
	{
		free(map_str);
		return (NULL);
	}
//	printf("ok3\n");
	if (map_str[i] == '\0' || check_others(map) == 0)
	{
		free(map_str);
		return (NULL);
	}
//	printf("ok4\n");
	//a enlever
//	print_mapdata(map);
	//
	map_tab = map_creation(map_str, i, map);
	if (map_tab == NULL)
	{
		free(map_str);
		return (NULL);
	}
	//a enlever
//	print_maptab(map_tab);
	//
//	printf("ok5\n");
	if (record_player_pos(map, map_tab) == -1 || map_check_walls(map_tab) == -1)
	{
		ft_free_map(map_tab, 2147483647); //pas sure d'avoir le droit
		return (NULL);
	}
//	printf("ok6\n");
	return (map_tab);
}
