/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:57:08 by jacher            #+#    #+#             */
/*   Updated: 2021/02/09 18:23:58 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		convert_trgb_bmp(t_bmp_color *pixel, t_img *img, int x, int y)
{
	int			color;
	char		*dst;

	dst = img->addr + (y * img->length + x * (img->bits / 8));
	color = *(unsigned int*)dst;
	pixel->r = (color & 0xFFFF00) >> 16;
	pixel->g = (color & 0xFF00) >> 8;
	pixel->b = (color & 0xFF);
}

int		get_byte_correction(int r_x)
{
	char	byte_correction[4];
	int		i;
	int		correction_byte;

	byte_correction[0] = 0;
	byte_correction[1] = 3;
	byte_correction[2] = 2;
	byte_correction[3] = 1;
	i = (int)(3 * r_x) % 4;
	correction_byte = byte_correction[i];
	return(i);
}
	
