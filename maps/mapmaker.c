#include <stdlib.h>
#include <stdio.h>

int	main(int c, char **argv)
{
	int x, y, xmax, ymax;
	FILE *fd;
	if (c == 4)
	{
		ymax = atoi(argv[3]);
		xmax = atoi(argv[2]);
		fd = fopen(argv[1], "w");
		for (y = 0; y < ymax; y++)
		{
			for (x = 0; x < xmax; x++)
				fprintf(fd, "%d ", rand() % 10);
			fprintf(fd, "\n");
		}
	}
	else
		printf("usage: mapmaker filename w h\n");
}
