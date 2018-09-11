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
	mlx->width = 400;
	mlx->height = 300;
	mlx->color = intcolor(255,255,255);
	mlx->click_x = -1;
	if (!(mlx->mlx_ptr = mlx_init()) ||
		!(mlx->win_ptr = mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height, "fdf")) )
		return (deconstruct(mlx));
	return (mlx);
}

int keypress(int key, t_mlxp *p)
{
	ft_putstr("key:");
	ft_putnbr(key);
	ft_putchar('\n');

	if (key == 53)
	{
		deconstruct(p);
		exit(1);
	}
	return (1);
}

int mousepress(int button, int x, int y, t_mlxp *p)
{
	ft_putstr(button == 1 ? "lclick:" : "rclick");
	ft_putnbr(x);
	ft_putchar(',');
	ft_putnbr(y);
	if (p->click_x >= 0)
	{
		ft_putendl("(lined)");
		drawline((int[]){p->click_x, p->click_y, x, y}, p);
		p->click_x = -1;
	}
	else
	{
		ft_putendl("(saved)");
		p->click_x = x;
		p->click_y = y;
	}
	return (1);
}

void loadimage(char *img_ptr, t_mlxp *p)
{
	mlx_new_image(p->mlx_ptr, p->width, p->height);
	(void)img_ptr;
}

int main()
{
	t_mlxp *mlx = construct();
	mlx_key_hook(mlx->win_ptr, keypress, mlx);
	mlx_mouse_hook(mlx->win_ptr, mousepress, mlx);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, mlx->color, "(ESC) exit");
	mlx_loop(mlx->mlx_ptr);
}
