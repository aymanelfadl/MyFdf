
#include "../fdf.h"

/*
    When you write a pixel:
        *(unsigned int *)dst = color;

        // It's like:
        Memory before: [00][00][00][00]
                        ↓  ↓  ↓  ↓
        Color (red):   [00][FF][00][00]
                        A  R  G  B 
        access the adress with x and yand change in it : so now change the adress
*/

void ft_put_pixel(t_vars *vars, int x, int y, int color)
{
    char *pixel;
    pixel = vars->img.addr + (x * (vars->img.bits_per_pixel / 8) + (y * vars->img.line_length));

    *(unsigned int *) pixel = color; 
}

void ft_lower_slope(t_vars *vars ,int dx, int dy, t_point *start_point)
{
    int i;
    int p;
	t_point tmp_point;

	tmp_point = *start_point;
    i = 0;
    p = 2 * dy - dx;
    ft_put_pixel(vars, tmp_point.x , tmp_point.y, tmp_point.color);
    while (i < dx)
    {
        tmp_point.x += 1;
        if (p < 0)
            p = p + 2 * dy;
        else
        {
            tmp_point.y += 1;
            p = p + 2 * dy - 2 * dx;
        }
        ft_put_pixel(vars, tmp_point.x, tmp_point.y, tmp_point.color);
        i++;
    }
}

void ft_higher_slope(t_vars *vars ,int dx, int dy, t_point *start_point)
{
    int i;
    int p;
	t_point tmp_point;

	tmp_point = *start_point;
    i = 0;
    p = 2 * dx - dy;
    ft_put_pixel(vars, tmp_point.x , tmp_point.y, tmp_point.color);
    while (i < dy)
    {
        tmp_point.y += 1;
        if (p < 0)
            p = p + 2 * dx;
        else
        {
            tmp_point.x += 1;
            p = p + 2 * dx - 2 * dy;
        }
        ft_put_pixel(vars, tmp_point.x, tmp_point.y, tmp_point.color);
        i++;
    }
}
/*
    calculate slope to draw a line between two points
*/
void ft_draw_line(t_vars *vars , t_point *p1, t_point *p2)
{
    int dx;
    int dy;

    dx = abs(p2->x - p1->x);
    dy = abs(p2->y - p2->y);

    if (dx > dy)
        ft_lower_slope(vars, dx, dy, p1);
    else
        ft_higher_slope(vars, dx, dy, p1);
}

void draw_img(t_vars *vars)
{
    int	i;
	int	j;

	i = 0;
	while (i < vars->map.map_height)
	{
		j = 0;
		while (j < vars->map.map_width - 1)
		{
			ft_draw_line(vars, &vars->map.map_points[i][j], &vars->map.map_points[i][j+1]);
			j++;
		}
		
		i++;
	}
}