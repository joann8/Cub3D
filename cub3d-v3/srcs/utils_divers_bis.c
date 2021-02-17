/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_divers_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:09:53 by jacher            #+#    #+#             */
/*   Updated: 2021/01/21 18:54:07 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static	void	man_neg(int n, unsigned int *nbr, unsigned int *size, int mod)
{
	if (n <= 0)
	{
		if (mod == 0)
			*size = *size + 1;
		*nbr = -n;
	}
	else
		*nbr = n;
	if (mod == 0)
	{
		while (*nbr > 0)
		{
			*size = *size + 1;
			*nbr = *nbr / 10;
		}
	}
}

char			*ft_define_color(char tab[10])
{
	unsigned int	nbr;
	unsigned int	size;
	char			tab[2][10];
	char			*base;

	size = 0;
	base = "0123456789abcdef";
	tab[0] = '0';
	tab[1] = '0';
	tab[0] = '0';
	if (nbr == 0)
		tab[0] = '0';
	else
	{
		while (nbr > 0)
		{
			tab[size - 1] = nbr % 10 + '0';
			nbr = nbr / 10;
			size--;
		}
		if (size > 0)
			tab[0] = '-';
	}
	return (tab);
}
