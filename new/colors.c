#include "headers/fdf.h"

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}


int	create_trgb(int trgb)
{
    int t;
    int r;
    int g;
    int b;

    t = get_t(trgb);
    r = get_r(trgb);
    g = get_g(trgb);
    b = get_b(trgb);
	return (*(int *)(unsigned char [4]){b, g, r, t});
}
