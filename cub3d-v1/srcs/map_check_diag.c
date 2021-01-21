/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_diag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:16:55 by jacher            #+#    #+#             */
/*   Updated: 2021/01/13 12:21:02 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
//#include "../libft.h"

int		check_diag1(char **map_tab, int lin, int col)
{
	int i;
	int j;

//	printf("___enter diag1___\n");
//	printf("check pour map_tab[%d][%d] = %c\n", lin, col, map_tab[lin][col]);
	i = lin - 1;
	j = col - 1;
//	print_maptab(map_tab);
	while (i >= 0 && j >= 0 && map_tab[i][j] != '1' && map_tab[i][j] != ' ')
	{
//		printf("i = %d et j = %d || map_tab[%d][%d] = %c\n", i,j, i, j, map_tab[i][j]);
		i--;
		j--;
	}
	if (i == -1 || j == -1 || map_tab[i][j] == ' ')
		return (-1);
//	printf(">>>exit with success\n");
	return (1);
}

int		check_diag2(char **map_tab, int lin, int col)
{
	int i;
	int j;
	int max_col;

//	printf("___enter diag2___\n");
	max_col = ft_strlen(map_tab[0]);
	i = lin - 1;
	j = col + 1;
	while (i >= 0 && j < max_col && map_tab[i][j] != '1' && map_tab[i][j] != ' ')
	{
		i--;
		j++;
	}
	if (i == -1 || j == max_col || map_tab[i][j] == ' ')
		return (-1);
//	printf(">>>exit with success\n");
	return (1);
}

int		check_diag3(char **map_tab, int lin, int col)
{
	int i;
	int j;
	int max_lin;

//	printf("___enter diag3__\n");
	max_lin = 0;
	while (map_tab[max_lin] != NULL)
		max_lin++;
	i = lin + 1;
	j = col - 1;
	while (i < max_lin && j >= 0 && map_tab[i][j] != '1' && map_tab[i][j] != ' ')
	{
		i++;
		j--;
	}
	if (i == max_lin || j == -1 || map_tab[i][j] == ' ')
		return (-1);
//	printf(">>>exit with success\n");
	return (1);
}

int		check_diag4(char **map_tab, int lin, int col)
{
	int i;
	int j;
	int max_lin;
	int max_col;

//	printf("___enter diag4___\n");
	max_col = ft_strlen(map_tab[0]);
	max_lin = 0;
	while (map_tab[max_lin] != NULL)
		max_lin++;
	i = lin + 1;
	j = col + 1;
	while (i < max_lin && j < max_col && map_tab[i][j] != '1' && map_tab[i][j] != ' ')
	{
		i++;
		j++;
	}
	if (i == max_lin || j == max_col || map_tab[i][j] == ' ')
		return (-1);
//	printf(">>>exit with success\n");
	return (1);
}
