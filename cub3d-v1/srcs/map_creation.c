/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:45:46 by jacher            #+#    #+#             */
/*   Updated: 2021/01/12 11:09:15 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		check_map_inputs(char *map_str, int *lines, int i, int mod)
{
	while (map_str[i])
	{
		//printf("i = %d || map_str[%d] = %c.\n", i, i, map_str[i]);
		if (map_str[i] == '\n')
		{
			i++;
			*lines += 1;
		}
		if (map_str[i] == '0' || map_str[i] == '1'
			|| map_str[i] == '2' || map_str[i] == ' ')
			i++;
		else if (map_str[i] == 'N' || map_str[i] == 'S'
					|| map_str[i] == 'E' || map_str[i] == 'W')
		{
			mod++;
			i++;
		}
		else if (map_str[i])
			break ;
	}

	if (map_str[i] == '\0' && (map_str[i - 1] == '0' || map_str[i - 1] == '1'
			|| map_str[i - 1] == '2' || map_str[i - 1] == ' '))
		*lines += 1;
	while (map_str[i] == '\n')
		i++;
	if (map_str[i] || mod != 1)
	{	
		//printf("mod = %d\n", mod);
		//printf("exit with failure at i = %d || map_str[%d] = %c.\n", i, i, map_str[i]);
		return (-1);
	}
	return (1);
}

int		count_bigger_line(char *map_str, int i)
{
	int count;
	int max;

	max = 0;
	while (map_str[i])
	{
		count = 0;
		while (map_str[i] && map_str[i] != '\n')
		{
			count++;
			i++;
		}
		if (count > max)
			max = count;
		i++;
	}
	return (max);
}

void	create_map_line(char **map_tab, char *map_str, int j, int col, int *pos)
{
	int k;
	int i;

	k = 0;
	i = *pos;
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
	*pos = i;
}

int		create_map_tab(char *map_str, char **map_tab, int i, int lines)
{
	int j;
	int col;

	col = count_bigger_line(map_str, i);
	//printf("____enter create map tab____\n");
	j = 0;
	//while (map_tab[j] != NULL)
	while (j < lines)
	{
		map_tab[j] = malloc(sizeof(char) * (col + 1));
		if (map_tab[j] == NULL)
		{
			ft_free_map(map_tab, j);
			return (-1);
		}
		else
			create_map_line(map_tab, map_str, j, col, &i);
		//printf("map_tab[%d] = ||%s||\n", j, map_tab[j]);
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
	int		col;
	char	**map_tab;

	i = pos;
	lines = 0;
	map_tab = NULL;
	//printf("map_creation_ok1\n");
	while (map_str[i] == '\n' && map_str[i])
		i++;
	//printf("map_creation_ok2\n");
	if (check_map_inputs(map_str, &lines, i, 0) == -1)
		return (NULL);
	//printf("map_creation_ok3\n");
	col = count_bigger_line(map_str, i);
	if (col < 3 || lines < 3)
		return (NULL);
	//printf("map_creation_ok4\n");
	map->map_col = col;
	map->map_lin = lines;
	map_tab = malloc(sizeof(char*) * (lines + 1));
	if (map_tab == NULL)
		return (NULL);
	//printf("map_creation_ok5\n");
	if (create_map_tab(map_str, map_tab, i, lines) == -1)
		return (NULL);
	//printf("map_creation_ok6\n");
	free(map_str);
	return (map_tab);
}
