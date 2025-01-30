#include "../fdf.h"



int step_x(t_point *start_point, t_point *end_point)
{
    if (end_point->x > start_point->x)
        return (1);
    else
        return (-1);
}

int step_y(t_point *start_point, t_point *end_point)
{
    if (end_point->y > start_point->y)
        return (1);
    else
        return (-1);
}

int     right_scale(t_vars *vars)
{
    int x_scale;
    int y_scale;

    x_scale = ((vars->mlx_info.mlx_window_height * 0.6) / vars->map.map_height);
    y_scale = ((vars->mlx_info.mlx_window_width* 0.6) / vars->map.map_width);

    if (x_scale < y_scale)
        return (x_scale);
    else
        return (y_scale);
}

void    apply_scale(t_vars *vars)
{
    int i;
    int j;

    vars->map.map_scale = right_scale(vars);
    i = 0;
    while (i < vars->map.map_height)
    {
        j = 0;
        while (j < vars->map.map_width)
        {
            vars->map.map_points[i][j].x *= vars->map.map_scale;
            vars->map.map_points[i][j].y *= vars->map.map_scale;
            j++;
        }
        i++;
    }
}
