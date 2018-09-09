#include "color.h"

int	intcolor(int r, int g, int b)
{	
	if (r > 255 || g > 255 | b > 255 || r < 0 || g < 0 || b < 0)
		return (-1);
	return ((int)(256*256*r + 256*g + b));
}
