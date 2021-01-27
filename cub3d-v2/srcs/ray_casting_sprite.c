/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:10:14 by jacher            #+#    #+#             */
/*   Updated: 2021/01/27 11:51:41 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int check_sprite(t_list **lst, int x, int y)
{
	t_list		*tmp_l;
	t_sprite	*tmp_s;

	tmp_l = *lst;
	while (tmp_l)
	{
		tmp_s = tmp_l->content;
		if(tmp_s->x_i == x && tmp_s->y_i == y)
			return (1);
		tmp_l = tmp_l->next;
	}
	printf("nouvel objet!\n");
	return (0);
}

		
		

void ray_cast_sprite(t_data *d, t_list **lst,  double h_x, double h_y)
{
	t_sprite	s;
	t_list		*new;
	t_list		*tmp_l;
	t_sprite	*tmp_s;


	s.bol = 1;
	s.x_d = h_x;
	s.y_d = h_y;
	s.x_i = h_x / d->map->tile_col;
	s.y_i = h_y / d->map->tile_lin;
  	s.dist = calculate_distance(h_x, d->player->x, h_y, d->player->y);
	
	new = ft_lstnew(&s);
	tmp_s = (*lst)->content;
	if(tmp_s->bol == 0)
		(*lst) = new;
	else if (check_sprite(lst, s.x_i, s.y_i) == 1)
		return ;
	else
	{
		tmp_l = *lst;
		print_elem_list(tmp_l);
		while (tmp_l->next)
			tmp_l = tmp_l->next;
		tmp_l->next = new;
	}
}
