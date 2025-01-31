#include "../fdf.h"

void set_boundaries(t_vars *vars)
{
    int i;
    int j;
    t_map_range range;

    i = -1;   
    range.min_x = vars->map.map_points[0][0].x;
    range.max_x = vars->map.map_points[0][0].x;
    range.min_y = vars->map.map_points[0][0].y;
    range.max_y = vars->map.map_points[0][0].y;
    while (++i < vars->map.map_height)
    {
        j = -1;
        while (++j < vars->map.map_width)
        {
            if (vars->map.map_points[i][j].x < range.min_x)
                range.min_x = vars->map.map_points[i][j].x;
            if (vars->map.map_points[i][j].x > range.max_x)
                range.max_x = vars->map.map_points[i][j].x;
            if (vars->map.map_points[i][j].y < range.min_y)
                range.min_y = vars->map.map_points[i][j].y;
            if (vars->map.map_points[i][j].y > range.max_y)
                range.max_y = vars->map.map_points[i][j].y;
        }
    }
    vars->map.map_range = range;
}

void move_to_center(t_vars *vars)
{
    int center_x;
    int center_y;
    int i;
    int j;
    
    set_boundaries(vars);
    center_x = (vars->mlx_info.mlx_window_width - (vars->map.map_range.max_x - vars->map.map_range.min_x)) / 2;
    center_y = (vars->mlx_info.mlx_window_height - (vars->map.map_range.max_y - vars->map.map_range.min_y)) / 2;
    i = 0;
    while (i < vars->map.map_height)
    {
        j = 0;
        while (j < vars->map.map_width)
        {
            vars->map.map_points[i][j].x += center_x - vars->map.map_range.min_x + vars->map.map_offset_x;
            vars->map.map_points[i][j].y += center_y - vars->map.map_range.min_y + vars->map.map_offset_y;
            j++;
        }
        i++;
    }
}
