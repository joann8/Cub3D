/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_col_lin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:16:55 by jacher            #+#    #+#             */
/*   Updated: 2021/01/13 12:20:46 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
//#include "../libft.h" // a enlever

//on check le 1er et le dernier caractere de chaque ligne == 1

int		check_ext_col(char **map_tab)
{
	int	i;
	int	j;
	int col;
	int lin;

//	printf("___enter check ext col___\n");
	j = 0;
	col = ft_strlen(map_tab[0]);
	printf("col = %d\n", col);
	while (j < col)
	{
		i = 0;
		//printf("enter while with i = %d et j = %d\n", i, j);
		//printf("map_tab[%d][%d] = %c\n", i, j, map_tab[i][j]);
		while (map_tab[i] && (map_tab[i][j] == ' ' || map_tab[i][j] == 'x'))
		{
			//printf("enter while\n");
			map_tab[i][j] = 'x'; //les espaces checkes deviennent des x
			i++;
		}
		if (map_tab[i] != NULL && map_tab[i][j] != '1')
		{
//			printf(">>>exit with failure at j = %d\n", j);
			return (-1);
		}
		else
			j++;
	}
	//printf("ok\n");
	j = 0;
	lin = 0;
	while (map_tab[lin])
		lin++;
	while (j < col)
	{
		i = lin - 1;
	//	printf("enter while with i = %d et j = %d\n", i, j);
	//	printf("map_tab[%d][%d] = %c\n", i, j, map_tab[i][j]);
		while (i >= 0 && (map_tab[i][j] == ' ' || map_tab[i][j] == 'x'))
		{
	//		printf("enter while tour %i\n", i);
			map_tab[i][j] = 'x'; //les espaces checkes deviennent des x
			i--;
		}
		if (i != -1 && map_tab[i][j] != '1')
			return (-1);
		else
			j++;
	}
//	printf(">>>>exit with success\n");
	return (1);
}

int		check_ext_lin(char **map_tab)
{
	int	i;
	int	j;

//	printf("___enter check ext lin___\n");
	i = 0;
	while (map_tab[i] != NULL)
	{
		j = 0;
		while (map_tab[i][j] == ' ')
		{
			map_tab[i][j] = 'x'; //les espaces checkes deviennent des x
			j++;
		}
		if (map_tab[i][j] != '\0' && map_tab[i][j] != '1')
		{
//			printf("fail at i = %d\n", i); //a enlever
			return (-1);
		}
		i++;
	}
	i = 0;
	while (map_tab[i] != NULL)
	{
		j = ft_strlen(map_tab[0]) - 1;
		while (j >= 0 && map_tab[i][j] == ' ')
		{
			map_tab[i][j] = 'x'; //les espaces checkes deviennent des x
			j--;
		}
		if (j != -1 && map_tab[i][j] != '1')
			return (-1);
		i++;
	}
//	printf(">>>>exit with success\n");
	return (1);
}

int		check_lin(char **map_tab, int lin, int col)
{
	int i;
	int max;

//	printf("___enter check lin___\n");
	max = ft_strlen(map_tab[0]);
	i = col - 1;
	//printf("enter while with col = %d et max = %d pour lin = %d\n", i, max, lin);
	while (i >= 0 && map_tab[lin][i] != '1' && map_tab[lin][i] != ' ')
	{
		//printf("map_tab[%d][%d] = %c\n", lin, i, map_tab[lin][i]);
		i--;
	}
	if (i == -1 || map_tab[lin][i] == ' ')
	{
		//printf("exit with failre 1\n");
		return (-1);
	}
	i = col + 1;
	while (i < max && map_tab[lin][i] != '1' && map_tab[lin][i] != ' ')
		i++;
	if (i == max || map_tab[lin][i] == ' ')
	{	
		//printf("exit with failre 2\n");
		return (-1);
	}
//	printf(">>>>exit with success\n");
	return (1);
}

int		check_col(char **map_tab, int lin, int col)
{
	int i;
	int max;

//	printf("___enter check col___\n");
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
//	printf(">>>>exit with success\n");
	return (1);
}
