/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_trigo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:41:30 by jacher            #+#    #+#             */
/*   Updated: 2021/01/20 13:59:47 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

float	deg_to_rad(float deg)
{
	float rad;

	rad = (deg * (M_PI / 180));
	return (rad);
}

float	rad_to_deg(float rad)
{
	float deg;

	deg = (rad * (180 / M_PI));
	return (deg);
}

float	within_rad(float rad)
{
	float 	rad2;

	rad2 = rad;
	while (rad2 > (2 * M_PI)) 
		rad2 -= 2 * M_PI;
	while (rad2 < 0)
		rad2 += 2 * M_PI;
	return (rad2);
}
