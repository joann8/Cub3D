/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:51:10 by jacher            #+#    #+#             */
/*   Updated: 2021/02/02 10:19:37 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include<stdio.h>

void	print_player(t_player *player)
{
	printf("\n****** PLAYER STRUCT *****\n");
	printf("player->x_max = %d\n", player->x_max);
	printf("player->y_max = %d\n", player->y_max);
	printf("player->x = %f\n", player->x);
	printf("player->y = %f\n", player->y);
	printf("player->dir_turn = %d\n", player->dir_turn);
	printf("player->dir_walk_lr = %d\n", player->dir_walk_lr);
	printf("player->dir_walk_bf = %d\n", player->dir_walk_bf);
	printf("player->dir_ang = %f\n", player->angle);
	printf("player->speed_ang = %f\n", player->speed_ang);
	printf("player->speed_walk = %f\n", player->speed_walk);
}

void	print_mapdata(t_map *map)
{
	printf("\n****** MAP DATA STRUCT *****\n");
	printf("map->r = %d\n", map->r);
	printf("map->r_x = %d\n", map->r_x);
	printf("map->r_y = %d\n", map->r_y);	
	printf("map->r_x_i = %d\n", map->r_x_i);
	printf("map->r_y_i = %d\n", map->r_y_i);
	printf("map->no = %d\n", map->no);
	printf("map->no_path = %s\n", map->no_path);
	printf("map->so = %d\n", map->so);
	printf("map->so_path = %s\n", map->so_path);
	printf("map->ea = %d\n", map->ea);
	printf("map->ea_path = %s\n", map->ea_path);
	printf("map->we = %d\n", map->we);
	printf("map->we_path = %s\n", map->we_path);
	printf("map->s = %d\n", map->s);
	printf("map->s_path = %s\n", map->s_path);
	printf("map->f = %d\n", map->f);
	printf("map->f_r = %d\n", map->f_r);
	printf("map->f_g = %d\n", map->f_g);
	printf("map->f_b = %d\n", map->f_b);
	printf("map->c = %d\n", map->c);
	printf("map->c_r = %d\n", map->c_r);
	printf("map->c_g = %d\n", map->c_g);
	printf("map->c_b = %d\n", map->c_b);
	printf("map->player = %d\n", map->player);
	printf("map->player_pos = %c\n", map->player_pos);
	printf("map->player_col = %d\n", map->player_col);
	printf("map->player_lin = %d\n", map->player_lin);
	printf("****** END *****\n");
}

void	print_maptab(char **map_tab)
{
	int i;

	printf("\n****** MAP TAB *****\n");
	i = 0;
	while (map_tab[i] != NULL)
	{
		printf("||%s||\n", map_tab[i]);
		i++;
	}
	printf("****** END *****\n");
}

void	print_ray(t_ray *r)
{
	printf("****print ray*****\n");
	printf("resolution  = %d\n", r->res);
	printf("x_hit = %f\n", r->x_hit);
	printf("y_hit = %f\n", r->y_hit);	
	printf("dist = %f\n", r->dist);
	printf("******************\n");
}

void	print_ray_orientation(t_ray *r)
{
	printf("****print ray orientation*****\n");
	printf("facing up    = %d\n", r->fac_up);
	printf("facing down  = %d\n", r->fac_down);
	printf("facing left  = %d\n", r->fac_left);
	printf("facing right = %d\n", r->fac_right);	
	printf("dist = %f\n", r->dist);
	printf("******************************\n");
}
	
	
void	print_coord(t_coord *c)
{
	printf("****print coord*****\n");
	printf("x_step = %f\n", c->x_step);
	printf("y_step = %f\n", c->y_step);
	printf("x_intercept = %f\n", c->x_intercept);
	printf("y_intercept = %f\n", c->y_intercept);	
	printf("x_next = %f\n", c->x_next);
	printf("y_next = %f\n", c->y_next);
	printf("********************\n");
}

void	print_hit(t_hit *h)
{
	printf("****print hit*****\n");
	printf("h_hit = %d\n", h->h_hit);
	printf("h_dist = %f\n", h->h_dist);
	printf("v_hit = %d\n", h->v_hit);
	printf("v_dist = %f\n", h->v_dist);
	printf("******************\n");
}
void	print_sprite(t_data *d, unsigned int count)
{
	unsigned int i;
	i = 0;
	while (i < count)
	{
		printf("****print sprite %d*****\n",i );
		printf("x_d = %f\n", d->sprite[i].x_d);
		printf("x_i = %d\n", d->sprite[i].x_i);	
		printf("y_d = %f\n", d->sprite[i].y_d);
		printf("y_i = %d\n", d->sprite[i].y_i);
		printf("dist = %f\n", d->sprite[i].dist);
		printf("************************\n");
		i++;
	}
}

void	print_rays(double *rays, int num_rays)
{
	int i;

	i = 0;

	while (i < num_rays)
	{
		printf("rays[%d] = %f\n", i, rays[i]);
		i++;
	}
}
	

/*
void	print_sprite(t_sprite *s)
{
	printf("****print sprite*****\n");
	printf("x_d = %f\n", s->x_d);
	printf("x_i = %d\n", s->x_i);	
	printf("y_d = %f\n", s->y_d);
	printf("y_i = %d\n", s->y_i);
	printf("dist = %f\n", s->dist);
	printf("******************\n");
}

void	print_elem_list(t_list *lst)
{
	if (!lst)
		printf("elem null\n");
	else
		print_sprite(lst->content);
}

void	print_list(t_list **lst)
{
	t_list *tmp;

	tmp = *lst;
	while (tmp)
	{
		print_elem_list(tmp);
		tmp = tmp->next;
	}
}
*/
	
