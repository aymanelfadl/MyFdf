#include "../fdf.h"


int     right_scale(t_vars *vars)
{
    int x_scale;
    int y_scale;

    x_scale = ((vars->map.map_width * 0.9) / vars->map.map_width);
    y_scale = ((vars->map.map_width * 0.9) / vars->map.map_height);

    if (x_scale < y_scale)
        return (x_scale);
    else
        return (y_scale);
}


void    apply_scale(t_vars *vars)
{
    int i;
    int j;
    int scale;

    scale = right_scale(vars);
    i = 0;
    while (i < vars->map.map_height)
    {
        j = 0;
        
        while (j < vars->map.map_width)
        {
            vars->map.map_points[i][j].x += scale;
            vars->map.map_points[i][j].y += scale;
            j++;
        }
        
    }
}
