
#include "../fdf.h"



void ft_put_pixel(t_vars *vars, int x, int y, int color) {
    char *pixel;
    
    if (x >= 0 && y >= 0 && x <= vars->mlx_info.mlx_window_width  &&  y <= vars->mlx_info.mlx_window_height)
    {   
         pixel = vars->img.addr + (y * vars->img.line_length + x * (vars->img.bits_per_pixel / 8));
        *(unsigned int *)pixel = color;
    }
}

void ft_lower_slope(t_vars *vars ,int dx, int dy, t_point *start_point, t_point *end_point)
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
        tmp_point.x += step_x(start_point, end_point);
        if (p < 0)
            p = p + 2 * dy;
        else
        {
            tmp_point.y += step_y(start_point, end_point);
            p = p + 2 * dy - 2 * dx;
        }
        ft_put_pixel(vars, tmp_point.x, tmp_point.y, tmp_point.color);
        i++;
    }
}

void ft_higher_slope(t_vars *vars ,int dx, int dy, t_point *start_point, t_point *end_point)
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
        tmp_point.y += step_y(start_point, end_point);
        if (p < 0)
            p = p + 2 * dx;
        else
        {
            tmp_point.x += step_x(start_point, end_point);
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

    dx = abs((int)p2->x - (int)p1->x);
    dy = abs((int)p2->y - (int)p1->y);

    if (dx > dy)
        ft_lower_slope(vars, dx, dy, p1, p2);
    else
        ft_higher_slope(vars, dx, dy, p1, p2);
}

void draw_img(t_vars *vars)
{
    int i;
    int j;

    i = 0;
    while (i < vars->map.map_height)
    {
        j = 0;
        while (j < vars->map.map_width)
        {
            if (vars->map.map_points[i][j].valid_point)
            {
                if (j + 1 < vars->map.map_width && vars->map.map_points[i][j + 1].valid_point)
                    ft_draw_line(vars, &vars->map.map_points[i][j], &vars->map.map_points[i][j + 1]);
                if (i + 1 < vars->map.map_height && vars->map.map_points[i + 1][j].valid_point)
                    ft_draw_line(vars, &vars->map.map_points[i][j], &vars->map.map_points[i + 1][j]);
            }
            j++;
        }
        i++;
    }
}
