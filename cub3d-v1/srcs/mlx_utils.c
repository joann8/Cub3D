#include "../cub.h"
#include<mlx.h>
int	key_hook(int key, t_mlx *mlx)
{
	(void)key;
	(void)mlx;
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

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char *dst;

	dst = mlx->img_addr + (y * mlx->img_line_length + x *(mlx->img_bits /8));
	*(unsigned int*)dst = color;
}

int close_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	return (1);
}

int enter_win(int key, t_mlx *mlx)
{	
	printf("enter window\n");
	(void)mlx;
	(void)key;
	return (1);
}

int exit_win(int key, t_mlx *mlx)
{	
	printf("exit window\n");
	(void)mlx;
	(void)key;
	return (1);
}
