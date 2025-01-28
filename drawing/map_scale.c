#include "../fdf.h"


int     right_scale(t_vars *vars)
{
    int x_scale;
    int y_scale;

    x_scale = ((vars->mlx_info.mlx_window_height * 0.9) / vars->map.map_height);
    y_scale = ((vars->mlx_info.mlx_window_width* 0.9) / vars->map.map_width);

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
        ft_printf("scale::%d\n",vars->map.map_scale);
        while (j < vars->map.map_width)
        {
            vars->map.map_points[i][j].x *= vars->map.map_scale;
            vars->map.map_points[i][j].y *= vars->map.map_scale;
            j++;
        }
        i++;
    }
     for (int i = 0; i < vars->map.map_height ; i++)
        {
            for (int j = 0; j < vars->map.map_width; j++)
            {
                ft_printf("---------------\n<x:%d :: y:%d :: z:%d :: color:%d> ", 
                    vars->map.map_points[i][j].x,
                    vars->map.map_points[i][j].y,
                    vars->map.map_points[i][j].z,
                    vars->map.map_points[i][j].color);
            }
            ft_printf("\n");
        }
}
