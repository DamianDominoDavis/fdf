#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "mlx.h"
#include "color.h"

int		WIDTH = 500;
int		HEIGHT = 500;

//required for minilibx
void	*mlx_init();

//main
typedef struct	s_mlxp
{
		void	*mlx_ptr;
		void	*win_ptr;
}		t_mlxp;

int		nope(char *str, int rval);
void	*deconstruct(t_mlxp *mlx);
t_mlxp	*construct(void);
int		keypress(int key, void *param);
int		mousepress(int key, void *param);

//elsewhere
void	drawline(int x0, int y0, int x1, int y1);

#endif /* FDF_H */
