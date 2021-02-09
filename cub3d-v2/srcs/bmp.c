/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:25:14 by jacher            #+#    #+#             */
/*   Updated: 2021/02/09 18:22:29 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		fill_file_header(t_data *d, t_file_header *fh)
{
	int		img_calcul;

	//fh->img = malloc(sizeof(t_img_header));
	//if (fh->img == NULL)
	//	return (print_error_else(2));
	
	img_calcul = (3 * d->map->r_y * d->map->r_x) + d->map->r_y * get_byte_correction(d->map->r_x);

	ft_bzero(fh, sizeof(t_file_header));
	fh->signature[0] = 'B';
	fh->signature[1] = 'M';
	fh->size = sizeof(t_file_header) - 2 + img_calcul;
	fh->reserved = 0;
	fh->offset_img = sizeof(t_file_header) - 2;
	
	fh->img.size_img_header = sizeof(t_img_header);
	fh->img.width = d->map->r_x;
	fh->img.length = d->map->r_y;
	fh->img.nb_planes = 1;
	fh->img.bpp = 24;
	fh->img.size_img_total = img_calcul;
	return(1);
}

void 	fill_img_header(t_img *img, t_file_header *fh, int fd)
{
	t_bmp_color 	pixel;
	unsigned char	pixel_color[3];
	int				x;
	int				y;
	int				offset;

	offset = get_byte_correction(fh->img.width);
	write(fd, fh, 2);
	write(fd, (char *)(fh) + 4, sizeof(t_file_header) - 4);
	y = fh->img.length - 1;
	while (y > -1)
	{
		x = 0;
		while (x < fh->img.width)
		{
			convert_trgb_bmp(&pixel, img, x, y);
			pixel_color[0] = pixel.b;
			pixel_color[1] = pixel.g;
			pixel_color[2] = pixel.r;
			write(fd, pixel_color, 3);
			x++;
		}
		ft_bzero(pixel_color, 3);
		write(fd, pixel_color, offset);
		y--;
	}
}


int save_bmp(t_data *d)
{
	int				fd;
	t_file_header	fh;

	f_update_player(d);
	cast_all_rays(d);
	
	fd = open("save.bmp", O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd == -1)
		return(print_error_else(1));
	if (fill_file_header(d, &fh) == 1)
	{
		fill_img_header(d->mlx->img, &fh, fd);
		//free(fh->img);
	}
	close(fd);
	if (fd == -1)
		return(print_error_else(1));
	return(1);
}
