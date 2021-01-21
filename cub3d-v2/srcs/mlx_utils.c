#include "../cub.h"
#include<mlx.h>
int	key_hook(int key, t_data *d)
{
	(void)key;
	(void)d;
	printf("hello hook\n");
	return (1);
}
	
int deal_key(int key, void *param)
{
	printf("key : %d\n", key);
	//mlx_pixel_put(mlx, mlx_win....);
	(void)param;
	return(0);
}

int deal_button(int button, void *param)
{
	printf("button : %d\n", button);
	//mlx_pixel_put(mlx, mlx_win....);
	(void)param;
	return(0);
}

void	my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char *dst;

	dst = d->mlx->img->addr + (y * d->mlx->img->length + x *(d->mlx->img->bits /8));
	*(unsigned int*)dst = color;
}

int close_win(t_data *d)
{
	mlx_destroy_window(d->mlx->ptr, d->mlx->win);
	return (1);
}

int enter_win(int key, t_data *d)
{	
	printf("enter window\n");
	(void)d;
	(void)key;
	return (1);
}

int exit_win(int key, t_data *d)
{	
	printf("exit window\n");
	(void)d;
	(void)key;
	return (1);
}
