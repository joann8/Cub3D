/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_trigo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:41:30 by jacher            #+#    #+#             */
/*   Updated: 2021/01/21 11:10:24 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

double	deg_to_rad(double deg)
{
	double rad;

	rad = (deg * (M_PI / 180));
	return (rad);
}

double	rad_to_deg(double rad)
{
	double deg;

	deg = (rad * (180 / M_PI));
	return (deg);
}

double	within_rad(double rad)
{
	double 	rad2;

	rad2 = rad;
	while (rad2 > (2 * M_PI)) 
		rad2 -= 2 * M_PI;
	while (rad2 < 0)
		rad2 += 2 * M_PI;
	return (rad2);
}
