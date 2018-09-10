#include "fdf.h"

int	nope(char *str, int rval)
{
	(void)str;
	return (rval);
}

void	*deconstruct(t_mlxp *mlx)
{
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlxp	*construct(void)
{
	t_mlxp	*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlxp))))
		return (NULL);
	if (!(mlx->mlx_ptr = mlx_init()) ||
		!(mlx->win_ptr = mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "mlx 42")) )
		return (deconstruct(mlx));
	return (mlx);
}

int keypress(int key, void *param)
{
	ft_putstr("key:");
	ft_putnbr(key);
	ft_putchar('\n');

	t_mlxp *p = (t_mlxp*)param;
	if (key == 53)
	{
		deconstruct(p);
		exit(1);
	}
	return (1);
}

int mousepress(int key, void *param)
{
	ft_putstr("mouse:");
	ft_putnbr(key);
	ft_putchar(',');
	ft_putnbr(key);
	ft_putendl(NULL);

	t_mlxp *p = (t_mlxp*)param;
	if (key == 126)
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, 20, 20, intcolor(255,255,0));
	if (key == 53)
		exit(1);
	return (1);
}

void loadimage(char *img_ptr, void *param)
{
	t_mlxp *p = (t_mlxp*)param;
	mlx_new_image(p->mlx_ptr, WIDTH, HEIGHT);
	(void)img_ptr;
}

int main()
{
	t_mlxp *mlx = construct();
	mlx_key_hook(mlx->win_ptr, keypress, mlx);
	mlx_loop(mlx->mlx_ptr);
}
