//#include "libft.h"
#include "cub.h"
#include<mlx.h>

void check_res(t_data *d)
{
	int		width;
	int		height;

	mlx_get_screen_size(d->mlx->ptr, &width, &height);
	printf("w = %d, h = %d\n", width, height);
	printf("w = %u, h = %u\n", d->map->r_x,d->map->r_y);
	if (d->map->r_x > (unsigned int)width)
		d->map->r_x = (unsigned int)width;
	if (d->map->r_y > (unsigned int)height)
		d->map->r_y = (unsigned int)height;
	return ; 
}

int main(int ac, char **av)
{
	char		**map_tab;
	t_map		map;
	int			err_num;
	t_player	player;
	t_data		d;
	t_ray 		ray;
	t_text		t;
	t_mlx 		m; 

//	t_sprite	*s;
	
	(void)ac;
//	s = NULL;
	d.mlx = &m;
	d.mlx->ptr = mlx_init();
	if(d.mlx->ptr == NULL)
	{
		print_error_mlx(1, &d);
		return(-1);
	}
	err_num = 0;
	//printf("is ok\n");
	f_init_mapdata(&map);
	//printf("is ok2\n");
	map_tab = map_parsing(av[1], &map);
	//printf("is ok3\n");
	print_mapdata(&map);
	//printf("is ok3\n");
	if (map_tab == NULL)
	{
		print_error_parsing(err_num);
		//printf("\n****Error****\n");
		return (0);
	}
	else
	{
		print_maptab(map_tab);
		printf("\n SUCCESS MOTHER FUCKER!!!!!\n");
	}
	d.map_tab = map_tab;
	d.map = &map;
	check_res(&d);
	define_tile_size(&map);
	
//	printf("is ok\n");
	count_sprite(&d);
//	printf("is ok2\n");
//	printf("sprite = %d\n", d.map->sprite);
	if (d.map->sprite >= 1)
	{
		record_sprite(&d, map.sprite);
//		printf("is ok3\n");
		if (!d.sprite)
			return (-1);
	}
//	printf("count sprite = %d\n", map.sprite);
//	print_sprite(&d, map.sprite);
	f_init_player(&player, &map);
	d.player = &player;
	d.ray = &ray;
	d.t = &t;
	mlx_main(&d);
	printf("out of mlx\n");
	f_free_mapdata(&map);
	//ft_free_sprite(&d);
	free(d.sprite);
	ft_free_map(map_tab, 2147483647);	
	return (-1);
}
