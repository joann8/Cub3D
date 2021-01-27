/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:02:07 by jacher            #+#    #+#             */
/*   Updated: 2021/01/27 11:23:43 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		cast_all_rays(t_data *d)
{
	int		i;
	int		num_rays;
	float	dist_plan;
	t_list	*lst;
	t_list 	first;
	t_sprite s;

	f_init_sprite(&s);
	first.content = &s;
	first.next = NULL;
	lst = &first; 
	
	f_reset_ray(d->ray);
	i = 0;
	num_rays = d->map->r_x / d->ray->res;
	dist_plan = (d->map->r_x / 2) / tan(d->player->fov / 2);
	while (i < num_rays)
	{
		d->ray->angle = within_rad(d->player->angle
				+ atan(((num_rays / 2) - i) / dist_plan));
		f_reset_ray(d->ray);
		d->ray->column_id = i * d->ray->res;
		cast_a_ray(d, &lst);
		i++;
	}
	printf("*******LAST*********\n");
	print_list(&lst);
	return (1);
}
