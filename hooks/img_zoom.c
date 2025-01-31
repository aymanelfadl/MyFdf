#include "../fdf.h"

void    zoom_in(t_vars *vars)
{
    int i;
    int j;
    float hight_factor;

    hight_factor = calculate_height_factor(vars);
    i = 0;
    while (i < vars->map.map_height)
    {
        j = 0;
        while (j < vars->map.map_width)
        {
            vars->map.map_points[i][j].x *= 1.1;
            vars->map.map_points[i][j].y *= 1.1;
            vars->map.map_points[i][j].z *= (1.1 * hight_factor);
            j++;
        }
        i++;
    }
}

void    zoom_out(t_vars *vars)
{
    int i;
    int j;
    float hight_factor;

    hight_factor = calculate_height_factor(vars);
    i = 0;
    while (i < vars->map.map_height)
    {
        j = 0;
        while (j < vars->map.map_width)
        {
            vars->map.map_points[i][j].x *= 0.9;
            vars->map.map_points[i][j].y *= 0.9;
            vars->map.map_points[i][j].z *= (0.9 * hight_factor);
            j++;
        }
        i++;
    }
}