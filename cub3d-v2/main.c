/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:06:33 by jacher            #+#    #+#             */
/*   Updated: 2021/02/11 15:47:38 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		prepare_game_bis(t_data *d)
{
	d->player = malloc(sizeof(t_player));
	d->t = malloc(sizeof(t_text));
	d->ray = malloc(sizeof(t_ray));
	if (d->player == NULL || d->t == NULL || d->ray == NULL)
		return (print_error_parsing(10));
	f_init_player(d->player, d->map);
	return (1);
}

int		prepare_game(t_data *d, char **av, int mod)
{
	d->map = malloc(sizeof(t_map));
	if (d->map == NULL)
		return (print_error_parsing(10));
	f_init_mapdata(d->map);
	d->map_tab = map_parsing(av[1], d->map);
	if (d->map_tab == NULL)
		return (-1);
	check_res(d, mod);
	if (check_block_size(d->map) == -1)
		return (-1);
	count_sprite(d);
	if (d->map->sprite >= 1)
	{
		record_sprite(d, d->map->sprite);
		if (!d->sprite)
			return (-1);
	}
	if (prepare_game_bis(d) == -1)
		return (-1);
	return (1);
}

int		main(int ac, char **av)
{
	t_data		d;
	t_mlx		m;
	int			mod;

	d.sprite = NULL;
	d.player = NULL;
	d.ray = NULL;
	d.t = NULL;
	d.map = NULL;
	d.map_tab = NULL;
	mod = check_arg(ac, av);
	if (mod == -1)
		return (-1);
	d.mlx = &m;
	d.mlx->ptr = mlx_init();
	if (d.mlx->ptr == NULL)
		return (print_error_mlx(1));
	if (prepare_game(&d, av, mod) == 1)
		mlx_main(&d, mod);
	free_data(&d);
	return (1);
}
