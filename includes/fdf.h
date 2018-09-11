#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "mlx.h"
#include "color.h"

//required for minilibx
void	*mlx_init();

//main
typedef struct	s_mlxp
{
		void	*mlx_ptr;
		void	*win_ptr;
		int		width;
		int		height;
		int		click_x;
		int		click_y;
		int		color;
}		t_mlxp;

int		nope(char *str, int rval);
void	*deconstruct(t_mlxp *mlx);
t_mlxp	*construct(void);
int		keypress(int key, t_mlxp *p);
int		mousepress(int button, int x, int y, t_mlxp *p);

//elsewhere
void	drawline(int c[], t_mlxp *p);

#endif /* FDF_H */
