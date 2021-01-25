#include "../cub.h"
#include<mlx.h>

int key_press(int key, t_data *d)
{
	printf("press key : %d\n", key);
	if (key == 119 || key == 13) //W  119 13
		d->player->dir_walk_bf = 1;
	else if (key == 115 || key == 1) //s 115 0
		d->player->dir_walk_bf = -1;
	else if (key == 97 || key == 0) //a 97 1
		d->player->dir_walk_lr = 1;
	else if (key == 100 || key == 2) //d 100 2
		d->player->dir_walk_lr = -1;
	else if (key == 65361 || key == 123) // gauche 65361 
		d->player->dir_turn = 1;
	else if (key == 65363 || key == 124) // 65363 
		d->player->dir_turn = -1;
	else if (key == 65307 || key == 53) // 65307 53
		close_game(d);
	player_move(d);
	//cast_all_rays(mlx);
	return(0);
}

int key_release(int key, t_data *d)
{
	printf("release key : %d\n", key);
	if (key == 119 || key == 13) //W
		d->player->dir_walk_bf = 0;
	else if (key == 115 || key == 1) //s
		d->player->dir_walk_bf = 0;
	else if (key == 97 || key == 0) //a
		d->player->dir_walk_lr = 0;
	else if (key == 100 || key == 2) //d
		d->player->dir_walk_lr = 0;
	else if (key == 65361 || key == 123) // gauche
		d->player->dir_turn = 0;
	else if (key == 65363 || key == 124)
		d->player->dir_turn = 0;
	return (0);
}

